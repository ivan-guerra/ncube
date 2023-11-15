#include "graphics/screen.h"

#include <curses.h>
#include <ncurses.h>

namespace nshapes {
namespace graphics {

[[nodiscard]] static int WrapAround(int v, int delta, int minval, int maxval) {
  const int kMod = maxval + 1 - minval;
  if (delta >= 0) {
    return (v + delta - minval) % kMod + minval;
  } else {
    return ((v + delta) - delta * kMod - minval) % kMod + minval;
  }
}

ScreenDimension InitScreen() {
  initscr();
  cbreak();             /* disable line buffering */
  keypad(stdscr, TRUE); /* enable the keypad so we can work with arrow keys */
  noecho();             /* disable character echoing */
  curs_set(0);          /* hide the cursor */

  /* fetch the screen dimensions */
  ScreenDimension screen_dim = {.width = 0, .height = 0};
  getmaxyx(stdscr, screen_dim.height, screen_dim.width);

  return screen_dim;
}

void TerminateScreen() { endwin(); }

void EnableInputDelay(int delay_ms) { timeout(delay_ms); }

void DisableInputDelay() { timeout(-1); }

bool UpdateCursor(const ScreenDimension& screen_dim, Point2D& cursor) {
  int key = getch();
  switch (key) {
    case KEY_UP:
      cursor.y = WrapAround(cursor.y, 1, 0, screen_dim.height);
      break;
    case KEY_DOWN:
      cursor.y = WrapAround(cursor.y, -1, 0, screen_dim.height);
      break;
    case KEY_LEFT:
      cursor.x = WrapAround(cursor.x, -1, 0, screen_dim.width);
      break;
    case KEY_RIGHT:
      cursor.x = WrapAround(cursor.x, 1, 0, screen_dim.width);
      break;
    case 'q':
      return false;
      break;
  }
  return true;
}

void DrawObject(const Faces2D& faces) {
  clear();
  for (const Face2D& face : faces) {
    for (const Point2D& point : face) {
      mvaddch(point.y, point.x, '+');
    }
  }
  refresh();
}

void DrawInstructions(const ScreenDimension& screen_dim) {
  mvprintw(screen_dim.height - 1, 0, "%s",
           "use the arrow keys to rotate the shape, press q to quit");
  refresh();
}

}  // namespace graphics
}  // namespace nshapes
