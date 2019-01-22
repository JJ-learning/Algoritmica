#ifndef MONEDAS__
#define MONEDAS__

#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;


class Monedas
{
private:
    vector<int> monedas;// Vector that keeps the type of coins used
public:
    // Name: Monedas
    // What it does: Constructor of the class Monedas. Reads all the type of coins
    // Monedas(string File);
    Monedas();
    // Name: ~Monedas
    // What it does: Destructor of the class Monedas. Deletes the bag
    ~Monedas();
    
    // Observadores
    
    // Name: getCambio.
    // Input: pos. int. Position of the vector
    // Output: int. Coins value
    // What it does: Returns the coins of a specific position
    int getCambio(int pos);
    // Name: sizeC
    // Input: pos. int. Position of the vector
    // Output: int. Size of the monedas's vector
    // What it does: Returns the size of the vector
    int sizeC();
    // Name: showMonedas
    // Output: void
    // What it does: Shows the different type of coins that are available
    void showMonedas();
    // Name: setCambio
    // Input: file. string. File to save all the coins used
    // Output: void
    // What it does: Set the coins used to get the change asked to the user
    void setCambio(string file);
    // Name: readFromFile
    // Input: file. string. File to read all the coins from
    // Output: void
    // What it does: Reads the type of coins used to get the change
    void readFromFile(string file);
};
#endif
