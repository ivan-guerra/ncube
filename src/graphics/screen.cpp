#include "graphics/screen.h"

#include <curses.h>
#include <ncurses.h>

namespace ncube {
namespace graphics {

[[nodiscard]] static int WrapAround(int v, int delta, int minval, int maxval) {
  const int kMod = maxval + 1 - minval;
  if (delta >= 0) {
    return (v + delta - minval) % kMod + minval;
  } else {
    return ((v + delta) - delta * kMod - minval) % kMod + minval;
  }
}

ScreenDimension InitScreen() noexcept {
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

void TerminateScreen() noexcept { endwin(); }

void Clear() noexcept { clear(); }

void EnableInputDelay(int delay_ms) noexcept { timeout(delay_ms); }

void DisableInputDelay() noexcept { timeout(-1); }

bool UpdateCursor(const ScreenDimension& screen_dim, Point2D& cursor) noexcept {
  int key = getch();
  switch (key) {
    case KEY_UP:
      cursor.y = WrapAround(cursor.y, 1, 0, 2 * screen_dim.height);
      break;
    case KEY_DOWN:
      cursor.y = WrapAround(cursor.y, -1, 0, 2 * screen_dim.height);
      break;
    case KEY_LEFT:
      cursor.x = WrapAround(cursor.x, -1, 0, 2 * screen_dim.width);
      break;
    case KEY_RIGHT:
      cursor.x = WrapAround(cursor.x, 1, 0, 2 * screen_dim.width);
      break;
    case 'q':
      return false;
      break;
  }
  return true;
}

void DrawObject(const Faces2D& faces) noexcept {
  for (const Face2D& face : faces) {
    for (const Point2D& point : face) {
      mvaddch(point.y, point.x, '+');
    }
  }
  refresh();
}

void DrawInstructions(const ScreenDimension& screen_dim) noexcept {
  mvprintw(screen_dim.height - 1, 0, "%s",
           "use the arrow keys to rotate the cube, press q to quit");
  refresh();
}

}  // namespace graphics
}  // namespace ncube
