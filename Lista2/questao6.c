#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define TAM 10

typedef struct registro{
    int chave;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

void preencherVetor(Registro *vet)
{
    int intersecao = gerarAleatorio(0, TAM/2-1) + (int)TAM/2;
    int ultimo_gerado = 100;
    for (int i = 0; i < TAM; i++){
            vet[i].chave = rand()%3 - 1;
    }
}

void imprimirVetor(Registro *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("%d\n", vet[i].chave);
    }
}

void countingSort(Registro *vet)
{
    
}

int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    countingSort(reg);
    imprimirVetor(reg);
    return 0;
}