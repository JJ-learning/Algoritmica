#include "funciones.hpp"

void fillConjunto(Conjunto &C, int tam){
	for (int i = 0; i < tam; ++i)
	{
		C.setElement((rand()%10000)+1, i);
	}
};

bool isInSet( Conjunto k,int value){
	bool inside=false;
	for(int i=0; i < k.sizeC(); i++){
		if(k.getElement(i) == value){
			inside=true;
		}
	}
	return inside;
};

void showSet(Conjunto C){
	for(int i=0; i < C.sizeC();i++){
		cout<<C.getElement(i)<<" ";
	}
};

void askUser(Conjunto C, int k, Conjunto ksmallest){
	char ans;
	
	cout<<"\n\t¿Quiere ver los k menores del vector? (y/Y-n/N): ";
	cin >> ans;
	if(ans == 'y' || ans == 'Y'){
		cout<<"El vector entero es: ";
		showSet(ksmallest);
		cout<<"---> ";
		for(int i = 0; i < C.sizeC(); i++){
			if(isInSet(ksmallest , C.getElement(i)) == false){
				cout<<C.getElement(i)<<" ";
			}
		}
		cout<<endl;
	}
};

void getSmallest(int begin, int end, int k, Conjunto C, Conjunto &ksmallest, int &numIt){
	// TODO
	int i=begin;
	int j=end;
	int mid = C.getElement((begin+end)/2);

	do{
		while(C.getElement(i) < mid){
			i++;
		}
		while(C.getElement(j) > mid){
			j--;
		}
		if(i<=j){
			C.swap(i,j);
			i++;
			j--;
		}
	}while(i<=j);

	if(k==i){
		for(int l=0; l<k; l++){
			ksmallest.setElement(C.getElement(l), l);
		}
	}else{
		if(k<i){
			numIt++;
			getSmallest(begin, j, k, C, ksmallest, numIt);
		}else{
			numIt++;
			getSmallest(i, end, k, C, ksmallest, numIt);
		}
	}
};

void getkSmallest(){
	int tam = 0;
	int numIt = 0;
	int k;
	srand(time(NULL));

	cout<<"Introduzca el tamaño del conjunto: ";
	cin >> tam;
	cout<<"Introduzca el valor de k: ";
	cin >> k;

	Conjunto C(tam);
	Conjunto ksmallest(k);
	fillConjunto(C, tam);

	int begin = 0;
	int end = C.sizeC()-1;

	getSmallest(begin, end, k, C, ksmallest, numIt);

	cout<<"los K menores son: ";
	showSet(ksmallest);
	cout<<"El numero minimo de llamadas han sido: "<<numIt;

	askUser(C, k, ksmallest);
};




