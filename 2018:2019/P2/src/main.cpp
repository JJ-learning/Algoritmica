#include "funciones.hpp"
#include <random>
#include <iostream>
#include <vector>

using namespace std;

int main()
{	
	int opt=0;
	do{
		cout<< "\nIntroduzca el programa deseado: \n\t1. Combinatorio sin tabla. \n\t2. Combinatorio con tabla. \n\t3. Combinatorio no recursivo. \n\t4. Realizar hanoi para n discos. \n\t0. Salir del pograma"<<endl;
		cin >> opt;

		switch(opt){

			case 1:
				combinatorioSinTabla();
				break;
			case 2:
				combinatorioConTabla();
				break;
			case 3:
				combinatorioNoRecursivo();
				break;
			case 4:
				hanoiMain();
				break;
			case 0:
				break;
			default:
				cout<<"No option recognized. Please, try again."<<endl;
				break;
		}		
	}while(opt!=0);

	return 0;
}

