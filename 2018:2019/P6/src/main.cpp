#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>

#include "funciones.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int opt=0;
    srand(time(NULL));
    do{
        cout<<"\t\tMenu:\n\t1. Resolver problema de las 8 reinas.\n\t2. Resolver problema de las 8 reinas usando Las Vegas.\nIntroduzca la opción deseada: ";
        cin >> opt;
        cout<<endl;
        switch (opt)
        {
            case 1:
                solve8Queen();
                break;
            case 2:
                solve8QueenLV();
                break;
            default:
                cout<<"Exiting the program..."<<endl;
                break;
        }
    }while(opt != 0);
    
    return 0;
}
