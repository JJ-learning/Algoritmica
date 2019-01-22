#include "funciones.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{

	int tam;
	int k;
	Conjunto C;

	cout<<"Introduce el tamaño del conjunto: ";
	cin>>tam;
	C.setConjunto(tam);
	
	cout<<"Introduce el número de K menores que quieres conseguir:";
	cin>>k;
	if(k>=tam){
		cout<<"ERROR: k no puede ser mayor que el tamaño."<<endl;
		exit(-1);
	}
	kmenores(C,k);

	return 0;
}