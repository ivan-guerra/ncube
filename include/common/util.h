#ifndef UTIL_H_
#define UTIL_H_

#include "common/types.h"
#include "cube/cube.h"

namespace ncube {

[[nodiscard]] Faces2D Get2DProjection(const Cube& cube, const ViewConfig& conf,
                                      double cursor_x, double cursor_y);

}  // namespace ncube

#endif
