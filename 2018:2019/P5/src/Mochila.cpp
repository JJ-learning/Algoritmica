#include "Mochila.hpp"

Material Mochila::getMaterial(int i){
    assert(i > 0 && i < this->material_set_.size());
    int j=0;
    for(list<Material>::iterator it = this->material_set_.begin(); it != this->material_set_.end(); it++){
        if(i==j){
            return *it;
        }
        else{
            cout<<"No hay material disponible"<<endl;
            exit(-1);
            return -1;
        }
    }
};

float Mochila::getValueBag(){
    list<Material>::iterator it;
    float aux = 0.0;

    for(it = this->material_set_.begin(); it != this->material_set_.end(); it++){
        aux = aux + (it->getValue() * it->getVolume());
    }

    return aux;
};

void Mochila::bagElements(){
    list<Material>::iterator it;
    cout<<"\tEl volumen usado es: "<<this->used_volume_<<" de un total de "<<this->getMaxCapacity()<<endl;
    cout<<"\tLos materiales que contiene son: "<<endl;
    for(it = this->material_set_.begin(); it != this->material_set_.end(); it++){
        cout<<"\n\t\tEtiqueta: "<<it->getLabel()<<endl;
        cout<<"\t\tPrecio unidad: "<<it->getValue()<<endl;
        cout<<"\t\tVolumen: "<<it->getVolume()<<endl;
        cout<<"\t\tValor total: "<<(it->getValue() * it->getVolume())<<endl;
    }
};

bool Mochila::setMaximumCapacity(int max_capacity){
    if(max_capacity > 0){
        this->max_capacity_ = max_capacity;
        return true;
    }else{
        return false;
    }
};

bool Mochila::addMaterial(Material &m){
    this->used_volume_ = this->used_volume_ + m.getVolume();
    this->material_set_.push_back(m);

    return true;
};

void Mochila::fillBag(vector<Material> &materiales, vector<vector<int> > &tabla_materiales){
    // TODO
    tabla_materiales.resize(materiales.size());
    for(int i=0; i<materiales.size(); i++){
        tabla_materiales[i].resize(this->getMaxCapacity()+1, 0);
    }

    for(int i=0; i<this->getMaxCapacity(); i++){
        if(i >= materiales[0].getVolume()){
            tabla_materiales[0][i] = materiales[0].getValue() * materiales[0].getVolume();
        }
    }

    for(int i=1; i<materiales.size(); i++){
        for(int j=1; j<this->getMaxCapacity()+1; j++){
            if(j < materiales[i].getVolume()){
                tabla_materiales[i][j] = tabla_materiales[i-1][j];
            }else{
                if(tabla_materiales[i-1][j] > materiales[i].getValue() * materiales[i].getVolume() + tabla_materiales[i-1][j-materiales[i].getVolume()]){
                    tabla_materiales[i][j] = tabla_materiales[i-1][j];
                }else{
                    tabla_materiales[i][j] = materiales[i].getValue() * materiales[i].getVolume() + tabla_materiales[i-1][j-materiales[i].getVolume()];
                }
            }
        }
    }
};

void Mochila::getSolution(vector<Material> &materiales, vector<vector<int> > &tabla_materiales){
    // TODO
    int remaining_cap = this->getMaxCapacity();
    int i=materiales.size()-1;
    bool exit=false;

    while(remaining_cap > 0 && tabla_materiales[i][remaining_cap] != 0 && !exit){
        if(i > 0){
            if(tabla_materiales[i][remaining_cap] == tabla_materiales[i-1][remaining_cap]){
                i--;
            }else{
                if(tabla_materiales[i][remaining_cap] > 0){
                    remaining_cap -= materiales[i].getVolume();
                    addMaterial(materiales[i]);
                    i--;
                }
            }
        }else{
            if(remaining_cap > materiales[i].getVolume()){
                remaining_cap -= materiales[i].getVolume();
                addMaterial(materiales[i]);
                exit=true;
            }
        }
    }
};