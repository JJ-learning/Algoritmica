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

// ------- 	FUNCIONES MAIN -------

void combinatorioSinTabla();
void combinatorioConTabla();
void combinatorioNoRecursivo();
void hanoiMain();

// --------ADDITIONAL FUNCTIONS--------

int combinateRecursive(int n, int i);
long double combinateNoRecursive(int n, int k);
long double combinateWithTable(int n, int k, vector<vector<long double> > &table);
void hanoi(int varilla, int i, int j, long double &movement);

// ------- 	FUNCIONES AUXILIARES -------

void askParam(int &n);
void showMatrix(vector<vector<double> > matrix, int grade);
void calculateEstimatedTime(vector<double> samples, int grade, vector<vector<double> > X, vector<double> &estimatedTime);
void saveData(vector<double> samples, vector<double> realTime, vector<double> estimatedTime);
void calculateCoefDeter(vector<double> realTime, vector<double> estimatedTime);
double calculateMean(vector<double> time);
double calculateVariance(vector<double> time, double mean);
void askPrediction(vector<vector< double> > X, int grade);

// ------- 	FUNCIONES PARA RESOLVER EL SISTEMA -------

void getSolution(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &X);
void getCoefficients(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &indepedentCoef, vector<vector<double> > &dependentCoef);
void calculateDepedentCoef(vector<double> samples, int grade, vector<vector<double> > &dependentCoef);
void calculateIndepedentCoef(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &indepedentCoef);

#endif