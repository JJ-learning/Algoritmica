#ifndef FUNCIONES__
#define FUNCIONES__

#include "Cambio.hpp"
#include <iostream>
#include <vector>
#include <random>

using namespace std;
// Name: getMinimo
// param: c -> Cambio. Object of the class Cambio
//			V -> int. Money that needs the change
//			tam -> int. Size of the vector that keeps the type of coins
// return: int
// What it does?: Returns the number of coins used in order to get the change
int getMinimo(Cambio c, int V, int tam);

#endif