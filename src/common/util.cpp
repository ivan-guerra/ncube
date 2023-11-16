#include "common/util.h"

#include <cmath>

#include "common/types.h"

namespace ncube {

static constexpr double kPi = 3.1415926535;

[[nodiscard]] static double Transform2DTo3D(double xy, double z,
                                            double fov_angle_deg) {
  const double kAngleRad = (fov_angle_deg / 180.0) * kPi;
  return (xy / (z * std::tan(kAngleRad / 2.0)));
}

[[nodiscard]] static Point3D Rotate3D(const Point3D &point,
                                      const Attitude &attitude) {
  return {
      .x = std::cos(attitude.yaw) * std::cos(attitude.pitch) * point.x +
           (std::cos(attitude.yaw) * std::sin(attitude.pitch) *
                std::sin(attitude.roll) -
            std::sin(attitude.yaw) * std::cos(attitude.roll)) *
               point.y +
           (std::cos(attitude.yaw) * std::sin(attitude.pitch) *
                std::cos(attitude.roll) +
            std::sin(attitude.yaw) * std::sin(attitude.roll)) *
               point.z,
      .y = std::sin(attitude.yaw) * std::cos(attitude.pitch) * point.x +
           (std::sin(attitude.yaw) * std::sin(attitude.pitch) *
                std::sin(attitude.roll) +
            std::cos(attitude.yaw) * std::cos(attitude.roll)) *
               point.y +
           (std::sin(attitude.yaw) * std::sin(attitude.pitch) *
                std::cos(attitude.roll) -
            std::cos(attitude.yaw) * std::sin(attitude.roll)) *
               point.z,
      .z = -std::sin(attitude.pitch) * point.x +
           std::cos(attitude.pitch) * std::sin(attitude.roll) * point.y +
           std::cos(attitude.pitch) * std::cos(attitude.roll) * point.z,
  };
}

Faces2D Get2DProjection(const Cube &cube, const ViewConfig &conf,
                        double cursor_x, double cursor_y) {
  const double kCursorXRatio = (cursor_x / conf.near_plane_width) * kPi;
  const double kCursorYRatio = (cursor_y / conf.near_plane_height) * kPi;

  ncube::Faces2D cube_faces_2d;
  for (const Face3D &face_3d : cube.GetFaces()) {
    ncube::Face2D face_2d;
    for (const Point3D &point : face_3d) {
      /* create the rotated 3D point */
      Point3D rotated_point = Rotate3D(
          point, {.roll = kCursorYRatio, .pitch = kCursorXRatio, .yaw = 0});

      /* distance the camera from the cube */
      rotated_point.z += conf.camera_distance;

      /* perform a perspective projection */
      Point2D projection_2d = {
          .x = Transform2DTo3D(rotated_point.x, rotated_point.z,
                               conf.fov_angle_deg),
          .y = Transform2DTo3D(rotated_point.y, rotated_point.z,
                               conf.fov_angle_deg)};

      /* shift the coordinate to account for the fact the origin is the top left
       * of our screen */
      projection_2d.x =
          projection_2d.x * conf.near_plane_width + conf.near_plane_width / 2.0;
      projection_2d.y = projection_2d.y * conf.near_plane_height +
                        conf.near_plane_height / 2.0;
      face_2d.push_back(projection_2d);
    }
    cube_faces_2d.push_back(face_2d);
  }
  return cube_faces_2d;
}

}  // namespace ncube
