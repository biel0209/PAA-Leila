#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 3 //quantidade de lojas
#define N 3 //quantidade de clientes por loja

typedef struct registro{
    int i, j;
    long chave;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}


void preencherVetor(Registro mat[][N])
{
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            mat[i][j].chave = gerarAleatorio(1, 1000);
        }
    }
}

void trocar(Registro *vet, int a, int b)
{
    Registro aux;
    aux.i = vet[b].i;
    aux.j = vet[b].j;
    aux.chave = vet[b].chave;

    vet[b].i = vet[a].i;
    vet[b].j = vet[a].j;
    vet[b].chave = vet[a].chave;


    vet[a].i = aux.i;
    vet[a].j = aux.j;
    vet[a].chave = aux.chave;

}

void imprimirMatriz(Registro mat[][N])
{
    for (int i = 0; i < M; i++){
        printf("-----Loja %d-----\n", i+1);
        for(int j = 0; j < N; j++){
            printf("elemento: %ld\n", mat[i][j].chave);
        }
    }
}

void imprimirVetor(Registro *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("elemento: %ld\n", 
                    vet[i].chave);
    }
}

void minHeapify(Registro *vet, int n, int i)
{
    int menor = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq].chave < vet[i].chave)
        menor = esq;
    
    if (dir < n && vet[dir].chave < vet[menor].chave)
        menor = dir;
   
    if (menor != i){
        trocar(vet, menor, i);  
        minHeapify(vet, n, menor);
    }
}


void montaMinHeap(Registro *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        minHeapify(vet, n, i);
    }
}



void rearranjeMinHeap(Registro *vet, int n)
{
    int pai = 0, filho = 1;
    while(filho <= n-1){
        if(vet[filho].chave > vet[filho+1].chave) filho++;
        if(vet[filho].chave < vet[pai].chave){
            trocar(vet, filho, pai);
            pai = filho;
            filho = 2*filho;
        }else{
            filho = n;
        }
    }
}

void kWayMerge(Registro mat[][N], Registro *heap, Registro *vetFinal, int m, int n)
{
    int tamV = m*n; //tamanho que o vetor final terá
    for (int i=0; i<m; i++){
        heap[i].i = mat[i][0].i;
        heap[i].j = mat[i][0].j;
        heap[i].chave = mat[i][0].chave;
    }
    montaMinHeap(heap, M);
    
    int cont=0;
    for (int i=0; i<tamV; i++){ 
        //printf("-----heap min-----\n");
        //imprimirVetor(heap, M);
        vetFinal[i].i = heap[0+cont].i;
        vetFinal[i].j = heap[0+cont].j;
        vetFinal[i].chave = heap[0+cont].chave;

        if(heap[0].j  < n-1){
            int auxI = heap[0+cont].i;
            int auxJ = heap[0+cont].j;
            heap[0+cont].i = mat[auxI][auxJ + 1].i;    
            heap[0+cont].chave = mat[auxI][auxJ + 1].chave;
            heap[0+cont].j = mat[auxI][auxJ + 1].j;

        }else{
            //trocar(heap, 0, m-1);
            //m--;
            //cont++;
            heap[0].chave = 9999;
        }
        minHeapify(heap, m, 0);
    }
}

void maxHeapify(Registro *vet, int n, int i)
{
    int maior = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq].chave > vet[i].chave)
        maior = esq;
    
    if (dir < n && vet[dir].chave > vet[maior].chave)
        maior = dir;
   
    if (maior != i){
        trocar(vet, maior, i);  
        maxHeapify(vet, n, maior);
    }
}


void montaMaxHeap(Registro *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        maxHeapify(vet, n, i);
    }
}

void heapSortMax(Registro *vet, int n)
{
    montaMaxHeap(vet, n);
    for (int i=n-1; i>=1; i--){
        trocar(vet, 0, i);
        maxHeapify(vet, i, 0);
    }
}

void ordenarVetores(Registro mat[M][N])
{
    for (int i=0; i<M; i++){
        heapSortMax(mat[i], N);
    }
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            mat[i][j].i = i;
            mat[i][j].j = j;
        }
    }
}

int main()
{
    Registro mat[M][N];
 
    srand(time(NULL));

    Registro heap[M];
    Registro vetFinal[M*N];

    preencherVetor(mat);
    ordenarVetores(mat);
    imprimirMatriz(mat);
    kWayMerge(mat, heap, vetFinal, M, N);
    
    printf("-----Vetor min heap-----\n");
    imprimirVetor(heap, M);
    printf("-----Vetor ordenado-----\n");
    imprimirVetor(vetFinal,  M*N);
    return 0;
}


 
