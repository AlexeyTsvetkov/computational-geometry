#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

#include "point.hpp"
#include "segment.hpp"

struct polygon {
  polygon(const std::vector<point>& points);

  bool contains(const point& p) const;
private:
  void add_segment(const point& p1, const point& p2);
  void update_bounding_box(const point& p);
  bool out_of_bounding_box(const point& p) const;

  std::vector<segment> segments;
  long long min_x;
  long long max_x;
  long long min_y;
  long long max_y;
};

#endif