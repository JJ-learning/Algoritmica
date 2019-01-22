#include "Chess.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	char opt;
	int row_begin, col_begin, row_final,col_final;

	do{
		cout<<"\n\t\t\t---MENU---\n\t1. Calcular caminos posibles para llegar a la meta.\n\t2. Calcular desde fila 2 caminos posibles para coronar.\n\t3. Calcular caminos posibles para coronar.\n\t0. Salir del programa."<<endl; 
		cin >> opt;
		switch(opt){
			case '1':{
				cout<<"Introduzca la fila del peon(1-8): ";
				cin>>row_begin;
				cout<<"Introduzca la fila del peon(1-8): ";
				cin>>col_begin;

				cout<<"Introduzca la columna deseada para llegar(1-8):";
				cin>>col_final;

				if (row_begin<=0||row_begin>8||col_begin<=0||col_begin>8 ||col_final<=0|| col_final>8)
				{
					cout<<"Error al introducir coordenadas."<<endl;
					exit(-1);
				}
				//Set the graph
				Chess T(8-1, col_final-1);

				//Add adyancent
				T.addEdge(row_begin-1, col_begin-1, opt);
			break;
			}
			
			case '2':{
				cout<<"Introduzca la columna del peon(1-8): ";
				cin>>col_begin;

				if (col_begin<=0||col_begin>8)
				{
					cout<<"Error al introducir coordenadas."<<endl;
					exit(-1);
				}
				//Set the graph
				Chess T(8-1, 1-1);

				//Add adyancent
				T.addEdge(2-1, col_begin-1, opt);
			break;
			}

			case '3':{
				cout<<"Introduzca la fila del peon(1-8): ";
				cin>>row_begin;
				cout<<"Introduzca la fila del peon(1-8): ";
				cin>>col_begin;


				if (row_begin<=0||row_begin>8||col_begin<=0||col_begin>8)
				{
					cout<<"Error al introducir coordenadas."<<endl;
					exit(-1);
				}
				//Set the graph
				Chess T(8-1, col_final-1);

				//Add adyancent
				T.addEdge(row_begin-1, col_begin-1, opt);
			break;
			}/*¿Es igual que el apartado 3?
			case '4':{
				cout<<"Introduzca la columna del peon(1-8): ";
				cin>>col_begin;

				if (col_begin<=0||col_begin>=8)
				{
					cout<<"Error al introducir coordenadas."<<endl;
					exit(-1);
				}
				//Set the graph
				Chess T(8-1, 1-1);

				//Add adyancent
				T.addEdge(2-1, col_begin-1, opt);
			break;
			}*/
			
		}
	}while(opt!='0');

	return 0;
}