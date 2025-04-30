#include <stdlib.h>
#include <stdio.h>
#define N 3

//Tinoco Videgaray Sergio 3BV1
//Practica 4 multiplicacion de matrices

void imprimirMatriz(int** m,int L);
int** multiplicarMatrices(int **A,int **B,int L);
int** crearMatriz(int n,int F);
int** obtenerTranspuesta(int** M,int l);
	
int main(int argc, char*argv[]){
	
	int** mA, **mB, **mC, **mTB;
	
	mA=crearMatriz(N,1);  //CREA MATRIZ DE 3X3 EMPEZANDO DEL 1
	mB=crearMatriz(N,2);//CREA MATRIZ DE 3X3 EMPEZANDO DEL 2
	
mTB=obtenerTranspuesta(mB,N); //Obtiene la transpuesta de B
	
	imprimirMatriz(mA,N);
	imprimirMatriz(mTB,N);
	
mC=multiplicarMatrices(mA,mTB,N);//Aplica el algoritmo de multiplicacion de matrices
	
imprimirMatriz(mC,N);	
	
	
free(mA);
free(mB);
free(mC);

	return 0;
}

int** crearMatriz(int n,int F){
	int i,j,k=F;
	
	int** matriz=(int**)malloc(n*sizeof(int*));
	
for(i=0;i<n;i++){
	matriz[i]=(int*)malloc(n*sizeof(int));
}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriz[i][j]=k;
			k+=2;
		}
	}


	return matriz;
}


int** multiplicarMatrices(int **A,int **B,int L){
	int i,j,k;
	
int** C=(int**)malloc(L*sizeof(int*));
	
for(i=0;i<L;i++){
	C[i]=(int*)calloc(L,sizeof(int));
}
	
	
	for(i=0;i<L;i++){
		for(j=0;j<L;j++){
			for(k=0;k<L;k++){
				C[i][j]+=(A[i][k])*(B[j][k]);		
			}
		}
	}

return C;
}


int** obtenerTranspuesta(int** M,int l){
int i,j,a1,a2;

int** Mt=(int**)malloc(l*sizeof(int*));
	
for(i=0;i<l;i++){
	Mt[i]=(int*)malloc(l*sizeof(int));
}


for(i=0;i<l;i++){
		for(j=0;j<l;j++){
			Mt[i][j]=M[j][i];
		}
		
	}
return Mt;
}
	
	


void imprimirMatriz(int** m,int L){
int i,j;

for(i=0;i<L;i++){
	for(j=0;j<L;j++){
		printf("%d\t",m[i][j]);
	}printf("\n");
}

printf("\n\n\n");	
}
