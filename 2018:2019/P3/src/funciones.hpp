#ifndef FUNCIONES__
#define FUNCIONES__

#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <tgmath.h>
#include "Conjunto.hpp"

void askUser(Conjunto C, int k, Conjunto ksmallest);

void getSmallest(int begin, int end, int x, Conjunto C, Conjunto &ksmallest, int &numIt);

void getkSmallest();

void fillConjunto(Conjunto &C, int tam);

bool isInSet( Conjunto k,int value);

void showSet(Conjunto C);

#endif