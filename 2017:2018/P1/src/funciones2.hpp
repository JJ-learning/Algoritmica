#ifndef FUNCIONES2_HPP
#define FUNCIONES2_HPP

#include "ClaseTiempo.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>


using namespace std;


// Name: getFibonacci
// param: min -> int. Minimum's itetarion.
// 		max -> int. Maximum's iteration.
// 		inc -> int. Increment's iteration.
// return: void
// What it does?: It calculates the curve that real and estimated time that take to run the Fibonacci algorithm
//					in a recursively way.
void getFibonacci(int min, int max, int inc);

// Name: reserveMatrix
// param: size -> Integer that keeps the size of the matrix
// return: double** -> Return a matrix with the size reserved
// What it does?: Reserves a matrix with a recieved data
double **reserveMatrix( int size);

// Name: finbonacci
// param: i -> number to calculate the fibonacci result
// return: int -> Return the fibonacci serie of i
// What it does?: It calculates the fibonacci's serie in a recursively way
int fibonacci(int i);

// Name: showMatrix
// param: M-> double**. Matrix to show
// 		rows-> int. Number of matrix's rows
// 		cols-> int. Number of matrix's columns
// return: void
// What it does?: Show the recieved matrix void calculateCoefficients(double **info_data, vector<double> &coefficients, int num_samples);
void showMatrix(double **M, int rows, int cols);

// Name: keepData
// param: samples -> vector<double>. Vector that keeps the number of samples
// 		realTime -> vector<double>. Vector that keeps the real time used by each sample
// 		realTime -> vector<double>. Vector that keeps the estimated time used by each sample
// 		file -> string. String that keeps the name of the name used to write on.
// return: void
// What it does?: Copies into a file the id, real time and estimated time.
void keepData(vector<double> samples, vector<double> realTime, vector<double> estimatedTime, string file);

// Name: calculateCoefficients
// param: info_data -> double**. Matrix that keeps the n, real time and the value of n^2
// 		coefficients -> vector<double>. Vector that keeps the coefficients to get the curve.
// 		num_samples -> int. Number of samples used 
// return: void
// What it does?: It calculates the coefficients a0 and a1 of the curve f(x)=a0+a1z; z=n^2 
void calculateCoefficients(double **info_data, vector<double> &coefficients, int num_samples);

// Name: fillMatrix
// param: info_data -> double**. Matrix that keeps the random matrix.
// 			grade -> int. Size of the random matrix
// return: void
// What it does?: Fills a matrix with random number between 1-10
void fillMatrix(double **M, int grade);

// Name: getFibonacci
// param: min -> int. Minimum's itetarion.
// 		max -> int. Maximum's iteration.
// 		inc -> int. Increment's iteration.
// return: void
// What it does?: It calculates the curve that real and estimated time that take to get the determinant of a nxn matrix.
void getDeterminante(int min, int max, int inc);

// Name: calculateSubMatrix
// param: M -> double**. Matrix that keeps the submatrix
//			grade -> int. Size of the matrix
//			row -> int. Row of the position recieved.
//			col -> int. Column of the position recieved.
// return: double -> Return the determinat of the matrix recieved.
// What it does?: Calculates the cofactor of the matrix in each column in order to get the determinant of it
double calculateSubMatrix(double **M, int grade, int row, int col);

// Name: calculateDeter
// param: M -> double**. Matrix that keeps the submatrix
//			grade -> int. Size of the matrix
// return: double -> Return the determinat of the matrix recieved.
// What it does?: First, calculates the cofactors of the matrix in order to get 2X2 matrix and then multiply them by the cofactors.
double calculateDeter(double **M, int grade);

// Name: fatorial
// param: estimacion -> double. Number of estimation.
// return: double -> return the factorial of the estimation.
// What it does?: It calculates the factorial of a number.
double factorial(double estimation);

#endif