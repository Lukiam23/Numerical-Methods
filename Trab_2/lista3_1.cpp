#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void gaussElimination(double** matriz, double* x1, double* x2,  double* x3, int rows, int columns){
	
	for(int k = 0; k<rows-1;k++){
		for(int i = k+1; i<rows; i++){
			double m = matriz[i][k] / matriz[k][k];
			matriz[i][k] = 0;
			for(int j = k+1; j<rows+1; j++){
				matriz[i][j] += - matriz[k][j] * m;
			}
		}
	}

	double x[rows];

	x[rows-1] = matriz[rows-1][columns-1]/matriz[rows-1][columns-2];
	for(int k = rows-1; k>-1; k--){
		double s = 0;
		for(int j = k+1; j<columns-1; j++){
			s +=  matriz[k][j] * x[j];
		}
		x[k] = (matriz[k][3]-s) / matriz[k][k];
	}

	*x1 = x[0];
	*x2 = x[1];
	*x3 = x[2];
}

void switchRows(double** matriz,int row1,int row2){

	double* aux = matriz[row1];
	matriz[row1] =  matriz[row2];
	matriz[row2] = aux;
}

void gaussEliminationParcialPivo(double** matriz, double* x1, double* x2,  double* x3, int rows, int columns){
	
	for(int k = 0; k<rows-1;k++){
		int pivo = k;
		for(int p = k; p<rows; p++){
			if(matriz[pivo][k]<abs(matriz[p][k])){
				pivo = p;
			}
		}
		switchRows(matriz,k,pivo);
		
		for(int i = k+1; i<rows; i++){
			double m = matriz[i][k] / matriz[k][k];
			matriz[i][k] = 0;
			for(int j = k+1; j<rows+1; j++){
				matriz[i][j] += - matriz[k][j] * m;
			}
		}
	}

	double x[rows];

	x[rows-1] = matriz[rows-1][columns-1]/matriz[rows-1][columns-2];
	for(int k = rows-1; k>-1; k--){
		double s = 0;
		for(int j = k+1; j<columns-1; j++){
			s +=  matriz[k][j] * x[j];
		}
		x[k] = (matriz[k][3]-s) / matriz[k][k];
	}

	*x1 = x[0];
	*x2 = x[1];
	*x3 = x[2];


}

int main(){
	double x1,x2,x3;
	//double matriz[3][4] = {{20,7,9,16},{7,30,8,38},{9,8,30,38}};

	double** matriz = new double*[3];
	for(int i = 0; i<3; i++) matriz[i] = new double[4];
	
	matriz[1][0] = 20;
	matriz[1][1] = 7;
	matriz[1][2] = 9;
	matriz[1][3] = 16;

	matriz[0][0] = 7;
	matriz[0][1] = 30;
	matriz[0][2] = 8;
	matriz[0][3] = 38;

	matriz[2][0] = 9;
	matriz[2][1] = 8;
	matriz[2][2] = 30;
	matriz[2][3] = 38;

	//gaussElimination(matriz, &x1,&x2,&x3,3,4);
	gaussEliminationParcialPivo(matriz, &x1,&x2,&x3,3,4);

	cout<<"x1: "<<x1<<" x2: "<<x2<<" x3: "<<x3<<endl;

	return 0;
}

