#include <stdio.h>
#include <stdlib.h>

#define TAM 50

//Alumno: Tinoco Videgaray Sergio Ernesto
//Grupo: 3BV1
//02/09/21

int* crearArreglo(int l);
void ordenarArreglo(int *arr,int n);

int main(int argc, char*argv[]){
	
int * arreglo;
int i;

	arreglo=crearArreglo(TAM);	
	ordenarArreglo(arreglo,TAM);
	
	for(i=0;i<TAM;i++){
		printf("%d\n",arreglo[i]);
	}
	
	return 0;
}

int* crearArreglo(int l){
	int * arr=NULL;
	int i;
	
	arr=(int*)malloc(l*sizeof(int));
	for(i=0;i<l;i++)			{
		arr[i]=rand()%99 +1;
	}
			
	return arr;
}


void ordenarArreglo(int *arr,int n){
	int i,j,x;
	for(j=2;j<n;j++){
		i=j-1;
		x=arr[j];
		while (x<arr[i] && i>=0){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=x;
	}
	
}


