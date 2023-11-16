#include <cstdlib>

#include "common/types.h"
#include "common/util.h"
#include "cube/cube.h"
#include "graphics/screen.h"

void RunDrawLoop(const ncube::graphics::ScreenDimension& screen_dim) {
  ncube::Point2D cursor = {.x = screen_dim.width / 2.0,
                           .y = screen_dim.height / 2.0};
  ncube::ViewConfig view;
  view.near_plane_width = screen_dim.width;
  view.near_plane_height = screen_dim.height;

  ncube::Cube cube;
  while (ncube::graphics::UpdateCursor(screen_dim, cursor)) {
    ncube::Faces2D faces =
        ncube::Get2DProjection(cube, view, cursor.x, cursor.y);
    ncube::graphics::DrawObject(faces);
    ncube::graphics::DrawInstructions(screen_dim);
  }
}

int main() {
  /* ncurses screen initialization */
  ncube::graphics::ScreenDimension screen_dim = ncube::graphics::InitScreen();

  /* set a reasonable input delay keeping in mind that higher delays make the
   * application seem laggy and that lower delays will waste CPU cycles
   * re-drawing the view */
  const int kInputDelayMs = 100;
  ncube::graphics::EnableInputDelay(kInputDelayMs);

  /* draw the shape and allow the user to rotate it using the arrow keys */
  RunDrawLoop(screen_dim);

  /* cleanup ncurses resources */
  ncube::graphics::DisableInputDelay();
  ncube::graphics::TerminateScreen();

  std::exit(EXIT_SUCCESS);
}
