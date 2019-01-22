#include "funciones.hpp"

void heapFunction(){
	int min, max, inc, rep; 
	int n; //Vector's size
	vector <int> V;
	vector <double> realTime;//Track the real time that the funcition takes to sort the vector
	vector <double> estimatedTime; //traks the estimated time that the function takes to sort the vector
	vector <vector <double> > coefficients; //Matrix that keeps the coefficients
	vector <vector <double> > independetCoef; //Matrix that keeps the independent coefficient 
	vector < vector < double > > X; //Matrix with the solution of the equations
	vector<double> samples_copy, samples;
	Clock time;
	double aux = 0.0, estimation = -1;
	int grade;
	string file = "times.txt";
	
	askParam(min, max, inc, rep);
				
	for (int i = min; i <=max; i=inc+i)
	{
		for (int j = 0; j < rep; ++j)
		{
			fillVector(V, i);
			//If we wanna see the vector unsorted, do it here
			time.start();
			
		 	heapSort(V);
		 	
			if(time.isStarted()){
				time.stop();
				aux += time.elapsed();
				//If we wanna see the vector sorted, do it here
			}
		}

		samples.push_back(i);
		realTime.push_back(aux/rep);
		isSorted(V);
		aux = 0.0;//Reset the summatory
	}

	//Reserve matrices
	grade=2;
	coefficients = vector<vector<double> >(grade, vector<double> (grade));
	independetCoef = vector<vector<double> >(grade, vector<double>(1));
	X = vector<vector<double> >(grade, vector<double> (1));
	
	//We calculate the samples*log(samples)
	samples_copy = samples;
	for (int i = 0; i < samples.size(); ++i)
	{
		samples_copy[i] = samples[i] * log10(samples[i]);
	}

	calculateCoef(samples_copy, realTime, coefficients, independetCoef, grade);
	cout<<"\n\tMatriz de coeficientes: "<<endl;
	for (int i = 0; i < grade; ++i)
	{
		for (int j = 0; j < grade; ++j)
		{
			cout<<"a"<<j<<" "<<coefficients[i][j];
			if(j < grade-1){
				cout<<" + ";
			}
		}
		cout<<" = "<< independetCoef[i][0]<<endl;
	}

	resolverSistemaEcuaciones(coefficients, independetCoef, grade, X);
	
	cout<<"\n\tSolucion: "<<endl;
	for (int i = 0; i < grade; ++i)
	{					
			cout<<X[i][0]<<"a^"<<i;
			if(i < grade-1)
				cout<<" + ";					
	}
	cout<<endl;	

	aux = 0.0;
	for (int i = 0; i < samples.size(); ++i)
	{
		aux = X[0][0] + X[1][0] * samples[i] * log10(samples[i]);		
		estimatedTime.push_back(aux);
		aux=0.0;
	}

	
	cout<< "Vector sorted and times saved"<<endl;
	saveData(samples, realTime, estimatedTime, file);

	calculateCoefDeter(realTime, estimatedTime);
	aux=0.0;
	do{
		do{
			cout<<"\t¿Valor que desea estimar?: ";
			cin >> estimation;
		}while(estimation < 0);
		if (estimation != 0)
		{
			aux = X[0][0] + X[1][0]*estimation*log10(estimation);
			aux = abs(aux)/1000000.0/(60*60*24); //Pass the estimation into day format
			cout<<"\n\tEl tiempo estimado en dias es: "<<aux<<endl;
		}
	}while(estimation != 0);

	//Free data
	samples.clear();
	realTime.clear();
	estimatedTime.clear();
	for (int i = 0; i < grade; ++i)
	{
		coefficients[i].clear();
	}
	coefficients.clear();
	independetCoef.clear();
	X.clear();
};

void bubbleFunction(){
	int min, max, inc, rep; 
	int n; //Vector's size
	vector <int> V;
	vector <double> samples;
	vector <double> realTime;//Track the real time that the funcition takes to sort the vector
	vector <double> estimatedTime; //traks the estimated time that the function takes to sort the vector
	vector <vector <double> > coefficients; //Matrix that keeps the coefficients
	vector <vector <double> > independetCoef; //Matrix that keeps the independent coefficient 
	vector < vector < double > > X; //Matrix with the solution of the equations
	Clock time;
	double aux = 0.0, estimation = -1;
	int grade;
	string file = "times.txt";

	askParam(min, max, inc, rep);
				
	for (int i = min; i <=max; i=inc+i)
	{
		for (int j = 0; j < rep; ++j)
		{
			fillVector(V, i);
			//If we wanna see the vector unsorted, do it here
			time.start();

			bubbleMethod(V);

			if(time.isStarted()){
				time.stop();
				aux += time.elapsed();
				//If we wanna see the vector sorted, do it here
			}
		}

		samples.push_back(i);
		realTime.push_back(aux/rep);
		isSorted(V);
		aux = 0.0;//Reset the summatory
	}

	//Reserve matrices
	grade=3;
	coefficients = vector<vector<double> >(grade, vector<double> (grade));
	independetCoef = vector<vector<double> >(grade, vector<double>(1));
	X = vector<vector<double> >(grade, vector<double> (1));
	
	
	calculateCoef(samples, realTime, coefficients, independetCoef, grade);	
	
	cout<<"\n\tMatriz de coeficientes: "<<endl;
	for (int i = 0; i < grade; ++i)
	{
		for (int j = 0; j < grade; ++j)
		{
			cout<<"a"<<j<<" "<<coefficients[i][j];
			if(j < grade-1){
				cout<<" + ";
			}
		}
		cout<<" = "<< independetCoef[i][0]<<endl;
	}

	

	resolverSistemaEcuaciones(coefficients, independetCoef, grade, X);
	
	cout<<"\n\tSolucion: "<<endl;
	for (int i = 0; i < grade; ++i)
	{					
			cout<<X[i][0]<<"x^"<<i;
			if(i < grade-1)
				cout<<" + ";					
	}
	cout<<endl;	

	aux=0.0;
	for (int i = 0; i < samples.size(); ++i)
	{	
		for (int j = 0; j < grade; ++j)
		{
			aux += X[j][0]*pow(samples[i],j);
		}
		estimatedTime.push_back(aux);
		aux = 0.0;
	}
	
	calculateCoefDeter(realTime, estimatedTime);

	cout<< "\n\tVector sorted and times saved"<<endl;
	saveData(samples, realTime, estimatedTime, file);

	aux=0.0;
	do{
		do{
			cout<<"\t¿Valor que desea estimar?: ";
			cin >> estimation;
		}while(estimation < 0);
		if (estimation != 0)
		{
			for (int j = 0; j < grade; ++j)
			{
				aux += X[j][0]*pow(estimation,j);
			}
			aux = abs(aux)/1000000.0/(60*60*24); //Pass the estimation into day format
			cout<<"\n\tEl tiempo estimado en dias es: "<<aux<<endl;
		}
	}while(estimation != 0);

	//Free data
	samples.clear();
	realTime.clear();
	estimatedTime.clear();
	for (int i = 0; i < grade; ++i)
	{
		coefficients[i].clear();
	}
	coefficients.clear();
	independetCoef.clear();
	X.clear();
};

double calculateMean(vector<double> times){
	double aux = 0.0;
	double mean = 0.0;
	for(int i=0; i<times.size(); i++){
		aux += times[i];
	}
	mean = aux/times.size();

	return mean;
}

double calculateVariance(vector<double> times, double mean){
	double variance = 0.0;
	double aux = 0.0;

	for(int i=0; i<times.size(); i++){
		aux += pow((times[i]-mean), 2);
	}

	variance = aux/times.size();

	return variance;
}

void calculateCoefDeter(vector<double> realTime, vector<double> estimatedTime){
	double real_mean = calculateMean(realTime);
	double estimated_mean = calculateMean(estimatedTime);

	double real_variance = calculateVariance(realTime, real_mean);
	double estimated_variance = calculateVariance(estimatedTime, estimated_mean);

	cout<<"El coeficiente de determinacion es: "<<(estimated_variance/real_variance)<<endl;
};

void fillVector(vector<int> &V, int n){
	//Clears the vector in order to get another random number in the next iteration
	V.clear();
	for (int i = 0; i < n; ++i)
	{
		V.push_back(rand() % 9999) ;
	}
};

void askParam(int &min, int &max, int &inc, int &rep){
	cout<< "\tValor minimo del vector: ";
	cin>>min;
	if(min<=0){
		cout<<"Error! El minimo debe ser mayor que 0"<<endl;
		exit(-1);
	}

	cout<< "\tValor maximo del vector: ";
	cin>>max;
	if(max < min){
		cout<<"Error! El maximo no puede ser mayor que el minimo"<<endl;
		exit(-1);
	}

	cout<< "\tValor del incremento: ";
	cin>>inc;
	if(inc<=0){
		cout<<"Error! El incremento debe ser mayor que 0"<<endl;
		exit(-1);
	}

	cout<<"\tNumero de repeticiones: ";
	cin>>rep;
	if(rep<=0){
		cout<<"Error! El número de repeticiones debe ser mayor que 0"<<endl;
		exit(-1);
	}
};

void showMatrix(vector<vector<double> > M, int size){
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
};

void calculateDepedentCoef(vector<double> samples, int grade, vector<vector<double> > &coeff){
	// TODO
	double aux=0.0;
	for(int i=0; i<grade; i++){
		for(int j=0; j<grade; j++){
			if(i==0 && j == 0){
				coeff[i][j] = samples.size();
			}else{
				for(int k=0; k<samples.size(); k++){
					aux += pow(samples[k], i+j);
				}
				coeff[i][j] =aux;
				aux = 0.0;
			}
		}
	}
}

void calculateIndependetCoeff(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &coeff){
	// TODO
	double aux = 0.0;
	for(int i=0; i<grade; i++){
		for(int j=0; j<samples.size(); j++){
			aux += pow(samples[j], i) * realTime[j];
		}
		coeff[i][0] = aux;
		aux = 0.0;
	}
}

void calculateCoef(vector <double> samples, vector<double> realTime, vector<vector<double> > &coefficients, vector<vector<double> > &indepedentCoef, int grade){
	calculateDepedentCoef(samples, grade, coefficients);
	calculateIndependetCoeff(samples, realTime, grade, indepedentCoef);
};

void saveData(vector<double> samples, vector<double> realTime, vector<double> estimatedTime, string file){
	ofstream outputFile(file.c_str());
	for (int i = 0; i < realTime.size(); ++i)
	{
		outputFile << samples[i] <<" "<< realTime[i]<<" "<<estimatedTime[i]<<endl;
	}
	outputFile.close();
};

void isSorted(vector<int> V){
	assert(is_sorted(V.begin(), V.end()));
};

void swap(int *left, int *right){
	// TODO
	int temp = *right;
	*right = *left;
	*left = temp;
};

void bubbleMethod(vector <int> &V){
	// TODO
	for(int i=0; i<V.size()-1; i++){
		for(int j=0; j<V.size()-i-1; j++){
			if(V[j] > V[j+1]){
				swap(&V[j], &V[j+1]);
			}
		}
	}
};

void reorderHeap(vector<int> &V, int size, int i){
	// TODO
	int greatest = i;
	int l=2*i+1;
	int r=2*i+2;

	if(l<size && V[l] > V[greatest]){
		greatest = l;
	}
	if(r<size && V[r] > V[greatest]){
		greatest = r;
	}

	if(greatest != i){
		swap(&V[i], &V[greatest]);
		reorderHeap(V, size, greatest);
	}
};

void heapSort(vector<int> &V){
	// TODO
	for(int i=(V.size()/2)-1; i>=0; i--){
		reorderHeap(V, V.size(), i);
	}
	for(int i=V.size()-1; i>=0; i--){
		swap(&V[0], &V[i]);
		reorderHeap(V, i, 0);
	}
};