#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
 
//Tinoco Videgaray Sergio 3BV1

struct MinHeapNode {
 
    char data;
 
    unsigned freq;
 
    struct MinHeapNode *left, *right;
};
 
 
struct MinHeap {
 

    unsigned size;
 

    unsigned capacity;
 
    struct MinHeapNode** array;
};
 

struct MinHeapNode* newNode(char data, unsigned freq)		//Generar nodo tipo struct
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(
        sizeof(struct MinHeapNode));
 
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
 
    return temp;
}
 

struct MinHeap* createMinHeap(unsigned capacity)			//Crear nodo cabeza
 
{
 
    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 
    minHeap->size = 0;
 
    minHeap->capacity = capacity;
 
    minHeap->array = (struct MinHeapNode**)malloc(
        minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
 

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)		//Intercambiar nodos cabeza
 
{
 
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(struct MinHeap* minHeap, int idx)
 
{
 
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size
        && minHeap->array[left]->freq
               < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size
        && minHeap->array[right]->freq
               < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
 

int isSizeOne(struct MinHeap* minHeap)			//Corroborar si el arbol es de tamaño 1
{
 
    return (minHeap->size == 1);
}
 

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
 
{
 
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) 		//Insertar nodo raiz
{
 
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)			//NodoCabeza
 
{
 
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
 
    printf("\n");
}
 

int isLeaf(struct MinHeapNode* root)			//Comprobar si es un nodo hoja
{
 
    return !(root->left) && !(root->right);
}
 

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
 
{
	int i;
 
    struct MinHeap* minHeap = createMinHeap(size);
 
    for (i = 0; i < size; i++)
        minHeap->array[i] = newNode(data[i], freq[i]);
 
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return minHeap;
}
 

struct MinHeapNode* buildHuffmanTree(char data[],int freq[], int size)		//GenerarArbol
 
{
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap
        = createAndBuildMinHeap(data, freq, size);
 

    while (!isSizeOne(minHeap)) {
 

        left = extractMin(minHeap);
        right = extractMin(minHeap);
 
        top = newNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        insertMinHeap(minHeap, top);
    }
 

    return extractMin(minHeap);
}
 

void printCodes(struct MinHeapNode* raiz, int arr[],int top)			//Imprimir codigo Huffman de manera recursiva

{
 
    if (raiz->left) {
 
        arr[top] = 0;
        printCodes(raiz->left, arr, top + 1);
    }
 
    if (raiz->right) {
 
        arr[top] = 1;
        printCodes(raiz->right, arr, top + 1);
    }
 
    if (isLeaf(raiz)) {
 
        printf("%c: ", raiz->data);
        printArr(arr, top);
    }
}
 
void Huffman(char *cadena, int *freq, int N)
 
{
	
    struct MinHeapNode* raiz= buildHuffmanTree(cadena, freq, N);
 
    int arr[MAX_TREE_HT], top = 0;
 
 	printf("Mensaje codificado:\n");
    printCodes(raiz, arr, top);
}


int getFreq(char* texto,char* cad, int* freq){			//Obtener Frecuencias
		
	int i,j,k=-1,N=strlen(texto);     
    
	for(i=0;i<N;i++){
		
		if(texto[i]!='Ù'){
			k++;
			cad[k]=texto[i];
			freq[k]=1;
			texto[i]='Ù';	
			}
			for(j=i+1;j<N;j++){
			if(texto[j]==cad[k]){
				freq[k]++;
				texto[j]='Ù';
				
			}
		}
}
		return k+1;	

}

int OrdenarFreq(char* texto,char* cad, int* freq){		//Ordenamiento por insercion
	int i,j,k,c;
	int N=getFreq(texto,cad,freq);
	
	for(i=1;i<N;i++){
		
		k=freq[i];
		c=cad[i];
		j=i-1;
		
		while(j>=0 && freq[j]>k){
			
			freq[j+1]=freq[j];
			cad[j+1]=cad[j];
			j--;
			
		}
		freq[j+1]=k;
		cad[j+1]=c;
		
	}
	
	return N;
}
 
int main()
{
	char* texto=(char*)malloc(60*sizeof(char));
 	char* cadena=(char*)malloc(24*sizeof(char));
   	int* freq=(int*)malloc(24*sizeof(int));
 	int i,N;
 	
 	
 	printf("Ingrese el mensaje: ");
	scanf("%s",texto);
	
	
	N=OrdenarFreq(texto,cadena,freq);
	
	
    cadena=(char*)realloc(cadena,N*sizeof(char));
    freq=(int*)realloc(freq,N*sizeof(int));
    
     
    Huffman(cadena, freq, N);
 
    return 0;
}
