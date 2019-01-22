CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P2)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
add_executable(Chess.out src/main.cpp src/Chess.cpp src/funciones.cpp)