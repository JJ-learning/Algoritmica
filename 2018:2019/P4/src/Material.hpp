#ifndef MATERIAL__
#define MATERIAL__
#include <iostream>
#include <vector>
#include <random>
#include <list>

using namespace std;

class Material
{
    private:
        int etiqueta;// Label of the material
        float precio;// Price of the material
        int volumen;// Volume of the material
        string state;// State of the material "usado", "parcial", "no_usado"
    public:
        // Name: Material.
        // What it does: Constructor of the class Material. Initializes the material.
        Material(int etiqueta=-1, float precio=-1.0, int volumen=-1, string estado="usado");
        // Name: ~Material.
        // What it does: Destructor of the class Material. Initializes the material.
        ~Material();

        // Observadores

        // Name: getEtiqueta.
        // Output: int. etiqueta
        // What it does: Returns the label of the material
        inline int getEtiqueta()const{
            return this->etiqueta;
        };
        // Name: getPrecio.
        // Output: float. precio
        // What it does: Returns the price of the material
        inline float getPrecio()const{
            return this->precio;
        };
        // Name: getVolumen.
        // Output: int. volumen
        // What it does: Returns the volume of the material
        inline int getVolumen()const{
            return this->volumen;
        };
        // Name: getState.
        // Output: int. estado
        // What it does: Returns the state of the material
        inline string getState()const{
            return this->state;
        };

        // Modificadores

        // Name: setEtiqueta.
        // Input: int. etiqueta
        // Output: void
        // What it does: It sets the label of the material
        inline void setEtiqueta(int etiqueta){
            this->etiqueta = etiqueta;
        };
        // Name: setPrecio
        // Input: float. precio
        // Output: bool. True or false
        // What it does: It sets the price of the material
        inline bool setPrecio(float precio){
            if(precio < 0){
                cout<<"Precios inferiores a cero no son aceptados"<<endl;
                return false;
            }else{
                this->precio = precio;
                return true;
            }
        };
        // Name: setVolumen
        // Input: int. volumen
        // Output: bool. True or false
        // What it does: It sets the volume of the material
        inline bool setVolumen(int volumen){
            if(volumen<0){
                cout<<"Volumenes inferiores a cero no son aceptados"<<endl;
                return false;
            }else{
                this->volumen = volumen;
                return true;
            }
        };
        // Name: setState
        // Input: string. estado
        // Output: bool. True or false
        // What it does: It sets the state of the material
        inline bool setState(string estado){
            if(estado != "usado" && estado != "parcial" && estado != "no_usado"){
                cout<<"Estado no reconocido"<<endl;
                return false;
            }else{
                this->state = estado;
                return true;
            }
        };

        // Operadores

        // Name: =
        // Input: Material. M
        // Output: void
        // What it does: It sets the material with the material passed
        Material& operator=(const Material &M);
};




#endif