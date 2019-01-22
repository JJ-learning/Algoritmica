#include "funciones.hpp"

int getMinimo(Cambio c, int money, int tam){
	vector<int> count;
	vector<int> aux;
	vector<int> monedas;
	int pos;
	//Base case
	count.push_back(0);

	aux.resize(money +1);
	for (int i = 1; i <= money; ++i)
	{
		count.push_back(INT_MAX);
		aux[i] = INT_MAX;
	}



	for (int i = 1; i <= money; ++i)
	{
		for(int j=0; j<tam; ++j){
			if(c.getCambio(j) <= i){ //If the coin is smaller than the money asked
				int sub_ans = count[i - c.getCambio(j)]; 
				if (sub_ans != INT_MAX && sub_ans+1 < count[i])
				{
					count[i] = sub_ans + 1;
					aux[i] = c.getCambio(j);
				}
			}
		}
	}

	for (int i = 0; i < aux.size(); ++i)
	{
		cout<<aux[i]<<" ";
	}
	cout<<endl;
	int i = aux.size()-1;
	do{
		pos = aux[i];
		monedas.push_back(pos);
		i=i-pos;

		if(pos==0){
			break;
		}
	}while(i >=0 );

	cout<<"Tipo de monedas necesarias"<<endl;
	for (int i = 0; i < monedas.size(); ++i)
	{
		cout<<monedas[i]<<" ";
	}
	cout<<endl;
	return count[money];
};