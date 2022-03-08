#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define TAM 10

typedef struct registro{
    char cpf[11], nome[5], genero;
    int idade;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

char* gerarCpf()
{
    
}

void preencherVetor(Registro *vet)
{
    char auxNome[5];
    char auxCpf[11];
    for (int i = 0; i < TAM; i++){
            strcpy(vet[i].cpf, gerarCpf());
            snprintf(auxNome, 5, "P%d", i+1);
            strcpy(vet[i].nome, auxNome);
            vet[i].genero = i+1;
            vet[i].idade = gerarAleatorio(1, 80);
    }
}

void imprimirVetor(Registro *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("%d/0%d/%d - Quantidade de casos: %d\n", 
                        vet[i].dia, vet[i].mes, 
                        vet[i].ano, vet[i].qtd_casos);
    }
}



int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);


    return 0;
}


 
