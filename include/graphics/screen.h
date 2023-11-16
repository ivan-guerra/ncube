#ifndef SCREEN_H_
#define SCREEN_H_

#include "common/types.h"

namespace ncube {
namespace graphics {

struct ScreenDimension {
  int width = 0;
  int height = 0;
};

[[nodiscard]] ScreenDimension InitScreen();

void TerminateScreen();

void EnableInputDelay(int delay_ms);

void DisableInputDelay();

[[nodiscard]] bool UpdateCursor(const ScreenDimension& screen_dim,
                                Point2D& cursor);

void DrawObject(const Faces2D& faces);

void DrawInstructions(const ScreenDimension& screen_dim);

}  // namespace graphics
}  // namespace ncube

#endif
