
#ifndef MOCHILA__
#define MOCHILA__

#include "Material.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <list>

using namespace std;


class Mochila
{
    private:
        int capacidad_maxima;// Maximum capacity of the bag
        int volumen_usado;// Volume used to fill the bag
        list<Material> conjunto;// List of materials within the bag
    public:
        // Name: Mochila.
        // What it does: Constructor of the class Mochila. Initializes the bag.
        Mochila(int capacidad=100);
        // Name: ~Mochila.
        // What it does: Destructor of the class Mochila. Deletes the bag.
        ~Mochila();

        // Observadores

        // Name: getCapacidadMaxima.
        // Output: int. Maximum capacity
        // What it does: Returns the maximum capacity of the bag
        inline int getCapacidadMaxima()const{
            return this->capacidad_maxima;
        };
        // Name: getVolumenQueda.
        // Output: int. Capacidad maxima-volument usado
        // What it does: Returns the amount of volume that left in the bag
        inline int getVolumenQueda()const{
            return (this->capacidad_maxima - this->volumen_usado);
        };
        // Name: getVolumenQueda.
        // Output: list<Material>. conjunto
        // What it does: Returns the material used to fill the bag
        inline list<Material> getMateriales()const{
            return conjunto;
        };
        // Name: getMochila.
        // Output: float. price
        // What it does: Returns the price of the bag within all the materials
        float getMochila();
        // Name: getContenidoMochila.
        // Output: void
        // What it does: Shows all the materials within the bag
        void getContenidoMochila();

        // Modificadores

        // Name: setCapacidad.
        // Input: int. capacidad
        // Output: bool. True or false
        // What it does: It sets the capacity of the bag.
        bool setCapacidad(int capacidad);
        // Name: nuevoMaterial.
        // Input: Material. M
        // Output: bool. True or false
        // What it does: It fills the bag with an allawed new material.
        bool nuevoMaterial(Material &M);
        // Name: rellenarMochila.
        // Input: vector<Material>. materiales
        // Output: void
        // What it does: It fills the bag with the maximum amount of materials allawed
        void rellenarMochila(vector<Material> &materiales);
        // Name: vaciarMochila.
        // Input: 
        // Output: void
        // What it does: It pop out all the materials in the bag leaving it empty
        void vaciarMochila();
};





#endif