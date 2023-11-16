#ifndef CUBE_H_
#define CUBE_H_

#include "common/types.h"

namespace ncube {

/**
 * \brief The Cube class represents a cube in 3D space.
 */
class Cube {
 public:
  /**
   * \brief Construct a cube with a set of default faces.
   * \details The default cube is a unit cube scaled down by a factor of two.
   */
  [[nodiscard]] Cube();

  ~Cube() = default;
  Cube(const Cube&) = default;
  Cube(Cube&&) = default;
  Cube& operator=(const Cube&) = default;
  Cube& operator=(Cube&&) = default;

  [[nodiscard]] const Faces3D& GetFaces() const noexcept { return faces_; }
  [[nodiscard]] Faces3D& GetFaces() noexcept { return faces_; }

  /**
   * \brief Add \p num_points_per_edge points on each cube edge.
   * \param [in] num_points_per_edge Number of desired points per edge excluding
   *             edge endpoints.
   */
  void AddPointsToEdges(unsigned int num_points_per_edge);

 private:
  [[nodiscard]] Point3D Midpoint(const Point3D& a,
                                 const Point3D b) const noexcept;
  [[nodiscard]] Face3D GenPoints(const Point3D a, const Point3D& b,
                                 unsigned int num_points) const;
  [[nodiscard]] Face3D ExpandFace(const Face3D& face,
                                  unsigned int num_points) const;

  Faces3D faces_;
};

}  // namespace ncube

#endif
