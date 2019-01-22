#ifndef __CAMBIO__
#define __CAMBIO__

#include <list>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <assert.h>

using namespace std;

class Cambio{
    private:
        vector<int> deno;
    public:
        Cambio();

        ~Cambio();

        inline void setCambio(int V){
            if(V <= 0){
                cout<<"Error! No puedes introducir un numero menor que 0"<<endl;
            }else{
                this->deno.push_back(V);
            } 
        };

        inline int getCambio(int pos){
            assert(pos >= 0);
            return this->deno[pos];
        };

        inline int getSizeC(){
            return this->deno.size();
        }

        inline vector<int> getVector(){
            return this->deno;
        }

        void showCambio();


};

#endif