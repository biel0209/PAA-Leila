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

void trocar(Registro *vet, int a, int b)
{
    Registro aux;
    
    strcpy(aux.cpf, vet[b].cpf);
    aux.genero = vet[b].genero;
    aux.idade = vet[b].idade;
    strcpy(aux.nome, vet[b].nome);

    strcpy(vet[b].cpf, vet[a].cpf);
    vet[b].genero = vet[a].genero;
    vet[b].idade = vet[a].idade;
    strcpy(vet[b].nome, vet[a].nome);

    strcpy(vet[a].cpf, aux.cpf);
    vet[a].genero = aux.genero;
    vet[a].idade = aux.idade;
    strcpy(vet[a].nome, aux.nome);
}

void minHeapify(Registro *vet, int n, int i)
{
    int menor = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n){
        if(vet[esq].idade < vet[i].idade)
            menor = esq;
        if(vet[esq].idade == vet[i].idade &&
            (int) (vet[esq].genero) > (int) (vet[i].genero) ){
                menor = esq;
        }
    }

    if (dir < n){
        if(vet[dir].idade < vet[menor].idade)
            menor = dir;
        if(vet[dir].idade == vet[menor].idade &&
            (int) (vet[dir].genero) > (int) (vet[menor].genero)){
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


 
