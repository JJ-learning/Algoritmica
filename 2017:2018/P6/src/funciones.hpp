#ifndef FUNCIONES__
#define FUNCIONES__

#include "board.hpp"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Name: solve8Queen
// param: tab -> Board. Object of the class Board
//			col -> int. Column of the board
//			numIt -> int. Number of iterations
// return: bool. Return the answer of the algorithm
// What it does?: Solves the 8 queen problem with a recursive way, and returns if an answer is found
bool solve8Queen(Board tab, int col, int &numIt);
// Name: solve8Queen
// param: tab -> Board. Object of the class Board
//			col -> int. Column of the board
//			row -> int. Row of the board
// return: bool. returns if the position is correct or not
// What it does?: Sees if a queen in a new position is able to not be eaten.
bool isSafe(Board tab, int row, int col);
// Name: solve8QueenLV
// param: tab -> Board. Object of the class Board
//			numIt -> int. Number of iterations
// return: bool. Return the answer of the algorithm
// What it does?: Solves the 8 queen problem with the Las Vegas algorithm
bool solve8QueenLV(Board tab, int &numIt);
// Name: solve8Queen
// param: tab -> Board. Object of the class Board
// return: bool. returns if the position is correct or not
// What it does?: Sees if a queen in a new position is able to not be eaten.
bool isSafeLV(Board tab);

#endif