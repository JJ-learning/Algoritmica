#include "funciones.hpp"

void getMinimo(Cambio c, int money){
	vector<int> ans; //Vector that keeps the change

	for (int i = c.getSize()-1; i >=0; --i)
	{
		//While the money asked is bigget that the coin
		while(money >= c.getCambio(i)){
			//Extract the amount of change used
			money -= c.getCambio(i);
			//Save the type of coin used
			ans.push_back(c.getCambio(i));
		}
	}

	//Show the result
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
};