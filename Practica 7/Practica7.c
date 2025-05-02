#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

//Tinoco Videgaray Sergio Ernesto
//09/12/21

void Aleatorizar(int* A,int n);
int ContratacionOnline(int* A,int n, int k);

int main(int argc, char*argv[]){
	int* A;
	int n,candidato,i;
	printf("Ingrese el numero de candidatos: ");
	scanf("%d",&n);
	A=(int*)malloc(n*sizeof(int));
		
	Aleatorizar(A,n);
	candidato=ContratacionOnline(A,n,n/2);
	
	for(i=0;i<n;i++){
			printf("%d\t",A[i]);
		}
	printf("\nSe contrato al candidato %d con la calificacion de %d",candidato+1,A[candidato]);
	
	return 0;
}

	int ContratacionOnline(int* A,int n, int k){
		int best=0,i=0;
		for(i=0;i<k;i++){
			if(A[i]>best){
				best=A[i];
			}
		}
		
		for(i=k;i<n;i++){
			if(A[i]>best){
				return i;
			}
		}
		return n-1;
	}

	void Aleatorizar(int* A,int n){
		int i,aux,r;
		for(i=0;i<n;i++){
			A[i]=rand()%50 +1;
		}
	
		for(i=0;i<n;i++){
			r=(rand()%n-i) +i;
			aux=A[i];
			A[i]=A[r];
			A[r]=aux;
		}
	}
