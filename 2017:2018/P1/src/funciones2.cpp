#include "funciones2.hpp"

// RECURSIVE FIBONACCI FUNCTIONS

int fibonacci(int i){
	if(i==0 || i==1){
		return i;
	}
	else{
		return fibonacci(i-2) + fibonacci(i-1);
	}
}

void getFibonacci(int min, int max, int inc){
	Clock time;
	vector<double> samples; //Tracks the number of the sample
	vector<double> real_time; //Tracks the real time on each iteration.
	vector<double> estimated_time; //Tracks the estimates time on each iteration.
	vector<double> coefficients; //Keeps the coefficients used to get the curve
	double **info_data; //Matrix that keeps in each row: i real_time esti_time
	double aux, estimation=-1; //Auxiliar variables
	string file = "data.txt"; //Name of the file used to save the data
	
	//Clear all the vector 
	samples.clear();
	real_time.clear();
	estimated_time.clear();
	coefficients.clear();

	// Run the fibonacci algotihm and get the real time on each iteration	
	for (int i = min; i <=max; ++i)
	{
		time.start();
		fibonacci(i);
		if(time.isStarted()){
			time.stop();
			samples.push_back(i);
			real_time.push_back(time.elapsed());
		}
	}

	//Reserve the samples matrix and fill it with the id, real time and id^2
	info_data = reserveMatrix(samples.size());
	for (int i = 0; i < samples.size(); ++i)
	{
		info_data[i][0] = samples[i]; 
		info_data[i][1] = real_time[i];	
		info_data[i][2] = pow(2, samples[i]);
	}
	

	// Calculation of the coeficcient and the estimated time of them
	calculateCoefficients(info_data, coefficients, samples.size());

	//Show the curve with the coefficients already calculated.
	for (int i = 0; i < samples.size(); ++i)
	{
		aux = coefficients[0]+coefficients[1]*info_data[i][2];
		estimated_time.push_back(aux);
	}
	cout<<"---------------------------------"<<endl;
	cout<<"La ecuación ajustada es: ";
	cout<<coefficients[0]<<" ";
	if (coefficients[1] >= 0)
	{
		cout<<"+ ";
	}
	cout<<coefficients[1]<<" * 2^n"<<endl;
	cout<<"---------------------------------"<<endl;

	//We save the time resulted in order to get the plot
	keepData(samples, real_time, estimated_time, file);

	//Asks a number of iteration to calculate how many days it would take to run enterely.
	aux=0.0;
	do{
		do{
			cout<<"\t¿Valor de n a estimar?(0 salir)\t\nn:";
			cin >> estimation;
		}while(estimation < 0);

		if(estimation != 0){
			aux = coefficients[0]+coefficients[1]*pow(2,estimation);
			aux = abs(aux)/1000000.0/(60*60*24); //Pass the estimation into day format
			cout<<"\tEl tiempo estimado en dias es: "<<aux<<endl;
		}
	}while(estimation != 0);
}

// RECURSIVE DETERMINANT'S MATRIX FUNCTIONS

void fillMatrix(double **M, int grade){
	srand(time(NULL));
	int aux;

	for (int i = 0; i < grade; ++i)
	{
		for(int j = 0; j < grade; ++j){
			aux=rand()%(10)+1;
			if((rand()%2)==1){
				aux*=-1;
			}
			M[i][j]=aux;
		}
	}
}

double calculateSubMatrix(double **M, int grade, int row, int col){
	double **subM; //Matrix that is going to be send to calculateDeter
	int n = grade-1; //Size to get the new submatrix
	int x=0, y=0;
	subM = reserveMatrix(grade);
	for (int i = 0; i < grade; ++i){
		for(int j = 0; j < grade; ++j){
			if(i!= row && j!=col){ //If is not the cofactor then, copy the matrix
				subM[x][y] = M[i][j];
				y++;
				if(y >= n){//If we get the final column, then copy next row
					x++;
					y=0;
				}
			}
		}
	}
	//we see if the position is even(1) or odd(-1)
	return pow(-1.0, row+col) * calculateDeter(subM, n);
}

double calculateDeter(double **M, int grade){
	double det = 0.0;

	if(grade == 1){ //Base case
		det = M[0][0];
	}else{
		for (int i = 0; i < grade; ++i){
			det = det +M[0][i] * calculateSubMatrix(M, grade, 0, i); //Multiply all the cofactor by the final 2x2 determinant
		}
	}
	return det;
}

double factorial(double estimation){
	if(estimation==0 || estimation ==1){
		return 1;
	}else{
		return estimation * factorial(estimation-1);
	}
}

void getDeterminante(int min, int max, int inc){

	Clock time;
	vector<double> samples; //Tracks the number of the sample
	vector<double> real_time; //Tracks the real time on each sample
	vector<double> estimated_time; //Tracks the estimated time on each sample
	vector<double> coefficients; //Keeps the coefficients of the curve
	double **Matrix; //Auxiliar matrix
	double **info_data; //Matrix that keeps i real_time esti_time
	double aux, estimation=-1; //Auxiliar variables
	string file = "data.txt"; //Name of the file to save the data
	coefficients.clear();
	
	//Get the real time and keep it in a vector. 
	for (int i = min; i <=max; ++i)
	{
		Matrix = reserveMatrix(i);
		fillMatrix(Matrix, i);
		time.start();
		calculateDeter(Matrix, i);
		if(time.isStarted()){
			time.stop();
			samples.push_back(i);
			real_time.push_back(time.elapsed());
		}
	}

	//Keep the data of id_samples, real_time, and id_samples!
	info_data = reserveMatrix(samples.size());
	for (int i = 0; i < samples.size(); ++i)
	{
		info_data[i][0] = samples[i]; //ID
		info_data[i][1] = real_time[i];	//observable time
		info_data[i][2] = factorial(i); // z = N!
	}
	
	//Calculate the coefficients of the curve
	calculateCoefficients(info_data, coefficients, samples.size());
	//Show the equation of the curve with the coefficients
	for (int i = 0; i < samples.size(); ++i)
	{
		aux = coefficients[0]+coefficients[1]*info_data[i][2];
		estimated_time.push_back(aux);
	}
	cout<<"---------------------------------"<<endl;
	cout<<"La ecuación ajustada es: ";
	cout<<coefficients[0]<<" ";
	if (coefficients[1] >= 0)
	{
		cout<<"+ ";
	}
	cout<<coefficients[1]<<" * n!"<<endl;
	cout<<"---------------------------------"<<endl;

	//We save the time resulted in order to get the plot
	keepData(samples, real_time, estimated_time, file);

	//Asks if the user want to estimate guesting the number of iterations
	aux=0.0;
	do{
		do{
			cout<<"\t¿Valor de n a estimar?(0 salir)\t\nn:";
			cin >> estimation;
		}while(estimation < 0);

		if(estimation != 0){
			aux = coefficients[0]+coefficients[1]*factorial(estimation);
			aux = abs(aux)/1000000.0/(60*60*24); //Pass the estimation into day format
			cout<<"\tEl tiempo estimado en dias es: "<<aux<<endl;
		}

	}while(estimation != 0);
}

// COMMON FUNCTIONS

double **reserveMatrix( int size){
	double ** M;
	M = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		M[i] = new double [size];
	}
	return M;
}

void showMatrix(double **M, int rows, int cols){
	for (int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void calculateCoefficients(double **info_data, vector<double> &coefficients, int num_samples){
	double mean_coef1, mean_coef2;
	double covariance_12;
	double varianza_2;
	double aux=0;
	double estimation;

	//Mean coef1 = ordenada_en_origen
	for (int i = 0; i < num_samples; ++i)
	{
		aux += info_data[1][i];
	}
	mean_coef1 = aux/num_samples;
	cout<<"Media orden: "<<mean_coef1<<endl;
	aux=0;
	//Mean coef2 = pendiente
	for (int i = 0; i < num_samples; ++i)
	{
		aux+= info_data[2][i];
	}
	mean_coef2 = aux/num_samples;
	cout<<"Media pendiente: "<<mean_coef2<<endl;
	//Varianza Sum((Xi- mean(X))^2)/size
	aux=0; 
	for (int i = 0; i < num_samples; ++i)
	{
		aux += pow(info_data[2][i]-mean_coef2, 2);
	}
	varianza_2 = aux/num_samples;
	cout<<"varianza pendiente: "<<varianza_2<<endl;
	//Covarianza Sxy=Sum((Xreal*Xest)/size)-(mean(Xreal)*mean(Xest))
	aux=0;
	for (int i = 0; i < num_samples; ++i)
	{
		aux += (info_data[1][i]*info_data[2][i]);
	}
	covariance_12 = (aux/num_samples) - (mean_coef1*mean_coef2);
	cout<<"Covarianza varianza pend/orden "<<covariance_12<<endl;

	coefficients.push_back(covariance_12 / pow(varianza_2, 2));
	coefficients.push_back(mean_coef1 - coefficients[0]*mean_coef2);
}

void keepData(vector<double> samples, vector<double> realTime, vector<double> estimatedTime, string file){
	ofstream output(file.c_str());
	for (int i = 0; i < realTime.size(); ++i)
	{
		output<<samples[i]<<" "<< realTime[i]<<" "<<estimatedTime[i]<< " "<<endl;
	}
}