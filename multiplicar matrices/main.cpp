#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(int argc, char** argv) {
	//declarando variables 
	int n=5, i, j, k;
	int **A, **B, **C;
	srand(time(NULL));
	LARGE_INTEGER t_ini, t_fin;
    double secs;
    
    
	/*
	cout<<"Ingrese el tamaño de las matrices que multiplicara: ";
	cin>>n;
	*/
	
	cout<<"n     time"<<endl;
	while(n<=150){
		A=new int*[n];   //Reservando memoria para las filas de la matriz A
		B=new int*[n]; 	 //Reservando memoria para las filas de la matriz B
		C=new int*[n];	 //Reservando memoria para las filas de la matriz C	
		
		//llenado de las matrices que se multiplicaran A y B
		for(i=0; i<n; i++){
			A[i] = new int[n];		//Reservando memoria para las columnas de A
			B[i] = new int[n];		//Reservando memoria para las columnas de B
			C[i] = new int[n];		//Reservando memoria para las columnas de C
			
			for(j=0; j<n; j++){
				A[i][j] = rand() % (1001);
				B[i][j] = rand() % (1001);
				
			}
		}
		
		//Multiplicación de las matrices A y B
		QueryPerformanceCounter(&t_ini);
		for(i=0; i<n; i++){
			
			for(j=0; j<n; j++){
				C[i][j] = 0;
				
				for (k=0; k<n; k++){
					C[i][j] = C[i][j] + A[i][k]*B[k][j];
				}
			}
		}
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		cout<<n<<"      "<<secs * 1000.0 <<endl;
		//Escribiendo el resultado de la multiplicación
		/*for(i=0; i<n; i++){
			//matriz A
			for(j=0; j<n; j++){
				cout<< A[i][j]<<" ";
			}
			cout<<"      ";
			//matriz B
			for(j=0; j<n; j++){
				cout<< B[i][j]<<" ";
			}
			cout<<"      ";
			//matriz resultante C
			for(j=0; j<n; j++){
				cout<< C[i][j]<<" ";
			}
			cout<<endl;
		}*/
		
		//liberar la memoria utilizada para la matriz
		for(i=0; i<n; i++){
			delete[] A[i];
			delete[] B[i];
			delete[] C[i];
		}
		delete[] A;
		delete[] B;
		delete[] C;
		n+=5;
	}
	
	
	
	return 0;
}
