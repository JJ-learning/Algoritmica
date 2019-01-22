#include "funciones.hpp"


bool isSafe(Board tab, int row, int col){
	//Check forward move
	for (int i = 0; i < col; ++i)
	{
		if (tab.getBoard(row, i))
		{
			return false;
		}
	}

	//Check diagonal bottom-right to top-left
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
	{
		if (tab.getBoard(i, j))
		{
			return false;
		}
	}

	//Check diagonal top-right bottom-left
	for (int i = row, j = col; j >= 0 && i < tab.getSizeBoard(); ++i, --j)
	{
		if (tab.getBoard(i,j))
		{
			return false;
		}
	}
	return true;
};

bool solve8Queen(Board tab, int col, int &numIt){
	if(col >= tab.getSizeBoard()){
		cout<<"Solution "<<numIt<<endl;
		numIt++;
		tab.showBoard();
		return true;
	}

	bool ans = false;

	for (int i = 0; i < tab.getSizeBoard(); ++i)
	{
		//Comprobate if the new queen is in a safe position
		if(isSafe(tab, i, col) == true)
		{	
			//Set a new queen in a position
			tab.setBoard(1, i, col);
			//See if it can be placed in that column and row
			ans=solve8Queen(tab, col+1, numIt) || ans;
			
			tab.setBoard(0, i, col);
		}
	}
	return ans;
};

bool isSafeLV(Board tab){
	for (int row = 0; row < tab.getSizeBoard(); ++row)
	{
		for (int col = 0; col < tab.getSizeBoard(); ++col)
		{
			if(tab.getBoard(row,col)){
				if(col!=7){
					for (int i = col+1; i < tab.getSizeBoard(); ++i)
					{
						if(tab.getBoard(row, i)){
							return false;
						}
					}
				}

				if (col!=0 || col!=7){
					for (int i = row+1, j = col-1; i < tab.getSizeBoard()&& j>=0; ++i, --j)
					{
						if(tab.getBoard(i, j)){
							return false;
						}
					}
				}

				if (col !=7 || row!=7){
					for (int i = row+1, j=col+1;j< tab.getSizeBoard() && i < tab.getSizeBoard(); ++i, ++j)
					{
						if(tab.getBoard(i, j)){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool solve8QueenLV(Board tab, int &numIt){
	int j;
	
	bool ans = true;
	do{
		tab.clearPoss();
		tab.clearBoard();
		tab.setpossibleCases();
		numIt++;
		ans = isSafeLV(tab);
	}while(ans == false);
	tab.showBoard();
	return true;
};