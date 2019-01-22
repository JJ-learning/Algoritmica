#ifndef FUNCIONES__
#define FUNCIONES__

#include <iostream>
#include <vector>
#include <random>
#include "board.hpp"

void solve8Queen();
bool isSafe();
bool getSolution(Board chess, int col, int &num_iteration);
void solve8QueenLV();
bool getSolutionLV(Board chess, int &num_iteration);
bool isSafeLV(Board chess);

#endif