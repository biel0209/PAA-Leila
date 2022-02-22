#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 20

typedef struct no{
    char nome[5];
    int qtd_amigos;
    struct no *esquerda, *direita;
}No;

int contador=0;

No* inserir(No *reg, char *nome, int qtd_amigos){
    if(reg == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        strcpy(novo->nome, nome);
        novo->qtd_amigos = qtd_amigos;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if(qtd_amigos < reg->qtd_amigos)
            reg->esquerda = inserir(reg->esquerda, nome, qtd_amigos);
        if(qtd_amigos >= reg->qtd_amigos)
            reg->direita = inserir(reg->direita, nome, qtd_amigos);
        return reg;
    }
}

void imprimir(No *reg) {
    if(reg != NULL) { 
        imprimir(reg->direita);
        if (contador < 10){
            printf("Nome: %s - Qtd de amigos: %d\n", reg->nome, reg->qtd_amigos);
            contador++;
        }
        
        imprimir(reg->esquerda);
    }
}

int gerarAleatorio()
{
    int qtd_aleatoria = rand() % ((int)TAM/2);
    while(qtd_aleatoria == 0)
        qtd_aleatoria = rand() % ((int)TAM/2);
    return qtd_aleatoria;
}

void buscarP(No **reg)
{
    for (int i = 0; i < TAM; i++){
        char nome[5];
        snprintf (nome, 5, "P%d", i+1);
        *reg = inserir(*reg, nome, gerarAleatorio());
    }
    imprimir(*reg);
}

int main()
{
    srand(time(NULL));
    No *reg = NULL;
    buscarP(&reg);
    return 0;
}