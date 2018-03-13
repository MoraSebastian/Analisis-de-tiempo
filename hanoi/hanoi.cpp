# include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace::std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void Mover_Torres(int N, char Origen, char Intermedio, char Destino)

{ // Abre funcion Mover_Torres

	if ( N > 1 )
	{ // Abre if
		Mover_Torres( N - 1, Origen, Destino, Intermedio);


		//cout <<"\nMueve el disco " <<  N  << " de " << Origen << " a " <<  Destino << endl;
		Mover_Torres( N - 1, Intermedio, Origen, Destino);
	} // Cierra if

// El caso limite mas sencillo se resuelve directamente

	if ( 1 == N ){
	}
	
		//cout << "\nMueve el disco 1 de " << Origen << " a " << Destino << endl;

} // Cierra funcion Mover_Torres

int main()
{ // Abre funcion main
	int n=2;
	LARGE_INTEGER t_ini, t_fin;
    double secs;
	//cout << "\nEste programa resuelve el problema clasico de las Torres de Hanoi";
	//cout <<" mediante la recursion." << endl;
	//cout << "\nPor favor introduzca el numero de discos que quiere mover ";
	//cout << " de la pila O a la pila D" << endl;
	//cin >> n;
	
	while(n<=500){
		QueryPerformanceCounter(&t_ini);
		Mover_Torres( n, 'O', 'A', 'D');
		QueryPerformanceCounter(&t_fin);
		
		secs = performancecounter_diff(&t_fin, &t_ini);
		cout<<n<<"      "<<secs * 1000.0 <<endl;
		n+=1;
	}
	
	
	
	return 0;

} // Cierra funcion main
