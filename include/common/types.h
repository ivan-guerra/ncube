#ifndef TYPES_H_
#define TYPES_H_

#include <vector>

namespace ncube {

/**
 * \brief 2D Coordinate
 */
struct Point2D {
  double x = 0.0; /**< 2D x coordinate **/
  double y = 0.0; /**< 2D y coordinate **/
};

/**
 * \brief 3D Coordinate
 */
struct Point3D {
  double x = 0.0; /**< 3D x coordinate */
  double y = 0.0; /**< 3D y coordinate */
  double z = 0.0; /**< 3D z coordinate */
};

/**
 * \brief Camera Attitude
 */
struct Attitude {
  double roll = 0.0;  /**< Camera roll */
  double pitch = 0.0; /**< Camera pitch */
  double yaw = 0.0;   /**< Camera yaw */
};

/**
 * \brief View Settings
 */
struct ViewConfig {
  double fov_angle_deg = 45.0;    /**< Camera FOV in degrees */
  double camera_distance = 10.0;  /**< Distance from center of the cube */
  double near_plane_width = 0.0;  /**< NP width (i.e., screen width) */
  double near_plane_height = 0.0; /**< NP height (i.e., screen height) */
};

using Face2D = std::vector<Point2D>;
using Face3D = std::vector<Point3D>;
using Faces2D = std::vector<Face2D>;
using Faces3D = std::vector<Face3D>;

}  // namespace ncube

#endif
