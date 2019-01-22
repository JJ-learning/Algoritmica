#include "Mochila.hpp"

Mochila::Mochila(int capacidad)
{
    if(capacidad > 0){
        this->capacidad_maxima = capacidad;
        this->volumen_usado = 0;
    }else{
        this->volumen_usado = 0;
    }
};

Mochila::~Mochila()
{
    this->volumen_usado = 0;
    this->conjunto.clear();
};

float Mochila::getMochila(){
    list<Material>::iterator it;
    float aux = 0.0;
    // Calculamos el precio total de la mochila sumando todos los precios por unidades de volumen
    for(it=this->conjunto.begin(); it != this->conjunto.end(); it++){
        aux = aux + it->getPrecio() * it->getVolumen();
    }
    return aux;
};

void Mochila::getContenidoMochila(){
    list<Material>::iterator it;

    for(it=this->conjunto.begin(); it != this->conjunto.end(); it++){
        cout<<"Etiqueta: "<<it->getEtiqueta()<<endl;
        cout<<"Precio: "<<it->getPrecio()<<endl;
        cout<<"Volumen usado: "<<it->getVolumen()<<endl;
        cout<<"Estado: "<<it->getState()<<endl;
        cout<<"Valor total: "<<it->getPrecio()*it->getVolumen()<<endl;
        cout<<endl;
    }
};

bool Mochila::setCapacidad(int capacidad){
    if(capacidad<=0){
        return false;
    }else{
        this->capacidad_maxima = capacidad;
        return true;
    }
};

bool Mochila::nuevoMaterial(Material &M){
    // Si el volumen que hemos usado es menor que la capacidad de la mochila
    if(this->volumen_usado != this->capacidad_maxima){
        Material auxM;
        // El volumen del material entra en la mochila
        if(this->getVolumenQueda() > M.getVolumen()){
            M.setState("usado");
            auxM = M;
            this->volumen_usado += auxM.getVolumen();
        }// El volumen del material no entra entero en la mochila
        else{
            M.setState("parcial");
            auxM = M;
            auxM.setVolumen(this->capacidad_maxima - this->volumen_usado);
            this->volumen_usado = this->capacidad_maxima;
        }
        this->conjunto.push_back(auxM);
        return true;
    }// El material no cabe en la mochila
    else{
        return false;
    }
};

void Mochila::vaciarMochila(){
    this->volumen_usado = 0;
    this->conjunto.clear();
};

void Mochila::rellenarMochila(vector<Material> &materiales){
    int precio_maximo;
    int material_maximo;
    bool material_esta_disponible;
    Material auxM;

    // Inicializamos la mochila a zero
    vaciarMochila();

    // Inicializamos los materiales
    for(int i = 0; i < materiales.size(); i++){
        materiales[i].setState("no_usado");
    }

    // Rellenamos la mochila hasta que sea posible
    do{
        precio_maximo = 0;
        material_maximo = 0;
        material_esta_disponible = false;
        // Recorremos todos los materiales disponibles
        for(int i = 0; i < materiales.size(); i++){
            // Si el material no ha sido usado
            if(materiales[i].getState() == "no_usado"){
                material_esta_disponible = true;
                // Si el precio del material es mayor que el precio maximo guardamos el material en la mochila
                if(materiales[i].getPrecio() > precio_maximo){
                    material_maximo = i;
                    precio_maximo = materiales[i].getPrecio();
                }
            }
        }

        // Introducimos el material en la mochila
        if(material_esta_disponible == true){
            nuevoMaterial(materiales[material_maximo]);
        }
    }while(this->getVolumenQueda() != 0 && material_esta_disponible==true);
};

