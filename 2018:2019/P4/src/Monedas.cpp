#include "Monedas.hpp"

Monedas::Monedas(){
};

Monedas::~Monedas(){
    this->monedas.clear();
};

int Monedas::getCambio(int pos){
    return this->monedas[pos];
};

void Monedas::readFromFile(string File){
    int moneda=0;
    ifstream file;

    file.open(File);
    if(file.is_open()){
        while(!file.eof()){
            file >> moneda;
            this->monedas.push_back(moneda);
        }
    }else{
        cout<<"Error al leer el fichero"<<endl;
        exit(-1);
    }
    file.close();
};

void Monedas::setCambio(string File){
    ofstream file(File);
    int moneda_user;
    if(file.is_open()){
        do{
            cout<<"\t0.Para salir.\n\tIntroduce las monedas o billetes a usar: ";
            cin >> moneda_user;
            if(moneda_user == 0){
                break;
            }
            this->monedas.push_back(moneda_user);
        }while(moneda_user != 0);
    }
    file.close();
};

int Monedas::sizeC(){
    return this->monedas.size();
}

void Monedas::showMonedas(){
    for(int i = 0; i < this->monedas.size();i++){
        cout<<this->monedas[i]<<" ";
    }
    cout<<endl;
}