cmake_minimum_required(VERSION 3.19)

project(generator)

set (CMAKE_CXX_STANDARD 11)

add_executable("generator" "src/main.cpp" "src/Box.cpp" "include/Box.h" "src/Sphere.cpp" "include/Sphere.h" "src/Cone.cpp" "include/Cone.h" "src/Plane.cpp" "include/Plane.h" "../Utils/Point3D.cpp" "../Utils/Point3D.h" "src/Triangle.cpp" "include/Triangle.h" "src/Model.cpp" "include/Model.h" "src/Torus.cpp" "include/Torus.h" "src/Bezier.cpp" "include/Bezier.h" "include/Patch.h")