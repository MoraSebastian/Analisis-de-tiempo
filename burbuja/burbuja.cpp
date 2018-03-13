#include <iostream>
#include <ctime> 
#include <time.h>
#include <stdio.h>
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
	int i, j, n, temp;
	//declarando variables para la medición de tiempo
	//unsigned t0, t1;      //Primera forma
	//double time;
	//t0=clock();      //Primera forma
	//clock_t start = clock();         //Segunda forma
	
	cout<<"ingrese el tamaño del vector: ";
	cin>>n;
	int vector[n];
	
	
	
	cout<<"ingrese los números del vector: "<<endl;
	for(i=0; i<n; i++){
		cin>>vector[i];
	}
	
	
	LARGE_INTEGER t_ini, t_fin;
    double secs;
    QueryPerformanceCounter(&t_ini);
    
	for (i= n-1; i>0 ;i--){
		for(j=1; j<=i; j++){
			if(vector[j-1] > vector[j]){
				temp = vector[j];
				vector[j] = vector[j-1];
				vector[j-1] = temp;
			}
		}
	}
	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
	cout<<"Tiempo transcurrido: "<<secs * 1000.0 <<endl;
	//t1 = clock();         //Primera forma
	cout<<"vector ordenado: "<<endl;
	for(i=0; i<n; i++){
		cout<< vector[i]<<endl;
	}
	//time= (double(t1-t0)/CLOCKS_PER_SEC);         //Primera forma
	//cout << "Execution Time: " << time << endl;       //Primera forma
	
	//cout<<"Tiempo transcurrido: %f"<< ((double)clock() - start) / CLOCKS_PER_SEC;      //Segunda forma
	return 0;
}
