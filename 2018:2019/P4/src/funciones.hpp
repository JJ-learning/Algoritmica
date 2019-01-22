
#ifndef FUNCIONES__
#define FUNCIONES__

#include "Monedas.hpp"
#include "Mochila.hpp"
#include "Material.hpp"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Funciones para cambio

// Name: cambioMinimo.
// Input: 
// Output: void
// What it does: Main program to get the minimum amount of coins to get the change.
void cambioMinimo();
// Name: getCambio.
// Input: Monedas. M
//          int. cantidad_user
// Output: void
// What it does: Shows the minimum amount of coins to get the change
void getCambio(Monedas M, int cantidad_user);
// Name: showCambio.
// Input: Monedas. M
//          vector<int>. solucion
// Output: void
// What it does: Shows the number of coins used to get the solution
void showCambio(Monedas M, vector<int> solucion);

// Funciones para mochila

// Name: leerMateriales.
// Input: string. file
//          vector<Material>. materiales
// Output: bool. True or false
// What it does: Reads all the material from a file
bool leerMateriales(string file, vector<Material> &materiales);
// Name: mochilaMinimo.
// Input: 
// Output: void
// What it does: Main function to get the the bag filled
void mochilaMinimo();


#endif