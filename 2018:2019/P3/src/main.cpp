#include "funciones.hpp"
#include <random>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	int opt = 0;
	do{
		cout<<"\n\t Practica 3: Divide y venceras"<<endl;
		cout<<"\n\t Options:\n\t 0. Salir del programa.\n\t 1. Calcular los k-menores."<<endl;
		cin >> opt;
		switch(opt){
			case 1:
				getkSmallest();
				break;
			case 0:
				cout<<"Saliendo del programa..."<<endl;
				return 0;
				break;
			default:
				cout<<"Opcion no reconocida. Saliendo del programa..."<<endl;
				break;
		};
	}while(opt != 0);
	return 0;
}