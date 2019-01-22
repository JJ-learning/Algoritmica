#include "funciones.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <fstream>

int main(int argc, char const *argv[])
{
    int opt;
    do{
        cout<<"\n\tPractica 4: Algoritmos voraces"<<endl;
        cout<<"\t 0. Salir del programa."<<endl;
        cout<<"\t 1. Conseguir cambio minimo."<<endl;
        cout<<"\t 2. Solucion al problema de la mochila."<<endl;
        cin >> opt;
        switch (opt)
        {
            case 1:
                cambioMinimo();
                break;
            case 2:
                mochilaMinimo();
            default:
                break;
        }
    }while(opt!=0);

    return 0;
}
