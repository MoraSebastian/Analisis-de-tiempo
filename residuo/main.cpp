#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void llenarArreglo(char a[], int n, int i);
int unsigned bits (int x, int k, int j);
void cambioresiduos(char a[], int izq, int der, int b);
void intercambio(char a[], int i, int j);
void MostrarArreglo(char a[], int n, int i);
using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int inline unsigned bits (int x, int k, int j)
    {return (x>>k)&~(~0<<j);}


void intercambio(char a[], int i, int j){
	int temp;
	temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

void llenarArreglo(char a[], int n, int i){
	for (i=0; i<n; i++){
		a[i]= 65 + rand() % (81 - 65) ;
	}
}

void MostrarArreglo(char a[], int n, int i){
	cout<<"Arreglo ordenado: "<<endl;
	for(i=0; i<n; i++){
		cout<<a[i];
	}
}
void cambioresiduos(char a[], int izq, int der, int b){ 
    int i,j; char t; 
    if (der>izq && b>=0)
      {i= izq; j=der;
        while(j!=i){ 
	   		while(!bits(a[i],b,1) && i<j)i++;               
            while( bits(a[j],b,1) && j>i)j--;
            intercambio(a, i, j);
           }
    	if (!bits(a[i], b,1)) j++;
            cambioresiduos(a, izq, j-1, b-1);
            cambioresiduos(a, j, der, b-1);
      }
}

int main(int argc, char** argv) {
	
	srand(time(NULL));
	LARGE_INTEGER t_ini, t_fin;
   	double tiempo;
	int n=10, i;
	char *arreglo;
	
	while(n<=300){
		arreglo = new char[n];
		//char arreglo[]={69,74,69,77,80,76,79,65,79,82,68,69,78,65,82};
		//llenarArreglo(arreglo, n, i);
		//MostrarArreglo(arreglo, n, i);
		
		QueryPerformanceCounter(&t_ini);
		cambioresiduos(arreglo, 0, n-1,5);
		QueryPerformanceCounter(&t_fin);
		
		tiempo = performancecounter_diff(&t_fin, &t_ini);
		cout<<" "<<tiempo * 1000.0 <<endl;
		//MostrarArreglo(arreglo, n, i);
		n+=10;
		delete[] arreglo;
	}
	
	return 0;
}


