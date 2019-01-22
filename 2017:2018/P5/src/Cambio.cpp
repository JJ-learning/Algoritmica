#include "Cambio.hpp"

Cambio::Cambio(){
}

Cambio::~Cambio(){
	this->deno.clear();
}

void Cambio::showCambio(){
	cout<<"\nMonedas/billetes en centimos disponibles para cambio:"<<endl;
	for (int i = 0; i < this->deno.size(); ++i)
	{
		cout<<this->deno[i]<<" ";
	}
	cout<<endl;
}

void Cambio::setCambio(int V){
	this->deno.push_back(V);
}

int Cambio::getCambio(int pos){
	return this->deno[pos];
}

int Cambio::getSize(){
	return this->deno.size();
}