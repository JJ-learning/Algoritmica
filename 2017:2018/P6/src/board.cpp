#include "board.hpp"

Board::Board(int tam){
	for (int i = 0; i < tam; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < tam; ++j)
		{
			temp.push_back(0);
		}
		this->board.push_back(temp);
	}

}

Board::~Board(){
}

void Board::clearBoard(){
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			this->board[i][j]=0;
		}
	}
}

void Board::showBoard(){
	for (int i = 0; i < this->board.size(); ++i)
	{
		for (int j = 0; j < this->board.size(); ++j)
		{
			cout<<this->getBoard(i, j)<<" ";
		}
		cout<<endl;
	}
}

void Board::setBoard(int V, int i, int j){
	this->board[i][j]=V;
}

int Board::getBoard(int i, int j){
	return this->board[i][j];
}

int Board::getSizeBoard(){
	return this->board.size();
}

void Board::suffleVector(){
	for (int i = 0; i < this->getpossibleCasesSize(); ++i)
	{
		int aux = rand() % this->getpossibleCasesSize();
		int aux2 = rand() % this->getpossibleCasesSize();
		int temp = this->possiblesCoordenates[aux];
		this->possiblesCoordenates[aux] = this->possiblesCoordenates[aux2];
		this->possiblesCoordenates[aux2] = temp;
	}
}

int Board::getpossibleCasesSize(){
	return this->possiblesCoordenates.size();
}

int Board::getpossibleCases(int pos){
	return this->possiblesCoordenates[pos];
}

void Board::clearPoss(){
	this->possiblesCoordenates.clear();
}

void Board::setpossibleCases(){
	for (int i = 0; i < this->getSizeBoard(); ++i)
	{
		this->possiblesCoordenates.push_back(i);	
	}
	
	suffleVector();

	for (int i = 0; i < this->getSizeBoard(); ++i)
	{
		this->setBoard(1, i, this->getpossibleCases(i));
	}
}