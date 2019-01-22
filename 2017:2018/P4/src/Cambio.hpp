#ifndef CAMBIO__
#define CAMBIO__

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Cambio
{
private:
	vector<int> deno; //Vector of integers that keep the minimum amount of coins to get the change
public:
	// Name: Cambio
	// param: 
	// return: void
	// What it does?: Constructor of the class Cambio
	Cambio();
	// Name: ~Cambio
	// param: 
	// return: void
	// What it does?:Destructor of the class Cambio
	~Cambio();
	// Name: setCambio
	// param: V -> int. Money that the user want to know the change
	// return: void
	// What it does?: Set the differents type of coins to get the change
	void setCambio( int V);
	// Name: getCambio
	// param: pos -> int. position of the vector.
	// return: int. Coin value
	// What it does?: Get the coin value for the change
	int getCambio(int pos);
	// Name: getSize
	// param: 
	// return: int. Number of coins used for the change
	// What it does?: Returns the number of coins that are used to get the change
	int getSize();
	// Name: showCambio
	// param: 
	// return: void
	// What it does?: Show the type of coins that are used to get the change
	void showCambio();
};

#endif