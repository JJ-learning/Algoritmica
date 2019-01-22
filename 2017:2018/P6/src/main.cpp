#include "funciones.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int tam = 8;
	int numIt = 0;
	int opt;
	srand(time(NULL));
	Board tab(tam);
	
	do
	{
		cout<<"\t---Menu---\n\t1. 8 reinas usando algoritmo Backtracking.\n\t2. 8 reinas usando algoritmo Las Vegas.\n\t0. Salir del programa."<<endl;
		cin>>opt;
		switch(opt){
			case 1:{
				if(solve8Queen(tab, 0, numIt) == false){
					cout<<"Solution doesn't exit"<<endl;
					return -1;
				}
				
				cout<<"Numero de soluciones "<<numIt<<endl;
				break;
			}
			case 2:{
				numIt=0;
				if(solve8QueenLV(tab, numIt) == false){
					cout<<"Solution doesn't found"<<endl;
					cout<<"Numero de intentos: "<<numIt<<endl;
					tab.showBoard();
					return -1;
				}

				cout<<"Numero de intentos: "<<numIt;
				break;
			}
		}
	}while(opt!=0);
	
	return 0;
}