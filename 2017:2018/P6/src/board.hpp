#ifndef BOARD__
#define BOARD__

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Board
{
private:
	vector<vector<int> > board;
	vector<int> possiblesCoordenates;
public:
	// Name: Board
	// param: tam -> int. Size of the board
	// return: void
	// What it does?: Initializes the vector board
	Board(int tam);
	// Name: ~Board
	// param: 
	// return: void
	// What it does?: Destructor of the class Board
	~Board();
	// Name: setBoard
	// param: V -> int. Value of the queen (1-positioned 0-notPositioned)
	//			i -> int. Row of the board
	//			j -> int. Column of the board
	// return: void
	// What it does?: Set a queen in a desired position
	void setBoard(int V, int i, int j);
	// Name: getBoard
	// param: i -> int. Row of the board
	//			j-> int. Column of the board
	// return: int. Get the value of that [i][j]
	// What it does?: Get if in that row and columns exits a queen or not
	int getBoard(int i, int j);
	// Name: getSizeBoard
	// param: 
	// return: int. get the size of the board
	// What it does?: Return the board's size
	int getSizeBoard();
	// Name: showBoard
	// param: 
	// return: void
	// What it does?: print the final board
	void showBoard();
	// Name: setpossibleCases
	// param: 
	// return: 
	// What it does?: Set the queens in random position
	void setpossibleCases();
	// Name: suffleVector
	// param: 
	// return: 
	// What it does?: Suffles the vector in order to get a random position for the queens
	void suffleVector();
	// Name: getpossibleCases
	// param: pos -> int. Position of the queen
	// return: int. Get the position of the random queen
	// What it does?: Return the value of the position of the random queen
	int getpossibleCases(int pos);
	// Name: getpossibleCasesSize
	// param: 
	// return: int. Number of random queen
	// What it does?: Returns the number of random queens
	int getpossibleCasesSize();
	// Name: clearPoss
	// param: 
	// return: void
	// What it does?: Clear the possibleCoordenates vector
	void clearPoss();
	// Name: clearBoard
	// param: 
	// return: void
	// What it does?: Clears the board matrix
	void clearBoard();
};

#endif
