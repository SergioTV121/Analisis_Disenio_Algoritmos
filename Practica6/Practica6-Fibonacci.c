#include <stdio.h>
#include <stdlib.h>

//Tinoco Videgaray Sergio 	3BV1	20/11/21

int main(int argc, char* argv[]){
	int n,k,i,j,a=0;
	printf("Ingrese n: ");
	scanf("%d",&n);
	k=n;
	int matriz[n][k];
	int serie[n+1];
	serie[0]=0;
	serie[1]=1;
	
	
	for(i=2;i<=n;i++){
		serie[i]=0;
	}	
	
	for(i=0;i<n;i++){
		matriz[i][0]=1;
	}
	
	for(i=1;i<n;i++){
		matriz[i][1]=i;
	}
	
	for(i=2;i<k;i++){
		matriz[i][i]=1;
	}
	
	for(i=3;i<n;i++){
		for(j=2;j<=i-1;j++){
			if(j<=k){
				matriz[i][j]=matriz[i-1][j-1]+matriz[i-1][j];
			}		
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<i+1;j++){
			printf("%d\t",matriz[i][j]);
		}
		printf("\n\n");
	}
	
	
	//Obtener secuencia de fibonacci
	for(i=2;i<=n;i++){
		if(i%2==1){
			a++;
		}
		for(j=0;j<=a;j++){
			serie[i]+=matriz[i-j-1][j];
		}
	
	}
	
	
	printf("Secuencia de %d: ",n);
	for(j=0;j<n+1;j++){
			printf("%d ",serie[j]);
		}
	
	
	return 0;
}

