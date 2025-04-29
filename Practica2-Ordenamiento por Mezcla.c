#include <stdio.h>
#include <stdlib.h>

//Tinoco Videgaray Sergio
//Grupo 3BV1
//08/09/21

#define TAM 10

int* crearArreglo(int l);
void mergeSort(int arr[],int tam);
void merge(int nIzq, int nDer, int *izq, int *der, int *final);

int main(int argc,char* argv[]){
		
int * arreglo;
int i;

	arreglo=crearArreglo(TAM);	
	mergeSort(arreglo,TAM);
	
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



void mergeSort(int arr[],int tam){
    int med,j,k;
if (tam==1)
{
    return ;
}
    med=tam/2;
    int izq[med], der[tam-med];
    int *i=izq;
    int *d=der;
    
    
    for (j = 0; j < med; j++)
    {
       izq[j]=arr[j];
    }
    for (k = med; k < tam; k++)
    {
        der[k-med]=arr[k];
    }
    mergeSort(i,med);
    mergeSort(d,tam-med);
    merge(med,(tam-med),i,d,arr);
      
}



void merge(int nIzq, int nDer, int *izq, int *der, int *final){
    int i=0,j=0,k=0;
    while ((i<nIzq) && (j<nDer))
    {
        if(izq[i] <= der[j]){
            final[k]=izq[i];
            i++;
        }
        else
        {
            final[k]=der[j];
            j++;
        }
        k++;
    }
    while (i<nIzq)
    {
        final[k]=izq[i];
            i++;
            k++;
    }
    while (j<nDer)
    {
         final[k]=der[j];
            j++;
            k++;
    }  
       
}

