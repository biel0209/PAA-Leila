#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 20
#define LIM 8

typedef struct registro{
    char nome[5];
    int qtd_amigos;
}Registro;

typedef struct list{
    int conteudo;
    int tamanho;
    struct list *prox;
}List;

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

void insere(List **lista, int valor)
{
    List *novo = malloc(sizeof(List));
    if(novo){
        novo->conteudo = valor;
        novo->prox = *lista;
        *lista = novo;
    }
}

void imprimirLista(List *lista)
{
    List *aux = lista;
    while(aux){
        printf("%d -> ",aux->conteudo);
        aux = aux->prox;
    }
    printf("\n");

}

int buscarMaior(Registro *vet, int n, int indice)
{
    if (n == 0){
        return indice;
    }
    if(vet[n].qtd_amigos > vet[indice].qtd_amigos){
        indice = n;
    }
    return buscarMaior(vet, n-1, indice);
}

int tamanhoLista=0;

List* buscarIguais(Registro *vet, int n, int chave, int contador, List *listaAux)
{
    if (n < 0)
        return listaAux;
    if(vet[n].qtd_amigos == chave){
        insere(&listaAux, n);
        tamanhoLista++;
    }
    return buscarIguais(vet, n-1, chave, contador, listaAux);
}

int sortearPessoa(List *lista)
{
    List *aux = lista;
    int num = gerarAleatorio(0, tamanhoLista);
    int p=0;
    while(aux && p<num){
        aux = aux->prox;
        p++;
    }
    return aux->conteudo;
}

int maisInfluentes(Registro *reg, Registro *vet, int contador)
{
    
    if (contador == LIM)
        return -1;
    else{
        int indice = buscarMaior(reg, TAM-1, 0); 
        if (contador >= 2){
            List *listaAux = NULL;
            listaAux = buscarIguais(reg, TAM-1, reg[indice].qtd_amigos, contador, listaAux);
            int sorteada = sortearPessoa(listaAux);
            strcpy(vet[contador].nome, reg[sorteada].nome);
            vet[contador].qtd_amigos = reg[sorteada].qtd_amigos;
            reg[sorteada].qtd_amigos = -1;
            //imprimirLista(listaAux);
            //printf("%d\n",tamanhoLista);
        }else{
            strcpy(vet[contador].nome, reg[indice].nome);
            vet[contador].qtd_amigos = reg[indice].qtd_amigos;
            reg[indice].qtd_amigos = -1;
            
            //printf("indice do maior: %d\n",indice);
        }
        contador++;
        tamanhoLista=0;
        
        return maisInfluentes(reg, vet, contador);
    }
}

int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    Registro influentes[LIM];
    preencherVetor(reg);
    printf("--------------------VETOR ORIGINAL-------------------------\n");
    imprimirVetor(reg, TAM);
    maisInfluentes(reg, influentes, 0);
    printf("\n--------------------MAIS INFLUENTES-------------------------\n");
    imprimirVetor(influentes, LIM);    

    return 0;
}