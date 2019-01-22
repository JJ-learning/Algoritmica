#ifndef CONJUNTO__
#define CONJUNTO__

#include <iostream>
#include <vector>
#include <random>
#include <assert.h>

#include <algorithm>
#include <tgmath.h>

using namespace std;

class Conjunto
{
	private:
		vector<int> conjunto; // Vector that keeps all the random numbers of the set
	public:
		// Name: Conjunto.
		// What it does: Constructor of the class Conjunto
		Conjunto(int tam);
		// Name: ~Conjunto.
		// What it does: Destructor of the class Conjunto
		~Conjunto();
		// Name: deleteelement.
		// Input: pos. Int. Vector's position
		// Output: void
		// What it does: Delete an element of a vector with its position
		void deleteElement(int pos);
		// Name: getelement.
		// Input: pos. Int. Vector's position
		// Output: int. Returns an element
		// What it does: Gets an element of a vector with a specific position
		int getElement(int pos);
		// Name: setElement.
		// Input: value. Int. Specific value
		// Output: void
		// What it does: Insert a new value into the vector
		void setElement(int value, int pos);
		// Name: sizeC.
		// Input: void
		// Output: int. Size of the vector
		// What it does: Returns the size of the actual vector
		int sizeC();
		// Name: swap.
		// Input: i. Int. Position of the vector
		//			j. Int. Position of the vector
		// Output: void
		// What it does: Swaps two elements of the vector with the bubble method
		void swap(int i, int j);
		// Name: isSorted.
		// Input: void
		// Output: void
		// What it does: Checks if the complete vector is sorted. Otherwise it returns an assert.
		void isSorted();
};

#endif