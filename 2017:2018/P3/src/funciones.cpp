#include "funciones.hpp"

int divide( int start, int end, Conjunto &C){
	int pivot = C.getPosConjunto(end);
	int temp;
	int i = start-1;
	for (int j = start; j < end; ++j)
	{
		if(C.getPosConjunto(j) <= pivot){
			i++;
			C.swap(i,j);
		}
	}

	C.swap(i+1, end);

	return i+1;
};

void quicksort( int start, int end, int &numIt, Conjunto &C){
	int pivot;
	if(start<end){
		pivot = divide(start, end, C);
		numIt++;
		quicksort(start, pivot-1, numIt, C);
		quicksort(pivot+1, end, numIt, C);
	}
};

void kmenores(Conjunto C, int k){
	int numIt=0; //Number of iterations
	char ans; //Auxiliar variable

	//Get the vector/set sorted
	quicksort(0, C.getSizeC()-1, numIt, C);

	//Show the k-smallest
	cout<<k<<" menores: ";
	for (int i = 0; i < k; ++i)
	{
		cout<<C.getPosConjunto(i)<<" ";
	}
	cout<<endl;

	cout<<"Numero de iteraciones: "<<numIt<<endl;

	//Asks tp show the complete vector
	cout<<"¿Quiere ver el vector ordenado de tamaño"<<C.getSizeC()<<"?(y/Y-n/N)";
	cin>>ans;
	if(ans == 'y' || ans=='Y'){
		for (int i = 0; i < C.getSizeC(); ++i)
		{
			cout<<C.getPosConjunto(i)<<" ";
		}
		cout<<endl;
	}
};
