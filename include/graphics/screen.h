#ifndef SCREEN_H_
#define SCREEN_H_

#include "common/types.h"

namespace ncube {
namespace graphics {

/**
 * \brief Screen Dimensions
 */
struct ScreenDimension {
  int width = 0;  /**< Screen width */
  int height = 0; /**< Screen height */
};

/**
 * \brief Initialize the ncurses screen.
 * \returns The dimensions of the screen (i.e., terminal window).
 */
[[nodiscard]] ScreenDimension InitScreen() noexcept;

/**
 * \brief Cleanup ncurses window(s).
 */
void TerminateScreen() noexcept;

/**
 * \brief Clear the screen.
 */
void Clear() noexcept;

/**
 * \brief Set the ncurses input delay.
 * \details Setting the delay too high can cause the application to appear laggy
 *          whereas setting the delay too low can waste CPU cycles.
 * \param [in] delay_ms Input delay in milliseconds.
 */
void EnableInputDelay(int delay_ms) noexcept;

/**
 * \brief Clear input delay settings previously set by EnableInputDelay().
 */
void DisableInputDelay() noexcept;

/**
 * \brief Update the cursor location dependent on user keypresses.
 * \details Unfortunately, this function bundles both application exit and
 *          cursor updates. UpdateCursor() monitors the user's keypresses.
 *          If they press the arrow keys, then the cursor location is updated
 *          accordingly. If they press 'q', \c true is returned and \p cursor
 *          is left unchanged. If they press any other key, \c false is returned
 *          and \p cursor is left unchanged.
 * \param [in] screen_dim Screen (i.e., terminal) dimensions.
 * \param [out] cursor 2D location of on-screen cursor.
 * \returns \c false if the user has hit the 'q' key, \c true otherwise.
 */
[[nodiscard]] bool UpdateCursor(const ScreenDimension& screen_dim,
                                Point2D& cursor) noexcept;

/**
 * \brief Render a 2D projection on screen.
 * \param [in] faces The faces of a 2D projection of a 3D object.
 */
void DrawObject(const Faces2D& faces) noexcept;

/**
 * \brief Print a help message on screen.
 * \param [in] screen_dim Screen (i.e., terminal) dimensions.
 */
void DrawInstructions(const ScreenDimension& screen_dim) noexcept;

}  // namespace graphics
}  // namespace ncube

#endif
