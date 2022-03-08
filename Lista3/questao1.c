#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 8

typedef struct registro{
    char cpf[12], nome[6], genero;
    int idade;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

char* gerarCpf()
{
    char *aux = malloc(11*sizeof(char));
    for (int i = 0; i < 11; i++){
        aux[i] = gerarAleatorio(0,10) + '0';
    }
    return aux;
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
    for (int i = 0; i < TAM; i++){
        strcpy(vet[i].cpf, gerarCpf());
        vet[i].genero = gerarGenero();
        vet[i].idade = gerarAleatorio(1, 80);
        snprintf(auxNome, 5, "P%d", i+1);
        strcpy(vet[i].nome, auxNome);
        
    }
}

void imprimirVetor(Registro *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("i: %d\tNome: %s \t CPF: %s \tGenero: %c\tIdade: %d\n", 
                        i+1, vet[i].nome, vet[i].cpf, 
                        vet[i].genero, vet[i].idade);
    }
}

void trocar(Registro *vet, int maior, int i)
{
    Registro aux;
    
    strcpy(aux.cpf, vet[i].cpf);
    aux.genero = vet[i].genero;
    aux.idade = vet[i].idade;
    strcpy(aux.nome, vet[i].nome);

    strcpy(vet[i].cpf, vet[maior].cpf);
    vet[i].genero = vet[maior].genero;
    vet[i].idade = vet[maior].idade;
    strcpy(vet[i].nome, vet[maior].nome);

    strcpy(vet[maior].cpf, aux.cpf);
    vet[maior].genero = aux.genero;
    vet[maior].idade = aux.idade;
    strcpy(vet[maior].nome, aux.nome);
}


void maxHeapify(Registro *vet, int n, int i)
{
    int maior;
    int esq = 2*i, dir = 2*i + 1;
    if (esq <= n && vet[esq].idade > vet[i].idade)
        maior = esq;
    else
        maior = i;
    if (dir <= n && vet[dir].idade > vet[maior].idade)
        maior = dir;
    if (maior != i){
        trocar(vet, maior, i);  //trocar A[i] com A[maior]
        maxHeapify(vet, n, maior);
    }
}

void montaMaxHeap(Registro *vet, int n)
{
    for(int i = n/2; i>=0; i--){
        maxHeapify(vet, n, i);
    }
}

int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);
    montaMaxHeap(reg, TAM);
    printf("-----HEAP-----\n");
    imprimirVetor(reg);
    return 0;
}


 
