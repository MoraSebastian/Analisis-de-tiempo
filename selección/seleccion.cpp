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
	unsigned t0, t1;
    clock_t start = clock();
	//t0=clock();
	// Code to execute
	
 
	double time;

	int i, j, min, n, temp;
	cout<<"ingrese el tamaño del arreglo: ";
	cin>>n;
	int vec[n];
	
	cout<<"ingrese los valores del arreglo: "<<endl;
	for(i=0; i<n; i++){
		cin>>vec[i];
	}
	
	LARGE_INTEGER t_ini, t_fin;
    double secs;
    QueryPerformanceCounter(&t_ini);
	for(i=0; i<n; i++){
		min = i; 
		for(j = i+1; j<=n; j++){
			if(vec[j] < vec[min]){
				min = j;
			}										
			temp = vec[j];
			vec[j] = vec[min];
			vec[min] = temp;	
		}
	}
	
	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
	cout<<"Tiempo transcurrido: "<<secs * 1000.0 <<endl;
	
	
	//t1 = clock();
	cout<<"arreglo ordenado:"<<endl;
	for(i=0; i<n; i++){
		cout<<vec[i]<<endl;
	}
	
	//time= (double(t1-t0)/CLOCKS_PER_SEC);
	//cout << "Execution Time: " << time << endl;
	//cout<<"Tiempo transcurrido: %f"<< ((double)clock() - start) / CLOCKS_PER_SEC;
	return 0;
}
