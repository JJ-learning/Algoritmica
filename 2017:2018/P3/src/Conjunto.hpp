#ifndef CONJUNTO__
#define CONJUNTO__

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Conjunto
{
	private:
		vector<int> conjunto;
	public:
		// Name: Conjunto
		// param: 
		// return: void
		// What it does?: Constructor of the class Conjunto. It does nothing.
		Conjunto();
		// Name: ~Conjunto
		// param: 
		// return: void
		// What it does?: Desctructor of the class Conjunto. Clears the vector conjunto.
		~Conjunto();
		// Name: getPosConjunto
		// param: pos -> int. Postion of the vector conjunto that the user wants.
		// return: int -> Vector's Element
		// What it does?: Returns a element of a vector in a given position
		int getPosConjunto(int pos);
		// Name: setConjunto
		// param: tam -> int. The size of the vector conjunto.
		// return: void
		// What it does?: Sets the vector conjunto to a given size and then it fills it with random naumber
		//					between 1 and 10000.
		void setConjunto(int tam);
		// Name: getSizeC
		// param: 
		// return: int -> Returns the size of the vector conjnto.
		// What it does?: Returns the size of the vector conjunto
		int getSizeC();
		// Name: swap
		// param: i -> int. Position of the vector conjunto.
		//			j -> int. Position of the vector conjunto.
		// return: void
		// What it does?: Swap two element of the vector.
		void swap(int i, int j);
};


#endif