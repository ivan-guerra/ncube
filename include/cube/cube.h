#ifndef CUBE_H_
#define CUBE_H_

#include "common/types.h"

namespace ncube {

class Cube {
 public:
  [[nodiscard]] Cube();
  ~Cube() = default;
  Cube(const Cube&) = default;
  Cube(Cube&&) = default;
  Cube& operator=(const Cube&) = default;
  Cube& operator=(Cube&&) = default;

  [[nodiscard]] const Faces3D& GetFaces() const noexcept { return faces_; }
  [[nodiscard]] const Faces3D& GetFaces() noexcept { return faces_; }
  void AddPointsToEdges(unsigned int num_points_per_edge);

 private:
  [[nodiscard]] Point3D Midpoint(const Point3D& a, const Point3D b) noexcept;
  [[nodiscard]] Face3D GenPoints(const Point3D a, const Point3D& b,
                                 unsigned int num_points);
  [[nodiscard]] Face3D ExpandFace(const Face3D& face, unsigned int num_points);

  Faces3D faces_;
};

}  // namespace ncube

#endif
