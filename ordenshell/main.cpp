#include <iostream>
#include <stdlib.h>
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
	int i, j, h, n=50, v;
	int *a;
	LARGE_INTEGER t_ini, t_fin;
    double secs;
	
	
	
	//while(n<=500){
		a = new int[n];
		//llenando el arreglo con el peor caso
		for(i=n-1; i>=0; i--){
			a[i] = i+1;
			cout<<a[i]<<" ";
		}
		
		QueryPerformanceCounter(&t_ini);
		for(h=1; h<=n/9; h=3*h+1);
		for(; h>0; h/=3)
		for(i=h; i<n; i+=1){     //bajar limite del for
			v=a[i];
			j=i;
			while(j>h && a[j-h]>v){
				a[j]=a[j-h];
				j-=h;
			}
			a[j]=v;
		}
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		cout<<endl;
		for(i=0; i<n; i++){
			cout<<a[i]<<" ";
		}
	
	//	delete[] a;
		
		
	//	cout<<"      "<<secs * 1000.0 <<endl;
	//	n+=10;
	//}
	
	return 0;
}
