#include "Chess.hpp"

Chess::Chess(int row_final, int col_final){
	this->coordenates[0] = row_final; 
	this->coordenates[1] = col_final;
	for (int k = 0; k < 64; ++k)
	{
		vector<int> aux;
		for (int i = 0; i < 64; ++i)
		{
			aux.push_back(0);
		}
		this->adj.push_back(aux);
	}	
}

void Chess::showMatrix(vector<vector<int> > M){
	for (int i = 0; i < M.size(); ++i)
	{
		for(int j=0; j<M.size();++j){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Chess::showPath(int u, int d, vector<bool> connected, int &pahtCount){
	connected[u] = true;
	//Reaches the final node
	if(u==d){
		pahtCount++;
		cout<<"Camino: ";
		for (int i = 0; i < connected.size(); ++i)
		{
			if (connected[i] == true)
			{
				cout<<i <<" ";			
			}
		}
		cout<<endl;
	}
	else{
		int i;
		for (i = u; i < this->adj[u].size(); ++i)
		{
			if(adj[u][i] == 1){				
				showPath(i, d, connected, pahtCount);
			}
		}
	}
	connected[u]=false;
}

void Chess::addEdge(int row_begin, int col_begin, char opt){
	int nodo=0;
	int u;
	vector<int> d;
	int row_final = this->coordenates[0];
	int col_final = this->coordenates[1];
	vector<bool> connected;
	int pahtCount=0;
	vector<vector<int> > nodesMatrix;

	//Create the adjacency matrix
	for (int i = 0; i < 8; ++i){
		for(int j=0; j < 8; ++j){
			if(nodo<56){
				if(j-1>=0 && i+1<8){ //Moves left&ford
					this->adj[nodo][nodo+7] = 1;					
				}
				if(i+1<8){ //Moves forward
					this->adj[nodo][nodo+8]= 1;
				}
				if(j+1<8 && i+1<8){ //Moves rigth&forward
					this->adj[nodo][nodo+9] = 1;
				}
				if (i==1 && i+2<8){ //Moves to forward
					this->adj[nodo][nodo+16] =1;
				}
				nodo++;
			}
		}
	}

	// Initialize the nodeMatrix
	// Create another matrix to keep tracking of the node and its
	// coordinates
	for (int k = 0; k < 8; ++k)
	{
		vector<int> aux;
		for (int i = 0; i < 8; ++i)
		{
			aux.push_back(0);
		}
		nodesMatrix.push_back(aux);
	}	
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if(i==0){
				nodesMatrix[i][j]=j;
			}
			if(i>=1){
				nodesMatrix[i][j]=(8*i)+j;
			}
		}
	}
	
	//Set the final position
	switch(opt){
		case '1':{	
			u = nodesMatrix[row_begin][col_begin];
			d.push_back(nodesMatrix[row_final][col_final]);
		break;
		}
		case '2':{
			cout<<"nodos finales:";
			u = nodesMatrix[row_begin][col_begin];
			for (int i = 0; i < 8; ++i)
			{
				d.push_back(nodesMatrix[7][i]);
				cout<<d[i];
			}
			cout<<endl;
		break;
		}
		case '3':{
			cout<<"nodos finales:";
			u = nodesMatrix[row_begin][col_begin];
			for (int i = 0; i < 8; ++i)
			{
				d.push_back(nodesMatrix[7][i]);
				cout<<d[i];
			}
			cout<<endl;
		break;
		}/*
		case '4':{
			cout<<"nodos finales:";
			u = nodesMatrix[row_begin][col_begin];
			for (int i = 0; i < 8; ++i)
			{
				d.push_back(nodesMatrix[7][i]);
				cout<<d[i];
			}
			cout<<endl;
		break;
		}*/
	}
	
	//Initializes the connected vector to false
	for (int i = 0; i < 64; ++i)
	{
		connected.push_back(false);
	}
	
	//Show path	
	for (int i = 0; i < d.size(); ++i)
	{
		showPath(u, d[i], connected, pahtCount);
	}
	
	if(pahtCount==0){
			cout<<"No existen caminos posibles."<<endl;
	}
	else{
		cout<<"Número de caminos: "<<pahtCount<<endl;
	}
}