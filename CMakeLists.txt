cmake_minimum_required(VERSION 3.13)
project(geoimg)
set(CMAKE_CXX_STANDARD 14)

#find_package(OpenCV REQUIRED)

include(${CMAKE_SOURCE_DIR}/conan/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(geoimg main.cpp src/Utilities.h src/Shapes/Shape.h src/Shapes/Circle.cpp src/Shapes/Circle.h)
target_link_libraries(geoimg ${CONAN_LIBS})
#target_link_libraries(geoimg ${OpenCV_LIBS})