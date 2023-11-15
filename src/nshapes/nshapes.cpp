#include <cstdlib>

#include "common/types.h"
#include "common/util.h"
#include "graphics/screen.h"
#include "shapes/cube.h"

void RunDrawLoop(const nshapes::graphics::ScreenDimension& screen_dim) {
  nshapes::Point2D cursor = {.x = screen_dim.width / 2.0,
                             .y = screen_dim.height / 2.0};
  nshapes::ViewConfig view;
  view.near_plane_width = screen_dim.width;
  view.near_plane_height = screen_dim.height;

  while (nshapes::graphics::UpdateCursor(screen_dim, cursor)) {
    nshapes::Faces2D faces = nshapes::Get2DProjection(nshapes::shapes::kCube,
                                                      view, cursor.x, cursor.y);
    nshapes::graphics::DrawObject(faces);
    nshapes::graphics::DrawInstructions(screen_dim);
  }
}

int main() {
  /* ncurses screen initialization */
  nshapes::graphics::ScreenDimension screen_dim =
      nshapes::graphics::InitScreen();

  /* set a reasonable input delay keeping in mind that higher delays make the
   * application seem laggy and that lower delays will waste CPU cycles
   * re-drawing the view */
  const int kInputDelayMs = 100;
  nshapes::graphics::EnableInputDelay(kInputDelayMs);

  /* draw the shape and allow the user to rotate it using the arrow keys */
  RunDrawLoop(screen_dim);

  /* cleanup ncurses resources */
  nshapes::graphics::DisableInputDelay();
  nshapes::graphics::TerminateScreen();

  std::exit(EXIT_SUCCESS);
}
