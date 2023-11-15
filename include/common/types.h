#ifndef TYPES_H_
#define TYPES_H_

#include <vector>

namespace nshapes {

struct Point2D {
  double x = 0.0;
  double y = 0.0;
};

struct Point3D {
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
};

struct Attitude {
  double roll = 0.0;
  double pitch = 0.0;
  double yaw = 0.0;
};

struct ViewConfig {
  double fov_angle_deg = 45.0;
  double camera_distance = 10.0;
  double near_plane_width = 0.0;
  double near_plane_height = 0.0;
};

using Face2D = std::vector<Point2D>;
using Face3D = std::vector<Point3D>;
using Faces2D = std::vector<Face2D>;
using Faces3D = std::vector<Face3D>;

}  // namespace nshapes

#endif
