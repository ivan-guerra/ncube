#include "cube/cube.h"

#include <queue>

#include "common/types.h"

namespace ncube {

Point3D Cube::Midpoint(const Point3D& a, const Point3D b) noexcept {
  Point3D midpoint;
  midpoint.x = (a.x + b.x) / 2.0;
  midpoint.y = (a.y + b.y) / 2.0;
  midpoint.z = (a.z + b.z) / 2.0;

  return midpoint;
}

Face3D Cube::GenPoints(const Point3D a, const Point3D& b,
                       unsigned int num_points) {
  if (num_points <= 0) {
    return {};
  }

  using PointPair = std::pair<Point3D, Point3D>;
  std::queue<PointPair> buffer;
  buffer.emplace(a, b);

  Face3D points;
  while (points.size() != num_points) {
    PointPair pp = buffer.front();
    buffer.pop();

    Point3D midpoint = Midpoint(pp.first, pp.second);
    points.push_back(midpoint);

    buffer.push({pp.first, midpoint});
    buffer.push({midpoint, pp.second});
  }
  return points;
}

Face3D Cube::ExpandFace(const Face3D& face, unsigned int num_points) {
  Face3D expanded_face = GenPoints(face.front(), face.back(), num_points);
  for (unsigned int i = 1; i < face.size(); ++i) {
    Face3D points = GenPoints(face[i - 1], face[i], num_points);
    expanded_face.insert(expanded_face.end(), points.begin(), points.end());
  }
  return expanded_face;
}

void Cube::AddPointsToEdges(unsigned int num_points_per_edge) {
  Faces3D new_faces;
  for (const Face3D& face : faces_) {
    new_faces.push_back(ExpandFace(face, num_points_per_edge));
  }
  faces_ = new_faces;
}

Cube::Cube() {
  faces_ = {
      {
          /* bottom */
          {.x = -0.5, .y = 0.5, .z = -0.5},
          {.x = 0.5, .y = 0.5, .z = -0.5},
          {.x = 0.5, .y = 0.5, .z = 0.5},
          {.x = -0.5, .y = 0.5, .z = 0.5},
      },
      {
          /* top */
          {.x = -0.5, .y = -0.5, .z = -0.5},
          {.x = 0.5, .y = -0.5, .z = -0.5},
          {.x = 0.5, .y = -0.5, .z = 0.5},
          {.x = -0.5, .y = -0.5, .z = 0.5},
      },
      {
          /* front */
          {.x = -0.5, .y = -0.5, .z = 0.5},
          {.x = 0.5, .y = -0.5, .z = 0.5},
          {.x = 0.5, .y = 0.5, .z = 0.5},
          {.x = -0.5, .y = 0.5, .z = 0.5},
      },
      {
          /* back */
          {.x = -0.5, .y = -0.5, .z = -0.5},
          {.x = 0.5, .y = -0.5, .z = -0.5},
          {.x = 0.5, .y = 0.5, .z = -0.5},
          {.x = -0.5, .y = 0.5, .z = -0.5},
      },
  };
}

}  // namespace ncube
