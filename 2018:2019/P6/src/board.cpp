#include "board.hpp"

Board::Board(int size)
{
    // Initializes to 0 all the board
    for(int i = 0; i < size; i++){
        vector<int> temp;
        for(int j = 0; j < size; j++){
            temp.push_back(0);
        }
        this->board.push_back(temp);
    }
}

Board::~Board()
{
    this->board.clear();
    this->possible_solutions.clear();
}

void Board::shuffleVector(){
    for (int i = 0; i < this->getSizePossibleSolution(); ++i)
	{
		int aux = rand() % this->getSizePossibleSolution();
		int aux2 = rand() % this->getSizePossibleSolution();
		int temp = this->possible_solutions[aux];
		this->possible_solutions[aux] = this->possible_solutions[aux2];
		this->possible_solutions[aux2] = temp;
	}
}

void Board::setPossibleSolution(){
    for(int i = 0; i < this->getSizeBoard(); i++){
        this->possible_solutions.push_back(i);
    }

    this->shuffleVector();

    // We set to 1 all the possible coordinates
    for(int i = 0; i < this->getSizeBoard(); i++){
        this->setBoard(1, i, this->getPossibleSolution(i));
    }
}

void Board::clearBoard(){
    for(int i = 0; i < this->getSizeBoard(); i++){
        for(int j = 0; j < this->getSizeBoard(); j++){
            this->board[i][j] = 0;
        }
    }
}

void Board::showBoard(){
    for(int i = 0; i < this->getSizeBoard(); i++){
        for(int j = 0; j < this->getSizeBoard(); j++){
            cout<<this->board[i][j]<<" ";
        }
        cout<<endl;
    }
}