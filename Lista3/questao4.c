#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define  QTD_L 5 //quantidade de lojas
#define QTD_C 5 //quantidade de clientes por loja

typedef struct data{
    int dia, mes, ano;
}Data;

typedef struct registro{
    long cpf, telefone;             
    char nome[15], email[45];
    Data data_nascimento;  
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

long gerarCpf()
{
    char *aux = malloc(11*sizeof(char));
    char *ptr;
    for (int i = 0; i < 11; i++){
        if(i==0)
            aux[i] = gerarAleatorio(1,9) + '0';
        else
            aux[i] = gerarAleatorio(0,9) + '0';
    }
    return atol(aux);
}

void preencherVetor(Registro vet[][QTD_C])
{
    char auxNome[15], auxEmail[45];
    for (int i = 0; i < QTD_L; i++){
        for(int j = 0; j < QTD_C; j++){
            snprintf(auxNome, 15, "P%d%d", i+1,j+1);
            strcpy(vet[i][j].nome, auxNome);
            snprintf(auxEmail, 45, "P%d%d@example.com", i+1, j+1);
            strcpy(vet[i][j].email, auxEmail);
            vet[i][j].cpf = gerarCpf();
            vet[i][j].telefone = gerarAleatorio(100000000, 899999999);
            vet[i][j].data_nascimento.dia = gerarAleatorio(1, 30);
            vet[i][j].data_nascimento.mes = gerarAleatorio(1, 12);
            vet[i][j].data_nascimento.ano = gerarAleatorio(1950, 54);
        }
    }
}

void imprimirVetor(Registro vet[][QTD_C])
{
    for (int i = 0; i < QTD_L; i++){
        printf("-----Loja %d-----\n", i+1);
        for(int j = 0; j < QTD_C; j++){
            printf("CPF: %ld\tNome: %s\tNascimento: %d/%d/%d\tEmail: %s\tTelefone: %ld\n", 
                        vet[i][j].cpf, vet[i][j].nome, vet[i][j].data_nascimento.dia,
                        vet[i][j].data_nascimento.mes, vet[i][j].data_nascimento.ano,
                        vet[i][j].email, vet[i][j].telefone);
        }
    }
}

void trocar(Registro *vet, int a, int b)
{
    Registro aux;
    
    strcpy(aux.email, vet[b].email);
    aux.cpf = vet[b].cpf;
    aux.telefone = vet[b].telefone;
    strcpy(aux.nome, vet[b].nome);
    aux.data_nascimento.dia = vet[b].data_nascimento.dia;
    aux.data_nascimento.mes = vet[b].data_nascimento.mes;
    aux.data_nascimento.ano = vet[b].data_nascimento.ano;

    strcpy(vet[b].email, vet[a].email);
    vet[b].cpf = vet[a].cpf;
    vet[b].telefone = vet[a].telefone;
    strcpy(vet[b].nome, vet[a].nome);
    vet[b].data_nascimento.dia = vet[a].data_nascimento.dia;
    vet[b].data_nascimento.mes = vet[a].data_nascimento.mes;
    vet[b].data_nascimento.ano = vet[a].data_nascimento.ano;

    strcpy(vet[a].email, aux.email);
    vet[a].cpf = aux.cpf;
    vet[a].telefone = aux.telefone;
    strcpy(vet[a].nome, aux.nome);
    vet[a].data_nascimento.dia = aux.data_nascimento.dia;
    vet[a].data_nascimento.mes = aux.data_nascimento.mes;
    vet[a].data_nascimento.ano = aux.data_nascimento.ano;
}

void minHeapify(Registro *vet, int n, int i)
{
    int menor = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq].cpf < vet[i].cpf)
        menor = esq;
    
    if (dir < n && vet[dir].cpf < vet[menor].cpf)
        menor = dir;
   
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

void ordenarVetores(Registro vet[QTD_L][QTD_C])
{
    for (int i=0; i<QTD_L; i++){
        heapSort(vet[i], QTD_C);
    }
}

int main()
{
    srand(time(NULL));
    Registro vet[QTD_L][QTD_C];
    preencherVetor(vet);
    ordenarVetores(vet);
    imprimirVetor(vet);
    return 0;
}


 
