#include "Cambio.hpp"

Cambio::Cambio(){
};

Cambio::~Cambio(){
    this->deno.clear();
};

void Cambio::showCambio(){
    cout<<"El cambio disponible es: ";
    for(int i=0; i<this->deno.size(); i++){
        cout<<this->deno[i]<<" ";
    }
    cout<<endl;
};
