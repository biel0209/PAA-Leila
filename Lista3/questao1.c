#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

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
    int maior = i;
    int esq = 2*i;
    int dir = (2*i)+1;
    if (esq < n){
        if(vet[esq].idade > vet[i].idade)
            maior = esq;
        else if(vet[esq].idade == vet[i].idade){
            if( (int) (vet[esq].genero) < (int) (vet[i].genero))
                maior = esq;
        }
    }

    if (dir < n){
        if(vet[dir].idade > vet[maior].idade)
            maior = dir;
        else if(vet[dir].idade == vet[maior].idade){
            if( (int) (vet[dir].genero) < (int) (vet[maior].genero))
                maior = dir;
        }
    }
   
    if (maior != i){
        trocar(vet, maior, i);  
        maxHeapify(vet, n, maior);
    }
}

void montaMaxHeap(Registro *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        maxHeapify(vet, n, i);
    }
}

void heapSort(Registro *vet, int n)
{
    montaMaxHeap(vet, n);
    for (int i=n-1; i>=0; i--){
        trocar(vet, 0, i);
        maxHeapify(vet, i, 0);
    }
}

int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    /*
    strcpy(reg[0].nome, "P1");
    strcpy(reg[0].cpf, "36753562912");
    reg[0].idade = 52;
    reg[0].genero = 'M';

    strcpy(reg[1].nome, "P2");
    strcpy(reg[1].cpf, "93606261879");
    reg[1].idade = 52;
    reg[1].genero = 'X';
    
    strcpy(reg[2].nome, "P3");
    strcpy(reg[2].cpf, "23759228973");
    reg[2].idade = 112;
    reg[2].genero = 'M';

    strcpy(reg[3].nome, "P4");
    strcpy(reg[3].cpf, "29319478450");
    reg[3].idade = 52;
    reg[3].genero = 'F';

    strcpy(reg[4].nome, "P5");
    strcpy(reg[4].cpf, "29119478450");
    reg[4].idade = 45;
    reg[4].genero = 'X';
    */
    
    heapSort(reg, TAM);
    printf("-----HEAP-----\n");
    imprimirVetor(reg);
    return 0;
}


 
