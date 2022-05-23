cmake_minimum_required(VERSION 3.13)
project(geoimg)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(geoimg main.cpp src/Utilities.h)
target_link_libraries(geoimg ${OpenCV_LIBS})