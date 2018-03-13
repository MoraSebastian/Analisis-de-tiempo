#include <algorithm>
#include <iostream>
#include <iterator>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include <ctime> 
using namespace std;


double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

// Radix sort comparator for 32-bit two's complement integers
class radix_test
{
    const int bit; // bit position [0..31] to examine
public:
    radix_test(int offset) : bit(offset) {} // constructor
 
    bool operator()(int value) const // function call operator
    {
        if (bit == 31) // sign bit
            return value < 0; // negative int to left partition
        else
            return !(value & (1 << bit)); // 0 bit to left partition
    }
};
 
// Least significant digit radix sort
void lsd_radix_sort(int *first, int *last)
{
    for (int lsb = 0; lsb < 32; ++lsb) // least-significant-bit
    {
        std::stable_partition(first, last, radix_test(lsb));
    }
}
 
// Most significant digit radix sort (recursive)
void msd_radix_sort(int *first, int *last, int msb = 31)
{
    if (first != last && msb >= 0)
    {
        int *mid = std::partition(first, last, radix_test(msb));
        msb--; // decrement most-significant-bit
        msd_radix_sort(first, mid, msb); // sort left partition
        msd_radix_sort(mid, last, msb); // sort right partition
    }
}


void llenarArreglo(int *arreglo, int n, int i){
	for(i=0; i<n; i++){
		arreglo[i] = rand()%(150);
	}
}

void mostrarArreglo(int *arreglo, int n, int i){
	for(i=0; i<n; i++){
		cout<<arreglo[i]<<" ";
	}
}
// test radix_sort
int main()
{
    int *data;
    int n=50,i;
    double secs;
    LARGE_INTEGER t_ini, t_fin;
    //cin>>n;
    srand(time(NULL));
    while(n<=500){
    	
	    data = new int[n];
		
		llenarArreglo(data, n, i);
		//mostrarArreglo(data, n, i);
		//cout<<endl; 
	    //lsd_radix_sort(data, data + n);
	    QueryPerformanceCounter(&t_ini);
	    msd_radix_sort(data, data + n);
	    QueryPerformanceCounter(&t_fin);
	    
	    //mostrarArreglo(data, n, i);
	    
	    secs = performancecounter_diff(&t_fin, &t_ini);
		cout<<" "<<secs * 1000.0 <<endl;
	    
	    //std::copy(data, data + n, std::ostream_iterator<int>(std::cout, " "));
	    delete[] data;
	    n+=10;
	}
    
 
    return 0;
}
