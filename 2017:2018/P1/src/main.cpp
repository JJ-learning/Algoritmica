#include "funciones2.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	int min, max, inc;
	int opt=0;

	do{
		cout<<"\n\t\t\t---MENU---\n\t1. Calcular el término n-esimo de la sucesion Fibonacci.\n\t2. Calcular determinante recursivo de matriz aleatoria.\n\t0. Salir del programa."<<endl;
		cin >> opt;
		switch(opt){
			case 1:
				cout<<"\tIntroduzca el minimo:";
				cin >> min;
				cout<<"\tIntruzca el maximo:";
				cin >> max;
				cout<<"\tIntroduzca el incremento:";
				cin >> inc;
				
				getFibonacci(min, max, inc);
			break;

			case 2:
				cout<<"\tIntroduzca el minimo:";
				cin >> min;
				cout<<"\tIntruzca el maximo:";
				cin >> max;
				cout<<"\tIntroduzca el incremento:";
				cin >> inc;
				
				getDeterminante(min, max, inc);
			break;
			case 0:
				cout<<"Cerrando el programa... ¡Hasta pronto!"<<endl;
			break;
			default:
				cout<<"Error... Option not recogniced"<<endl;
				exit(-1);
			break;
		}
	}while(opt!=0);

	return 0;
}