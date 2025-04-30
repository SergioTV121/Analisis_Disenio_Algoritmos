#include <stdio.h>
#include <stdlib.h>
#define TAM 20


//Tinoco Videgaray Sergio
//Grupo 3BV1
//17/09/21

int* crearArreglo(int l);
void quicksort(int *a,int p,int r);
int particion(int *a,int p,int r);

int main(int argc, char* argv[]){
	int* arr=crearArreglo(TAM);
	int i;
	
	quicksort(arr,0,TAM-1);
	
		
	for(i=0;i<TAM;i++){
		printf("%d\n",arr[i]);
	}
	
	return 0;
}

void quicksort(int *a,int p,int r){
	int q;
	if(p<r)
	{
	q=particion(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);
	}	
	
}


int particion(int *a,int p,int r){
int x,i,j,aux;
x=a[r];
i=p-1;

for(j=p;j<r;j++){
	if(a[j]<=x){
		i++;
		aux=a[i];
		a[i]=a[j];
		a[j]=aux;
	}	
}	
i++;
	aux=a[i];
	a[i]=a[r];
	a[r]=aux;	
	
	return i;
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
