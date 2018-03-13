#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <windows.h>


double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


using namespace std;
int main(int argc, char** argv) {
	int n=5, i,medio, clave, j=0;
	int primero , ultimo;
	bool encontrado  =false;
	int * arreglo, *vector;
	LARGE_INTEGER t_ini, t_fin;
   	double tiempo;
	

	
	while(n<=1500){
		
		arreglo = new int[n];
		
		for(i=0;i<n;i++){
			arreglo[i]=(i+1);		
			//cout<<arreglo[i]<<endl;
		}
		clave = -1;
		//cout<<"clave: "<<clave<<endl;
		primero = 0;
		ultimo = n;     // cambio
		
		QueryPerformanceCounter(&t_ini);
		
		while(primero<=ultimo && encontrado != true){
			medio  = (primero+ultimo)/2;
			j+=1;
			if(arreglo[medio]== clave ){    //cambie 1 por clave
				encontrado = true;
			}
			else{
				if(clave<arreglo[medio])
					ultimo = medio-1;
				else
					primero = medio+1;
			}
		}
		encontrado=false;
		cout<<"  ";
		QueryPerformanceCounter(&t_fin);
		//cout<<n<<"  "<<j;
		
		tiempo = performancecounter_diff(&t_fin, &t_ini);
		cout<<" "<<tiempo * 1000.0 <<endl;
		n+=5;
		j=0;
		encontrado=false;
		delete []arreglo;
	}
	
	
	return 0;
}
