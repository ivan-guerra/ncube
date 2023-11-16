#ifndef UTIL_H_
#define UTIL_H_

#include "common/types.h"
#include "cube/cube.h"

namespace ncube {

/**
 * \brief Perform perspective projection and camera rotation.
 * \details This function projects the cube from 3D space to 2D space. Rotation
 *          of the camera around the cube is also performed using the cursor
 *          location to dictate how the camera moves.
 * \param [in] cube A 3D cube object.
 * \param [in] conf View settings (FOV, camera distance, etc.).
 * \param [in] cursor_x Cursor X position on the screen.
 * \param [in] cursor_y Cursor Y position on the screen.
 * \returns A 2D projection of the cube with rotation information included
 *          in the coordinates.
 */
[[nodiscard]] Faces2D RotateAndProject3Dto2D(const Cube& cube,
                                             const ViewConfig& conf,
                                             double cursor_x, double cursor_y);

}  // namespace ncube

#endif
