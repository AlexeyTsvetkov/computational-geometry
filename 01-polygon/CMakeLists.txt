cmake_minimum_required(VERSION 2.8.4)
add_compile_options(-std=c++11)

include_directories(include)
set(COMMON_SOURCE  src/point.cpp src/polygon.cpp src/segment.cpp src/turn.cpp)
add_executable(program src/main.cpp ${COMMON_SOURCE})
add_executable(test src/test.cpp ${COMMON_SOURCE})