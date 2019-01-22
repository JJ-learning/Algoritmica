#include "Conjunto.hpp"

Conjunto::Conjunto(){
}

Conjunto::~Conjunto(){
	this->conjunto.clear();
}

int Conjunto::getPosConjunto(int pos){
	return this->conjunto[pos];
}

void Conjunto::setConjunto(int tam){
	srand(time(NULL));
	int aux;
	for (int i = 0; i < tam; ++i)
	{
		aux=rand() % 10000+1;
		this->conjunto.push_back(aux);
	}
}

void Conjunto::swap(int i, int j){
	int temp;
	temp = this->conjunto[i];
	this->conjunto[i]=this->conjunto[j];
	this->conjunto[j]=temp;
}

int Conjunto::getSizeC(){
	return this->conjunto.size();
}