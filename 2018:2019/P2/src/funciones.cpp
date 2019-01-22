#include "funciones.hpp"

// ------- 	FUNCIONES MAIN -------
//  2^n
void combinatorioSinTabla(){
	int n, k;
	int solution = 0;
	int grade;
	double aux = 0.0;
	vector<double> samples;
	vector<double> samples2;
	vector<double> realTime;
	vector<double> estimatedTime;
	vector< vector<double> > X;

	Clock time;

	askParam(n);

	for (int i = 1; i <= n; ++i)
	{
		time.start();
		
	
		solution = combinateRecursive(n, i);
	
		cout<<"La solución de "<<n<<" sobre "<<i<<" es: "<<solution<<endl;
	
		if(time.isStarted()){
			time.stop();
			samples.push_back(i);
			realTime.push_back(time.elapsed());
		}
	}

	grade = 2;
	// Reseve space for solution
	X = vector<vector<double> >(grade, vector<double>(1));
	for (int i = 0; i < samples.size(); ++i)
	{	
		samples2.push_back(pow(2, samples[i]));
	}
	getSolution(samples2, realTime, grade, X);

	cout<<"\tSolucion del sistema: "<<endl;
	cout<<"Y = "<<X[0][0]<<" + "<<X[1][0]<<"X"<<endl;

	//calculateEstimatedTime(samples2, grade, X, estimatedTime);
	for(int i=0; i<samples.size(); i++){
		aux = 0.0;
		aux = X[0][0] + (X[1][0] * pow(2, samples[i]));
		estimatedTime.push_back(aux);
	}
	saveData(samples, realTime, estimatedTime);

	cout<<"\t Coeficiente de determinacion: ";
	calculateCoefDeter(realTime, estimatedTime);

	askPrediction(X, grade);
};

// tercer grado
void combinatorioConTabla(){
	int n, k;
	long double solution = 0;
	int grade;
	double aux = 0.0;
	vector<double> samples;
	vector<double> realTime;
	vector<double> estimatedTime;
	vector< vector<double> > X;
	vector< vector<long double> > table;
	Clock time;

	askParam(n);
	
	for (int i = 1; i <= n; ++i)
	{
		table = vector<vector<long double> >(n+1, vector<long double>(n+1, 0));
		time.start();
		
		
		solution = combinateWithTable(n, i, table);
	
		cout<<"La solución de "<<n<<" sobre "<<i<<" es: "<<solution<<endl;

		if(time.isStarted()){
			time.stop();
			samples.push_back(i);
			realTime.push_back(time.elapsed());
		}
	}

	grade = 3;
	// Reseve space for solution
	X = vector<vector<double> >(grade, vector<double>(1));
	getSolution(samples, realTime, grade, X);

	cout<<"\tSolucion del sistema: "<<endl;
	showMatrix(X, grade);

	calculateEstimatedTime(samples, grade, X, estimatedTime);

	saveData(samples, realTime, estimatedTime);

	cout<<"\t Coeficiente de determinacion: ";
	calculateCoefDeter(realTime, estimatedTime);

	askPrediction(X, grade);
};

// Tercer grado
void combinatorioNoRecursivo(){
	int n, k;
	long double solution = 0;
	int grade;
	double aux = 0.0;
	vector<double> samples;
	vector<double> realTime;
	vector<double> estimatedTime;
	vector< vector<double> > X;

	Clock time;

	askParam(n);

	for (int i = 1; i <= n; ++i)
	{
		time.start();
		
		solution = combinateNoRecursive(n, i);
	
		cout<<"La solución de "<<n<<" sobre "<<i<<" es: "<<solution<<endl;
		if(time.isStarted()){
			time.stop();
			samples.push_back(i);
			realTime.push_back(time.elapsed());
		}
	}

	grade = 3;
	// Reseve space for solution
	X = vector<vector<double> >(grade, vector<double>(1));
	getSolution(samples, realTime, grade, X);

	cout<<"\tSolucion del sistema: "<<endl;
	showMatrix(X, grade);

	calculateEstimatedTime(samples, grade, X, estimatedTime);

	saveData(samples, realTime, estimatedTime);

	cout<<"\t Coeficiente de determinacion: ";
	calculateCoefDeter(realTime, estimatedTime);

	askPrediction(X, grade);
};

// 2^n
void hanoiMain(){
	Clock time;
	int discos;
	long double movement = 0;
	int grade;
	vector<double> samples;
	vector<double> samples2;
	vector<double> realTime;
	vector<double> estimatedTime;
	vector< vector<double> > X;

	cout<<"\tIntroduzca el numero de discos: ";
	cin >> discos;
	if(discos<3){
		cout<<"Error! El numero de discos ha de ser mayor o igual que tres"<<endl;
		exit(-1);
	}

	for (int i = 3; i <= discos; ++i)
	{
		time.start();
		hanoi(i, 1, 2, movement);
		if(time.isStarted()){
			time.stop();
			samples.push_back(i);
			realTime.push_back(time.elapsed());
			cout<<"Numero de movimientos con "<<i<<" discos: "<<movement<<endl;
		}
	}

	grade = 2;
	// Reseve space for solution
	X = vector<vector<double> >(grade, vector<double>(1));
	for (int i = 0; i < samples.size(); ++i)
	{
		samples2.push_back(pow(2, samples[i]));
	}
	getSolution(samples2, realTime, grade, X);

	cout<<"\tSolucion del sistema: "<<endl;
	showMatrix(X, grade);

	calculateEstimatedTime(samples2, grade, X, estimatedTime);

	saveData(samples, realTime, estimatedTime);

	cout<<"\t Coeficiente de determinacion: ";
	calculateCoefDeter(realTime, estimatedTime);

	askPrediction(X, grade);
};
// ------- 	FIN FUNCIONES MAIN -------


// ------- 	FUNCIONES AUXILIARES -------

void askPrediction(vector<vector< double> > X, int grade){
	double aux = 0.0, estimation = -1;
	int segundos_dia = 86400;
	int segundos_hora = 3600;
	int segundos_minuto = 60;
	int aux2;
	long double dias = 0, horas = 0, minutos = 0, segundos = 0, anios = 0;
	do{
		do{
			cout<<"\t¿Valor que desea estimar?";
			cin >> estimation;
		}while(estimation < 0);
		aux = 0;
		if(estimation != 0){
			for (int i = 0; i < grade; ++i)
			{
				aux += X[i][0] * pow(estimation, i);
			}
			aux = abs(aux)/1000000.0/(60*60*24);
			cout<<"\t El tiempo estimado en dias es: "<<aux<<endl;			

		}
	}while(estimation != 0);
}

void hanoi(int varilla, int i, int j, long double &movement){
	// TODO
	if(varilla > 0){
		hanoi(varilla-1, i, 6-i-j, movement);
		movement++;
		j=i;
		hanoi(varilla-1, 6-i-j, j, movement);
	}
};

long double combinateWithTable(int n, int k, vector<vector<long double> > &table){
	// TODO
	if(k==0 || k==n){
		table[n][k] = 1;
		return 1;
	}else{
		if(table[n][k] > 0){
			return table[n][k];
		}else{
			long double result = combinateWithTable(n-1, k-1, table) + combinateWithTable(n-1, k, table);
			table[n][k] = result;
			return result;
		}
	}
};

void saveData(vector<double> samples, vector<double> realTime, vector<double> estimatedTime){
	string file="times.txt";
	ofstream outFile(file.c_str());
	for (int i = 0; i < realTime.size(); ++i)
	{
		outFile << samples[i] << " " << realTime[i] << " " << estimatedTime[i] << endl;
	}
	outFile.close();
};

long double combinateNoRecursive(int n, int k){
	// TODO
	long double aux=n;
	long double sumatory=1;

	if(k==0 || k==n){
		return 1;
	}else{
		for(int i=n-1; i>k; i--){
			aux*=i;
		}
		for(int i=2; i<=n-k; i++){
			sumatory*=i;
		}
		return aux/sumatory;
	}
};

int combinateRecursive(int n, int k){
	//TODO
	if(k==0 || k==n){
		return 1;
	}else{
		return combinateRecursive(n-1, k-1) + combinateRecursive(n-1, k);
	}
};

void calculateEstimatedTime(vector<double> samples, int grade, vector<vector<double> > X, vector<double> &estimatedTime){
	double aux = 0;
	for (int i = 0; i < samples.size(); ++i)
	{		
		for (int j = 0; j < grade; ++j)
		{
			aux += X[j][0] * pow(samples[i], j);
		}
		estimatedTime.push_back(aux);
		aux = 0.0;
	}
};

void askParam(int &n){
	cout<< "\tIntroduzca el valor de n:";
	cin>>n;
	if(n < 0){
		cout<<"Error! El valor de n debe ser mayor que 0"<<endl;
		exit(-1);
	}
};

void showMatrix(vector<vector<double> > matrix, int grade){
	for (int i = 0; i < grade; ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
};

double calculateMean(vector<double> time){
	double mean = 0;
	for (int i = 0; i < time.size(); ++i)
	{
		mean += time[i];
	}
	mean = mean/time.size();
	return mean;
};

double calculateVariance(vector<double> time, double mean){
	double variance = 0;
	for (int i = 0; i < time.size(); ++i)
	{
		variance += (pow((time[i] - mean), 2) / time.size());
	}
	variance = variance - pow(mean, 2);
	return variance;
};
// ------- 	FUNCIONES AUXILIARES -------


// ------- 	FUNCIONES PARA RESOLVER EL SISTEMA -------
void calculateDepedentCoef(vector<double> samples, int grade, vector<vector<double> > &dependentCoef){
	// TODO
	double aux = 0.0;
	for(int i=0; i<grade; i++){
		for(int j=0; j<grade; j++){
			if(i==0 && j==0){
				dependentCoef[i][j] = samples.size();
			}else{
				for(int k=0; k<samples.size(); k++){
					aux += pow(samples[k], i+j);
				}
				dependentCoef[i][j] = aux;
				aux=0.0;
			}
		}
	}
};

void calculateIndepedentCoef(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &indepedentCoef){
	// TODO
	double aux =0.0;
	for(int i=0; i<grade; i++){
		for(int j=0; j<samples.size(); j++){
			aux = pow(samples[j], i) * realTime[j];
		}
		indepedentCoef[i][0] = aux;
		aux = 0.0;
	}
};

void getCoefficients(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &indepedentCoef, vector<vector<double> > &dependentCoef){
	calculateDepedentCoef(samples, grade, dependentCoef);
	calculateIndepedentCoef(samples, realTime, grade, indepedentCoef);
};

void getSolution(vector<double> samples, vector<double> realTime, int grade, vector<vector<double> > &X){
	vector<vector<double> > indepedentCoef;
	vector<vector<double> > dependentCoef;

	// Reserve matrix
	indepedentCoef = vector<vector<double> >(grade, vector<double>(1));
	dependentCoef = vector<vector<double> >(grade, vector<double>(grade));
	// Get coefficients
	getCoefficients(samples, realTime, grade, indepedentCoef, dependentCoef);
	// Show coefficients
	
	cout<<"\n\tMatriz de coeficientes: "<<endl;
	for (int i = 0; i < grade; ++i)
	{
		for (int j = 0; j < grade; ++j)
		{
			cout<<"a"<<j<<" "<<dependentCoef[i][j];
			if(j < grade-1){
				cout<<" + ";
			}
		}
		cout<<" = "<< indepedentCoef[i][0]<<endl;
	}

	resolverSistemaEcuaciones(dependentCoef, indepedentCoef, grade, X);
};

void calculateCoefDeter(vector<double> realTime, vector<double> estimatedTime){
	double meanReal = calculateMean(realTime);
	double meanEstimated = calculateMean(estimatedTime);
	double varianceReal = calculateVariance(realTime, meanReal);
	double varianceEstimated = calculateVariance(estimatedTime, meanEstimated);
	double determinationCoef = varianceEstimated / varianceReal;
	cout<<determinationCoef<<endl;
};
// ------- 	FIN FUNCIONES PARA RESOLVER EL SISTEMA -------
