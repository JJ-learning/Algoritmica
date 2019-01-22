CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P4)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
add_executable(board.out src/main.cpp src/board.cpp src/funciones.cpp)