#ifndef FUNCIONES__
#define FUNCIONES__

#include "Conjunto.hpp"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Name: kmenores
// param: C -> Conjunto. Object Conjunto to create the set.
// 			k -> int. Number of k-smaller elements to show.
// return: void
// What it does?: Sets a vector conjunto of random number and shows the k-smaller element of the set.
//					The set is sorted by the algorithm quicksort.
void kmenores(Conjunto C, int k);
// Name: quicksort
// param: start -> int. The first element of the set.
//			end -> int. The last element of the set.
//			numIt -> int. Number of iterations.
//			C -> Conjunto. Object Conjunto.
// return: void
// What it does?: First, set the pivot with the divide method, then, it call itself recursively
//					in but first with the smallest elements and then with the biggest.
void quicksort( int start, int end, int &numIt, Conjunto &C);
// Name: divde
// param: start -> int. The first element of the set.
//			end -> int. The last element of the set.
//			C -> Conjunto. Object Conjunto.
// return: int. Returns the pivot element. 
// What it does?: Calculates the position of the pivot element in order to split the set in two.
int divide( int start, int end, Conjunto &C);

#endif