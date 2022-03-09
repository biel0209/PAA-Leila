#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 20

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

void trocar(Registro *vet, int menor, int i)
{
    Registro aux;
    
    strcpy(aux.cpf, vet[i].cpf);
    aux.genero = vet[i].genero;
    aux.idade = vet[i].idade;
    strcpy(aux.nome, vet[i].nome);

    strcpy(vet[i].cpf, vet[menor].cpf);
    vet[i].genero = vet[menor].genero;
    vet[i].idade = vet[menor].idade;
    strcpy(vet[i].nome, vet[menor].nome);

    strcpy(vet[menor].cpf, aux.cpf);
    vet[menor].genero = aux.genero;
    vet[menor].idade = aux.idade;
    strcpy(vet[menor].nome, aux.nome);
}

void minHeapify(Registro *vet, int n, int i)
{
    int menor = i;
    int esq = 2*i;
    int dir = (2*i)+1;
    if (esq < n){
        if(vet[esq].idade < vet[i].idade)
            menor = esq;
        else if(vet[esq].idade == vet[i].idade){
            if( (int) (vet[esq].genero) > (int) (vet[i].genero))
                menor = esq;
        }
    }

    if (dir < n){
        if(vet[dir].idade < vet[menor].idade)
            menor = dir;
        else if(vet[dir].idade == vet[menor].idade){
            if( (int) (vet[dir].genero) > (int) (vet[menor].genero))
                menor = dir;
        }
    }
   
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

void heapSort(Registro *vet, int n)
{
    montaMinHeap(vet, n);
    for (int i=n-1; i>=1; i--){
        trocar(vet, 0, i);
        minHeapify(vet, i, 0);
    }
}

int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    heapSort(reg, TAM);
    printf("-----HEAP-----\n");
    imprimirVetor(reg);
    return 0;
}


 
