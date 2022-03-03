#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 500
#define LIM 100

typedef struct registro{
    char nome[5];
    int qtd_amigos;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

void preencherVetor(Registro *vet)
{
    char nome[5];
    for (int i = 0; i < TAM; i++){
            snprintf(nome, 5, "P%d", i+1);
            strcpy(vet[i].nome, nome);
            vet[i].qtd_amigos = gerarAleatorio(1, TAM/2);
    }
}

void imprimirVetor(Registro *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("Nome: %s -- Quantidade de amigos: %d\n", vet[i].nome, vet[i].qtd_amigos); 
    }
}

void bubbleSort(Registro *vetor) 
{
    int k, j; 
    char auxNome[5];
    int aux;
    for (k = 1; k < TAM; k++){
        for (j = 0; j < TAM - 1; j++) {
            if (vetor[j].qtd_amigos < vetor[j+1].qtd_amigos) {

                strcpy(auxNome, vetor[j].nome);
                aux = vetor[j].qtd_amigos;

                strcpy(vetor[j].nome, vetor[j+1].nome);
                vetor[j].qtd_amigos = vetor[j+1].qtd_amigos;

                strcpy(vetor[j+1].nome, auxNome);
                vetor[j+1].qtd_amigos = aux;
            }
        }
    }
}

void maisInfluentes(Registro *reg, Registro *vet)
{
    bubbleSort(reg);
    for(int i=0; i<LIM; i++){
        strcpy(vet[i].nome, reg[i].nome);
        vet[i].qtd_amigos = reg[i].qtd_amigos;
    }
}


int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    Registro influentes[LIM];
    preencherVetor(reg);
    //imprimirVetor(reg, TAM);
    //printf("\n\n");
    maisInfluentes(reg, influentes);
    imprimirVetor(influentes, LIM);

    
    
    return 0;
}