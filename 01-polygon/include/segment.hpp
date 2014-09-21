#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "point.hpp"

struct segment {
  segment(point p1_, point p2_);
  segment(const segment& other);

  bool contains(const point& p) const;
  bool is_vertical() const;
  bool is_horizontal() const;
  const point& left() const;
  const point& right() const;
  const point& top() const;
  const point& bottom() const;

  point p1;
  point p2;
};

#endif