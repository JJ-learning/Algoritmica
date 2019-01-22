CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P5)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
add_executable(Cambio.out src/main.cpp src/Cambio.cpp src/funciones.cpp)