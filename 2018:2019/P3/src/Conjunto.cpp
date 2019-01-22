#include "Conjunto.hpp"

Conjunto::Conjunto(int tam){
	this->conjunto.resize(tam);
}

Conjunto::~Conjunto(){
	this->conjunto.clear();
}

int Conjunto::getElement(int pos){
	return this->conjunto[pos];
}

void Conjunto::setElement(int value, int pos){
	this->conjunto[pos] = value;
}

void Conjunto::deleteElement(int pos){
	this->conjunto.erase(this->conjunto.begin()+pos);
}

int Conjunto::sizeC(){
	return this->conjunto.size();
}

void Conjunto::swap(int i, int j){
	int temp;
	temp = this->conjunto[i];
	this->conjunto[i] = this->conjunto[j];
	this->conjunto[j] = temp;
}

void Conjunto::isSorted(){
	assert(is_sorted(this->conjunto.begin(), this->conjunto.end()));
	cout<<"El vector esta ordenado."<<endl;
}


