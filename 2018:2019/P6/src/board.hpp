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
        vector<int> possible_solutions;
    public:
        Board(int size);
        ~Board();

        inline void setBoard(int value, int i, int j){
            this->board[i][j] = value;
        };

        inline int getBoard(int i, int j){
            return this->board[i][j];
        };

        inline int getSizeBoard(){
            return this->board.size();
        }

        inline int getSizePossibleSolution(){
            return this->possible_solutions.size();
        };

        inline int getPossibleSolution(int pos){
            return this->possible_solutions[pos];
        };

        inline void clearPossibleSolution(){
            this->possible_solutions.clear();
        }

        void shuffleVector();

        void setPossibleSolution();

        void clearBoard();
        void showBoard();

};

#endif