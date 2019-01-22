CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P3)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
add_executable(Conjunto.out src/main.cpp src/Conjunto.cpp src/funciones.cpp)