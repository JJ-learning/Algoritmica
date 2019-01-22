#ifndef __Chess_H__
#define __Chess_H__

#include <iostream>
#include <vector>

using namespace std;

//Class Chess to use to calculates the path of a pawn
class Chess{
	private:
		int coordenates[2]; //Final coordenates of the pawn
		vector<vector<int> > adj; //Adjacency matrix for set the possible paths
	public:
		// Name: Chess
		// param: row_final -> int. Final row of the pawn
		//			col_final -> int. Final col of the pawn
		// return: void
		// What it does?: Se the last coordenate of the pawn.
		Chess(int row_final, int col_final);

		// Name: addEdge
		// param: row_begin -> int. Initial row of the pawn
		//			col_begin -> int. Iinal col of the pawn
		//			opt -> char. Set the option of the program
		// return: void
		// What it does?: Set the possible path of the pawn and create a matrix simulating a graph.
		void addEdge(int row_begin, int col_begin, char opt);

		// Name: addEdge
		// param: M -> vector<vector<int>>. Matrix to show
		// return: void
		// What it does?: Show a matrix into the screen.
		void showMatrix(vector<vector<int> > M);

		// Name: addEdge
		// param: u -> int. Initial position of the pawn
		// 			d -> int. Final position of the pawn
		// 			conected -> vector<bool>. Keeps the conected nodes of the graph
		//			pathCount -> int. Number of paths.
		// return: void
		// What it does?: Show the node rute that has to follow to find a solution
		void showPath(int u, int d, vector<bool> conected, int &pahtCount);
		

};
#endif
