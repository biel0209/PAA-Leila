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

int gerarGenero()
{
    char c;
    int aux = gerarAleatorio(1,3);
    if(aux == 1) c = 'F';
    else if (aux == 2) c = 'M';
    else c = 'X';
    return c;
}

void preencherVetor(Registro *vet)
{
    char auxNome[5];
    char auxCpf[11];
    for (int i = 0; i < TAM; i++){
        strcpy(vet[i].cpf, gerarCpf());
        snprintf(auxNome, 5, "P%d", i+1);
        strcpy(vet[i].nome, auxNome);
        vet[i].genero = gerarGenero();
        vet[i].idade = gerarAleatorio(1, 80);
    }
}

void imprimirVetor(Registro *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("i: %d Nome: %s CPF: %s Genero: %c Idade: %d\n", 
                        i, vet[i].nome, vet[i].cpf,
                        vet[i].genero, vet[i].idade);
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


 
