#include "funciones.hpp"
#include <random>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));
	int opt=0;
	


	do{
		cout<< "\nIntroduzca el programa deseado: \n\t1.Metodo burbuja.\n\t2.Ordenacion por montículo.\n\t0.Salir del programa."<<endl;
		cin >> opt;

		switch(opt){

			case 1:
				bubbleFunction();
				break;
			case 2:
				heapFunction();
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

