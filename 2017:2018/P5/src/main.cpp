#include "Cambio.hpp"
#include "funciones.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int money, cents;
	int tam;
	int numC=0;
	ifstream file("../src/money.txt");
	Cambio c;

	if(file.is_open()){
		while(file){
			file >> cents;
			c.setCambio(cents);
		}
	}
	file.close();
	c.showCambio();

	cout<<"\nIntroduzca la cantidad de dinero: ";
	cin>>money;

	tam = c.getSize();
	
	//Get the minimum amount of coins to get the change
	numC = getMinimo(c, money, tam);
	cout<<"El número de monedas necesario es: "<<numC<<endl;
	return 0;
}