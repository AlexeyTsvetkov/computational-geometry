#ifndef TURN_HPP
#define TURN_HPP

#include "point.hpp"

enum class turn {
  left, right, none
};

turn points_turn(
  const point& p1,
  const point& p2,
  const point& p3
);

#endif