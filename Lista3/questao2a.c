
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
        vet[i] = gerarAleatorio(0, 100);
    }
}

void imprimirVetor(int *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("i: %d\tElemento: %d\n", i+1, vet[i]);
    }
}

void trocar(int *vet, int a, int b)
{
    int aux;
    aux = vet[b];
    vet[b] = vet[a];
    vet[a] = aux;
}

void maxHeapify(int *vet, int n, int i)
{
    int maior = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq] > vet[i])
            maior = esq;

    if (dir < n && vet[dir] > vet[maior])
            maior = dir;
   
    if (maior != i){
        trocar(vet, maior, i);  
        maxHeapify(vet, n, maior);
    }
}

void montaMaxHeap(int *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        maxHeapify(vet, n, i);
    }
}

void rearranjeMaxHeap(int *vet, int n, int k)
{
    int pai = k, filho = k+1;
    while(filho <= n-1){
        if(vet[filho] < vet[filho+1]) filho++;
        if(vet[filho] > vet[pai]){
            trocar(vet, filho, pai);
            pai = filho;
            filho = 2*filho;
        }else{
            filho = n;
        }
    }
}

void removeMaxHeap(int *vet, int n, int k)
{
    if (n==0)
        printf("heap vazio!");
    else{
        trocar(vet, k, n-1);
        n--;
        rearranjeMaxHeap(vet, n, k);
    }
}

void buscarMenor(int *vet, int n)
{
    int iMenor = 0;
    for(int i = n/2; i<n; i++){
        if(vet[iMenor] > vet[i])
            iMenor = i;
    }
    removeMaxHeap(vet, n, iMenor);
}


int main()
{
    srand(time(NULL));
    int reg[TAM];
    preencherVetor(reg);
    montaMaxHeap(reg, TAM);
    printf("-----HEAP-----\n");
    imprimirVetor(reg, TAM);
    printf("-----REMOCAO-----\n");
    buscarMenor(reg, TAM);
    imprimirVetor(reg, TAM-1);
    return 0;
}


 
