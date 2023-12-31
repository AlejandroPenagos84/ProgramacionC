//Javier Alejandro Penagos Hernández. 20221020028.
//Laura Sofia Amado Gonzalez. 20212020034.
#include <iostream>
#include <Windows.h>

using namespace std;

int *Llenar(int* a,int n){
	int num=n;
	for(int i=0;i<n;i++){
		a[i]=num;
		num--;
	}
	return a;
}

int *Burbuja(int* a,int n){
	int temp;
	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=i;j++){
			if(a[j-1]>a[j]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	return a;
}


int main(int argc, char *argv[]) {
	LARGE_INTEGER frequency;
    LARGE_INTEGER start_time, end_time;
    

	
	int *arreglo;
	
	
	for(int N = 10;N<=1000;N+=10){
	
		arreglo = new int[N];
		arreglo = Llenar(arreglo,N);
		
		QueryPerformanceFrequency(&frequency);
		
		QueryPerformanceCounter(&start_time);
		arreglo = Burbuja(arreglo,N);
		QueryPerformanceCounter(&end_time);
			
		double tiempo = static_cast<double>(end_time.QuadPart - start_time.QuadPart)/ frequency.QuadPart;
        cout <<tiempo<<endl;
		
		delete[]arreglo;
	}
	return 0;
}


