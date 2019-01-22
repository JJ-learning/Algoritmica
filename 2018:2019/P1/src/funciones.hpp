#ifndef FUNCIONES__
#define FUNCIONES__

#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <tgmath.h>
#include "ClaseTiempo.cpp"
#include "sistemaEcuaciones.hpp"

using namespace std;

// --------MAIN FUNCTIONS--------

// Name: bubbleFunction.
// Input:
// Output: void
// What it does: It sorts a vector of different sizes with the bubble method
void bubbleFunction();

// Name: heapFunction.
// Input: 
// Output: void
// What it does: It sorts a vector of different sizes with the heap method
void heapFunction();


// --------ADDITIONAL FUNCTIONS--------

// Name: aksParam.
// Input: min. int. Minimum size of the vector
//			max. int. Maximum size of the vector
//			inc. int. Size of the increment
//			rep. int. Number of repetitions
// Output: void
// What it does: Asks for the initial variables needed to see how many iterations we are gonna do.
void askParam(int &min, int &max, int &inc, int &rep);

// Name: fillVector.
// Input: V. vector<int>. Vector that keeps the random numbers
//			n. int. Size of the vector
// Output: void
// What it does: It fills a vector with n random numbers
void fillVector(vector<int> &V, int n);

// Name: bubbleMethod.
// Input: V. vector<int>. Keeps the element of a vector
// Output: void
// What it does: Apply the bubble method in order to sort a specific vector.
void bubbleMethod(vector<int> &V);

// Name: swap.
// Input: left. int. An element of a vector
//			right. int. An element of a vector
// Output: void
// What it does: Swaps two element of a vector.
void swap(int *left, int *rigth);

// Name: saveData.
// Input: samples. vector<double>. Keeps the size of the vector on each iteration
//			realTime. vector<double>. Vector within the real time.
//			estimatedTime. vector<double>. Vector within the estimated time.
//			file. string. String with the name of the file
// Output: void
// What it does: Saves the size, real time and estimated time of the algorithm.
void saveData(vector<double> samples, vector<double> realTime, vector<double> estimatedTime, string file);

// Name: isSorted.
// Input: V. vector<int>. Keeps the elements of a vector
// Output: void
// What it does: Cheks if a vector is sorted or not.
void isSorted(vector<int> V);

// Name: heapSort.
// Input: V. vector<int>. Keeps the element of a vector
// Output: void
// What it does: Applies the heap sort method in order to sort a vector
void heapSort(vector<int> &V);

// Name: reorderHeap.
// Input: V. vector<int>. Keeps the element of a vector
// 			size. int. Size of the vector.
// 			i. int. The first node of the vector
// Output: void
// What it does: It reorders the tree leaving the greatest element on top.
void reorderHeap(vector<int> &V, int size, int i);

// Name: calculateCoef.
// Input: samples. vector<double>. Keeps the size of the vector on each iteration
//			realTime. vector<double>. Vector within the real time.
//			estimatedTime. vector<double>. Vector within the estimated time.
//			coefficients. vector<vector<double>>. Matrix that keeps the coefficient matrix
//			indepedentCoef. vector<vector<double>>. Keeps the independent coefficients of the equations system.
//			grade. int. Grade of the equations system.
// Output: void
// What it does: Calculates the determinant and independet coefficient of a equations system of specified grade.
void calculateCoef(vector <double> samples, vector<double> realTime, vector<vector<double> > &coefficients, vector<vector<double> > &indepedentCoef, int grade);
void calculateDepedentCoef(vector<double> samples, int grade, vector<vector<double> > &coeff);
void calculateIndependetCoeff(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &coeff);
double calculateMean(vector<double> times);

// Name: showMatrix.
// Input: M. vector<vector<double>>. Matrix to show
//			size. int. Size of the matrix
// Output: void
// What it does: It shows a matrix out.
void showMatrix(vector<vector<double> > M, int size);

// Name: calculateCoefDeter.
// Input: realTime. vector<double>. Vector within the real time.
//			estimatedTime. vector<double>. Vector within the estimated time.
// Output: void
// What it does: It calculates the determination coefficient.
void calculateCoefDeter(vector<double> realTime, vector<double> estimatedTime);

#endif