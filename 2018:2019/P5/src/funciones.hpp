#ifndef FUNCIONES__
#define FUNCIONES__

#include "Cambio.hpp"
#include "Mochila.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

// Funciones para cambio

void cambioMinimo();
void readFromFile(Cambio &c);
void getMinimo(Cambio c, vector<vector<int> > &tabla, int cantidad_user, int tam);
void showSolution(Cambio c, vector<vector<int> > tabla, int cantidad_user);

void mochilaMinimo();
bool readFromFileM(vector<Material> &material_vector);

#endif