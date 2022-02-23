#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 10

typedef struct registro{
    char nome[5];
    int qtd_amigos;
    struct registro *prox;
}Registro;

void insere (Registro **p, char *nome, int qtd_amigos)
{
    Registro *aux = malloc (sizeof (Registro));
    strcpy(aux->nome, nome); 
    aux->qtd_amigos = qtd_amigos;
    aux->prox = *p;
    *p = aux;

}

void imprimirInfluentes (Registro *p, int limite){
    if (p != NULL){
        printf("\n----Os %d mais influentes\n", limite);
        while (p && limite != 0){
            printf("Nome: %s - Qtd de amigos: %d\n", p->nome, p->qtd_amigos);
            p = p->prox;
            limite--;
        }
    }
}

void ordenar(Registro *p)
{
    Registro *pi; //referencia do primeiro da fila
    Registro *pj; //referencia do nó que varrerá a fila
    Registro *pfim = NULL; //referencia do ultimo da fila

    for(pi=p; pi->prox != NULL; pi = pi->prox){
        for(pj=p; pj->prox != pfim; pj = pj->prox){
            if ( pj->qtd_amigos < pj->prox->qtd_amigos ){
                char auxNome[5];
                strcpy(auxNome, pj->nome);
                int auxQtd = pj->qtd_amigos;

                strcpy(pj->nome, pj->prox->nome);
                pj->qtd_amigos = pj->prox->qtd_amigos;

                strcpy(pj->prox->nome, auxNome);
                pj->prox->qtd_amigos = auxQtd;
            }
        }
        pfim = pj;
    }
}

int gerarAleatorio()
{
    int qtd_aleatoria = rand() % ((int)TAM/2);
    while(qtd_aleatoria == 0)
        qtd_aleatoria = rand() % ((int)TAM/2);
    return qtd_aleatoria;
}

void buscarP(Registro **reg)
{
    for (int i = 0; i < TAM; i++){
        char nome[5];
        snprintf (nome, 5, "P%d", i+1 );
        insere(reg, nome, gerarAleatorio());
    }
    ordenar(*reg);
    imprimirInfluentes(*reg, 100);
}
/*
Algoritmo buscarP(reg)
{- Entrada: vetor reg cujos registros possuem os campos nome e
  qtd_amigos 
  Saída: impressão dos 100 primeiros registros do vetor reg ordenado
  de forma decrescente pela quantidade de amigos-}

    início
        
    fim
*/
int main()
{
    srand(time(NULL));
    Registro *reg = NULL;
    
    buscarP(&reg);
    return 0;
}