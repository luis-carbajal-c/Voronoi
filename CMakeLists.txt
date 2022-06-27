cmake_minimum_required(VERSION 3.22)
project(Voronoi)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
add_executable(Voronoi main.cpp Voronoi.cpp Voronoi.h)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( Voronoi ${OpenCV_LIBS} )