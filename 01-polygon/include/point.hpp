#ifndef POINT_HPP
#define POINT_HPP

struct point {
  point(long long x_, long long y_);
  point(const point& other);
  bool equals(const point& other) const;

  long long x;
  long long y;
};

#endif