#include <algorithm>
#include <stdexcept>

#include "polygon.hpp"
#include "turn.hpp"

polygon::polygon(const std::vector<point>& points) {
  if (points.size() < 3)
    throw std::runtime_error("Polygon should have at least 3 vertices");

  min_x = max_x = points[0].x;
  min_y = max_y = points[0].y;
  segments.reserve(points.size());

  for (size_t i = 1; i < points.size(); i++) {
    add_segment(points[i-1], points[i]);
  }

  add_segment(points.back(), points.front());
}

bool polygon::contains(const point& p) const {
  if (out_of_bounding_box(p))
    return false;

  unsigned int intersections = 0;
  for (const segment& seg : segments) {
    if (seg.contains(p))
      return true;

    if (seg.is_horizontal())
      continue;

    if (seg.bottom().y == p.y && seg.bottom().x <= p.x) {
      intersections++;
      continue;
    }

    if (seg.bottom().y < p.y && p.y < seg.top().y)
      if (points_turn(seg.bottom(), p, seg.top()) == turn::right)
        intersections++;
  }

  return intersections % 2 != 0;
}

void polygon::add_segment(const point& p1, const point& p2) {
  update_bounding_box(p1);
  update_bounding_box(p2);

  segments.push_back(segment(p1, p2));
}

void polygon::update_bounding_box(const point& p) {
  min_x = std::min(min_x, p.x);
  max_x = std::max(max_x, p.x);
  min_y = std::min(min_y, p.y);
  max_y = std::max(max_y, p.y);
}

bool polygon::out_of_bounding_box(const point& p) const {
  return p.x < min_x || p.x > max_x
      || p.y < min_y || p.y > max_y;
}