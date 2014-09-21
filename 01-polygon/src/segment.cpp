#include "segment.hpp"
#include "turn.hpp"

segment::segment(point p1_, point p2_)
: p1(p1_),
  p2(p2_) {}

segment::segment(const segment& other)
: p1(other.p1),
  p2(other.p2) {}

bool segment::contains(const point& p) const {
  if (p1.equals(p) || p2.equals(p))
    return true;

  return points_turn(bottom(), p, top()) == turn::none
    && left().x <= p.x && p.x <= right().x
    && bottom().y <= p.y && p.y <= top().y;
}

bool segment::is_vertical() const {
  return p1.x == p2.x;
}

bool segment::is_horizontal() const {
  return p1.y == p2.y;
}

const point& segment::left() const {
  return p1.x < p2.x ? p1 : p2;
}

const point& segment::right() const {
  return p1.x > p2.x ? p1 : p2;
}

const point& segment::top() const {
  return p1.y > p2.y ? p1 : p2;
}

const point& segment::bottom() const {
  return p1.y < p2.y ? p1 : p2;
}
