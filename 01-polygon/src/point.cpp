#include "point.hpp"

point::point(long long x_, long long y_)
: x(x_),
  y(y_) {}

point::point(const point& other)
: x(other.x),
  y(other.y) {}

bool point::equals(const point& other) const {
  return x == other.x && y == other.y;
}