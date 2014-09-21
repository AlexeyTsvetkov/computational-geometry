#include <iostream>
#include <vector>
#include <stdexcept>

#include "point.hpp"
#include "polygon.hpp"

template<typename T>
void assertEquals(
  const T& expected,
  const T& actual,
  const std::string& message
) {
  if (expected != actual)
    throw std::runtime_error(message);
}

// square test
void test1() {
  polygon poly(
    {
      point(0,0),
      point(4,0),
      point(4,4),
      point(0,4)
    });

  assertEquals(false, poly.contains(point(5, 2)), "test1: point(5, 2)");
  assertEquals(false, poly.contains(point(5, 4)), "test1: point(5, 4)");
  assertEquals(false, poly.contains(point(-1, 2)), "test1: point(-1, 2)");

  assertEquals(true, poly.contains(point(4, 2)), "test1: point(4, 2)");
  assertEquals(true, poly.contains(point(3, 2)), "test1: point(3, 2)");
  assertEquals(true, poly.contains(point(0, 2)), "test1: point(0, 2)");
}

// triangle test
void test2() {
  polygon poly(
    {
      point(0,0),
      point(6,0),
      point(3,3)
    });

  assertEquals(false, poly.contains(point(3, 4)), "test2: point(3, 4)");
  assertEquals(false, poly.contains(point(3, -1)), "test2: point(3, -1)");
  assertEquals(false, poly.contains(point(1, 2)), "test2: point(1, 2)");
  assertEquals(false, poly.contains(point(5, 2)), "test2: point(5, 2)");

  // top
  assertEquals(true, poly.contains(point(3, 3)), "test2: point(3, 3)");

  // bottom
  assertEquals(true, poly.contains(point(2, 0)), "test2: point(2, 0)");
  assertEquals(true, poly.contains(point(4, 0)), "test2: point(4, 0)");

  // left side
  assertEquals(true, poly.contains(point(2, 2)), "test2: point(2, 2)");
  assertEquals(true, poly.contains(point(1, 1)), "test2: point(1, 1)");
  assertEquals(true, poly.contains(point(0, 0)), "test2: point(0, 0)");

  // right side
  assertEquals(true, poly.contains(point(4, 2)), "test2: point(4, 2)");
  assertEquals(true, poly.contains(point(5, 1)), "test2: point(5, 1)");
  assertEquals(true, poly.contains(point(6, 0)), "test2: point(6, 0)");

  // inside
  assertEquals(true, poly.contains(point(3, 1)), "test2: point(3, 1)");
  assertEquals(true, poly.contains(point(3, 2)), "test2: point(3, 2)");
  assertEquals(true, poly.contains(point(4, 1)), "test2: point(4, 1)");
  assertEquals(true, poly.contains(point(2, 1)), "test2: point(2, 1)");
}

// complex polygon test
void test3() {
  polygon poly(
    {
      point(0,3),
      point(2,1),
      point(4,3),
      point(5,2),
      point(6,3),
      point(7,3),
      point(6,4),
      point(4,4),
      point(1,4)
    });

  assertEquals(false, poly.contains(point(4, 2)), "test3: point(4, 2)");
  assertEquals(false, poly.contains(point(4, 1)), "test3: point(4, 1)");
  assertEquals(false, poly.contains(point(7, 4)), "test3: point(7, 4)");
  assertEquals(false, poly.contains(point(7, 2)), "test3: point(7, 2)");
  assertEquals(false, poly.contains(point(8, 3)), "test3: point(8, 3)");
  assertEquals(false, poly.contains(point(0, 2)), "test3: point(0, 2)");
  assertEquals(false, poly.contains(point(0, 4)), "test3: point(0, 4)");

  assertEquals(true, poly.contains(point(5, 3)), "test3: point(5, 3)");
  assertEquals(true, poly.contains(point(1, 3)), "test3: point(1, 3)");
  assertEquals(true, poly.contains(point(2, 2)), "test3: point(2, 2)");
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}