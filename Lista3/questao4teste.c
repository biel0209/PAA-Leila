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
        printf("-----heap min-----\n");
        imprimirVetor(heap, M);
        vetFinal[i].i = heap[0+cont].i;
        vetFinal[i].j = heap[0+cont].j;
        vetFinal[i].chave = heap[0+cont].chave;

        if(heap[0].j  < n-1){
            heap[0+cont].i = mat[heap[0+cont].i][heap[0+cont].j + 1].i;    
            heap[0+cont].chave = mat[heap[0+cont].i][heap[0+cont].j + 1].chave;
            heap[0+cont].j = mat[heap[0+cont].i][heap[0+cont].j + 1].j;

        }else{
            //trocar(heap, 0, m-1);
            //m--;
            //cont++;
            heap[0].chave = 99999999999;
        }

        //minHeapify(heap, m, 0);
        //montaMinHeap(heap, M);
        rearranjeMinHeap(heap, m);


    }
}

int main()
{
    Registro mat[M][N];
    mat[0][0].i = 0; mat[0][0].j = 0; mat[0][0].chave = 27075713615; /**/ mat[0][1].i = 0; mat[0][1].j = 1; mat[0][1].chave = 56071886688; /**/ mat[0][2].i = 0; mat[0][2].j = 2; mat[0][2].chave = 60035317476;
    mat[1][0].i = 1; mat[1][0].j = 0; mat[1][0].chave = 55223211880; /**/ mat[1][1].i = 1; mat[1][1].j = 1; mat[1][1].chave = 70562873420; /**/ mat[1][2].i = 1; mat[1][2].j = 2; mat[1][2].chave = 72565766853;
    mat[2][0].i = 2; mat[2][0].j = 0; mat[2][0].chave = 45260727281; /**/ mat[2][1].i = 2; mat[2][1].j = 1; mat[2][1].chave = 56046232043; /**/ mat[2][2].i = 2; mat[2][2].j = 2; mat[2][2].chave = 76801170320;



    Registro heap[M];
    Registro vetFinal[M*N];
    
    imprimirMatriz(mat);
    kWayMerge(mat, heap, vetFinal, M, N);
    
    printf("-----Vetor min heap-----\n");
    imprimirVetor(heap, M);
    printf("-----Vetor ordenado-----\n");
    imprimirVetor(vetFinal,  M*N);
    return 0;
}


 
