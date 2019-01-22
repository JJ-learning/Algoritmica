#include "funciones.hpp"

bool isSafe(Board chess, int row, int col){
	// TODO
	for(int i=0; i<col; i++){
		if(chess.getBoard(row, i)){
			return false;
		}
	}
	for(int i=row, j=col; i>=0 && j>=0; i--, j--){
		if(chess.getBoard(i,j)){
			return false;
		}
	}
	for(int i=row, j=col; i<chess.getSizeBoard() && j>=0; i++, j--){
		if(chess.getBoard(i,j)){
			return false;
		}
	}
	return true;
}

bool getSolution(Board chess, int col, int &num_iteration){
	// TODO
	bool ans=false;
	if(col >= chess.getSizeBoard()){
		cout<<"Solution "<<num_iteration<<endl;
		num_iteration++;
		chess.showBoard();
		return true;
	}
	for(int i=0; i<chess.getSizeBoard(); i++){
		if(isSafe(chess, i, col)){
			chess.setBoard(1, i, col);
			ans = getSolution(chess, col+1, num_iteration) || ans;
			chess.setBoard(0, i, col);
		}
	}
	return ans;
}

void solve8Queen(){
    Board chess(8);
    int col = 0;
    int num_iteration = 0;

    if(getSolution(chess, col, num_iteration) == true){
        cout<<"\nEl numero de iteraciones ha sido: "<<num_iteration<<endl<<endl;
    }else{
        cout<<"\nNo se ha podido encontrar ninguna solucion."<<endl;
        cout<<"\nSe ha intentado: "<<num_iteration<<endl;
        exit(-1);
    }
}

bool isSafeLV(Board chess){
	// TODO
    for(int row=0; row<chess.getSizeBoard(); row++){
		for(int col=0; col<chess.getSizeBoard(); col++){
			if(chess.getBoard(row, col)){
				if(col!=7){
					for(int i=col-1; i>=0; i--){
						if(chess.getBoard(row, i)){
							return false;
						}
					}
				}
				if(col!=0 || col!=7){
					for(int i=row+1, j=col-1; i<chess.getSizeBoard() && j>=0; i++, j--){
						if(chess.getBoard(i,j)){
							return false;
						}
					}
				}
				if(row!=7 || col!=7){
					for(int i=row+1, j=col+1; i<chess.getSizeBoard() && j<chess.getSizeBoard(); i++, j++){
						if(chess.getBoard(i,j)){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool getSolutionLV(Board chess, int &num_iteration){
	// TODO
    bool ans=false;

	do{
		chess.clearBoard();
		chess.clearPossibleSolution();
		chess.setPossibleSolution();
		num_iteration++;
		ans = isSafeLV(chess);
	}while(ans == false);

	chess.showBoard();
	return true;
}

void solve8QueenLV(){
    Board chess(8);
    int num_iteration = 0;

    if(getSolutionLV(chess, num_iteration) == true){
       cout<<"\nEl numero de iteraciones ha sido: "<<num_iteration<<endl<<endl;
    }else{
        cout<<"\nNo se ha podido encontrar ninguna solucion."<<endl;
        cout<<"\nSe ha intentado: "<<num_iteration<<endl;
        exit(-1);
    }
}