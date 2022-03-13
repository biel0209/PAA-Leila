#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 5

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

void preencherVetor(int *vet)
{
    for (int i = 0; i < TAM; i++){
        vet[i] = gerarAleatorio(1, 100);  
    }
}

void imprimirVetor(int *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("i: %d Elemento: %d\n", i+1, vet[i]);
    }
}

void trocar(int *vet, int a, int b)
{
    int aux;
    aux = vet[b];
    vet[b] = vet[a];
    vet[a] = aux;
}

void minHeapify(int *vet, int n, int i)
{
    int maior = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq] < vet[i])
        maior = esq;
    
    if (dir < n && vet[dir] < vet[maior])
        maior = dir;
   
    if (maior != i){
        trocar(vet, maior, i);  
        minHeapify(vet, n, maior);
    }
}

void montaMinHeap(int *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        minHeapify(vet, n, i);
    }
}

void buscar_k_esimo(int *vet, int n, int k)
{
    int aux[k], z;
    montaMinHeap(vet, TAM);
    for(int i = 0; i<k; i++){
        aux[i] = vet[0];
        vet[0] = __INT_MAX__;
        minHeapify(vet, k, 0);
    }
    printf("%dº menor elemento: %d\n",k, aux[k-1]);
}


int main()
{
    srand(time(NULL));
    int reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);
    int k = gerarAleatorio(1, TAM);
    printf("Buscar o %dº menor elemento\n",k);
    buscar_k_esimo(reg, TAM, k);
    return 0;
}


 
