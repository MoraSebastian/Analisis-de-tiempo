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
	int i, j, n, v;
	//declarando variables para la medición de tiempo
	unsigned t0, t1;
	double time;
	
	//t0=clock();
	
	cout<<"ingrese el tamaño del vector: ";
	cin>>n;
	int vector[n] ;
	cout<<"ingrese los valores del vector:"<<endl;
	for(i=0; i<n; i++){
		cin>>vector[i];
	}
	
	
	//clock_t start = clock();
	LARGE_INTEGER t_ini, t_fin;
    double secs;
    QueryPerformanceCounter(&t_ini);
	for(i=1; i<n; i++){
		j=i;
		v=vector[j];
		while((vector[j-1]>v) && (j>0)){
			vector[j] = vector[j-1];
			j--;
		}
		vector[j]=v;
	}
	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
	//time =((double)clock() - start) / CLOCKS_PER_SEC;
	cout<<"Tiempo transcurrido: "<<secs * 1000.0 <<endl;
	//t1 = clock();
	cout<<"vector ordenado: "<<endl;
	for(i=0; i<n; i++){
		cout<<vector[i]<<endl;
	}
	//time= (double(t1-t0)/CLOCKS_PER_SEC);
	//cout << "Execution Time: " << time << endl;
	
	return 0;
}
