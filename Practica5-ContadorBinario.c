#include <stdio.h>
#include <stdlib.h>
#define k 8

//Tinoco Videgaray Sergio-3BV1
//07/12/21
//Practica 5 Contador binario

void Incrementar(int A[k],int* costo);

int main(int argc, char* argv[]){
	int A[k]={0,0,0,0,0,0,0,0};
	int i,costo=0;
		
	Incrementar(A,&costo);
	Incrementar(A,&costo);
	Incrementar(A,&costo);
	Incrementar(A,&costo);
	Incrementar(A,&costo);
	Incrementar(A,&costo);
	
	for(i=k;i>=0;i--){
		printf("%d\t",A[i]);
	}
	printf("\nCosto total: %d",costo);
	
	return 0;
}

void Incrementar(int A[k],int* costo){
	int i=0;
	while(i<k && A[i]==1){
		A[i]=0;
		(*costo)++;
		i++;
	}
	if(i<k){
		(*costo)++;
		A[i]=1;
	}
	
}
