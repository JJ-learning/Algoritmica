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

	cout<<"El cambio final para "<<money<< " es: ";
	getMinimo(c, money);
	
	return 0;
}