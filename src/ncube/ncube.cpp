#include <getopt.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "common/types.h"
#include "common/util.h"
#include "cube/cube.h"
#include "graphics/screen.h"

void PrintUsage() noexcept {
  std::cout << "usage: ncube [OPTION]..." << std::endl;
  std::cout << "ncurses rendering of a cube" << std::endl;
  std::cout << "\t-f, --fov-angle-deg\tFOV angle in degrees" << std::endl;
  std::cout << "\t-c, --camera-dist\tdistance of the camera from the center of "
               "the cube"
            << std::endl;
  std::cout << "\t-n, --num-edge-points\tnumber of points per edge"
            << std::endl;
  std::cout << "\t-h, --help\t\tprint this help page" << std::endl;
}

void RunDrawLoop(const ncube::Cube& cube, const ncube::ViewConfig& view,
                 const ncube::graphics::ScreenDimension& dim) {
  ncube::Point2D cursor = {.x = view.near_plane_width / 2.0,
                           .y = view.near_plane_height / 2.0};
  while (ncube::graphics::UpdateCursor(dim, cursor)) {
    ncube::Faces2D faces =
        ncube::RotateAndProject3Dto2D(cube, view, cursor.x, cursor.y);

    ncube::graphics::Clear();
    ncube::graphics::DrawObject(faces);
    ncube::graphics::DrawInstructions(dim);
  }
}

int main(int argc, char** argv) {
  struct option long_options[] = {
      {"fov-angle-deg", required_argument, 0, 'f'},
      {"camera-dist", required_argument, 0, 'c'},
      {"num-edge-points", required_argument, 0, 'n'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0},
  };

  int opt = 0;
  int long_index = 0;
  ncube::ViewConfig view;
  unsigned int num_edge_points = 5;
  while (-1 != (opt = ::getopt_long(argc, argv, "hf:c:n:",
                                    static_cast<struct option*>(long_options),
                                    &long_index))) {
    switch (opt) {
      case 'f':
        view.fov_angle_deg = std::stod(optarg);
        break;
      case 'c':
        view.camera_distance = std::stod(optarg);
        break;
      case 'n':
        num_edge_points = std::stoul(optarg);
        break;
      case 'h':
        PrintUsage();
        std::exit(EXIT_SUCCESS);
      case '?':
        std::cerr << "error: unknown option -> " << opt << std::endl;
        std::exit(EXIT_FAILURE);
    }
  }

  ncube::Cube cube;
  cube.AddPointsToEdges(num_edge_points);

  /* ncurses screen initialization */
  ncube::graphics::ScreenDimension dim = ncube::graphics::InitScreen();

  /* our terminal window is our near plane */
  view.near_plane_width = dim.width;
  view.near_plane_height = dim.height;

  /* set a reasonable input delay keeping in mind that higher delays make the
   * application seem laggy and that lower delays will waste CPU cycles
   * re-drawing the view */
  const int kInputDelayMs = 100;
  ncube::graphics::EnableInputDelay(kInputDelayMs);

  /* draw the cube and allow the user to rotate it using the arrow keys */
  RunDrawLoop(cube, view, dim);

  /* cleanup ncurses resources */
  ncube::graphics::DisableInputDelay();
  ncube::graphics::TerminateScreen();

  std::exit(EXIT_SUCCESS);
}
