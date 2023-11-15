#ifndef UTIL_H_
#define UTIL_H_

#include "common/types.h"

namespace nshapes {

[[nodiscard]] Faces2D Get2DProjection(const Faces3D &faces,
                                      const ViewConfig &conf, double cursor_x,
                                      double cursor_y);

}  // namespace nshapes

#endif
