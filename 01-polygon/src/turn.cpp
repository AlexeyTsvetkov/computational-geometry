#include "turn.hpp"

turn points_turn(
  const point& p1,
  const point& p2,
  const point& p3
) {
  /*
   * determinant of matrix
   * | x1 x2 x3 |
   * | y1 y2 y3 |
   * | 1  1  1  |
   */

  long long det = p1.x * p2.y + p3.x * p1.y + p2.x * p3.y
                 -p2.y * p3.x - p1.y * p2.x - p3.y * p1.x;

  if (det > 0)
    return turn::right;

  if (det < 0)
    return turn::left;

  return turn::none;
}