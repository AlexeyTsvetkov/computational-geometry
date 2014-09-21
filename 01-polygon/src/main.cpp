#include <iostream>
#include <fstream>
#include <vector>

#include "point.hpp"
#include "polygon.hpp"

point readPoint(std::istream& in) {
  char c;
  long long x;
  long long y;
  in >> c >> x >> c >> y >> c;

  return point(x, y);
}

int main() {
  size_t polygonPointsCount;
  size_t testPointsCount;
  std::vector<point> polygonPoints;

  std::cin >> polygonPointsCount;
  polygonPoints.reserve(polygonPointsCount);

  for (size_t i = 0; i < polygonPointsCount; i++) {
    point polygonPoint = readPoint(std::cin);
    polygonPoints.push_back(polygonPoint);
  }

  polygon poly(polygonPoints);
  std::cin >> testPointsCount;

  for (size_t i = 0; i < testPointsCount; i++) {
    point testPoint = readPoint(std::cin);

    if (poly.contains(testPoint))
      std::cout << "yes\n";
    else
      std::cout << "no\n";
  }

  return 0;
}