#include <stdio.h>
#include <stdlib.h>

// estrututa nó
typedef struct no {
    int conteudo;
    struct no *esq, *dir;
} No;

No* inserir(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if(valor < raiz->conteudo)
            raiz->esq = inserir(raiz->esq, valor);
        if(valor > raiz->conteudo)
            raiz->dir = inserir(raiz->dir, valor);
        return raiz;
    }
}

int isInIntervalo(int x, int a, int b)
{
    if (x >= a && x <= b)
        return x;
    else    
        return 0;
}

int somaArv(No *r, int a, int b)
{
    if (r==NULL)
        return 0;
    else
        return isInIntervalo(r->conteudo,a,b) + somaArv(r->esq,a,b) + somaArv(r->dir,a,b);
}

int main() {
    int op, valor;
    No *raiz = NULL;

    int a = 4; //limite inferior
    int b = 7; //limite superior

    int v[10] = {2,8,3,0,9,5,4,7,10,15};
    //int v[10] = {0,9,15,92,23,84,22,5,7,3};
    
    for(int i=0; i<10; i++)
       raiz = inserir(raiz, v[i]);// não precisa da estrutura ArvB

    printf("Somatorio: %d\n", somaArv(raiz,a,b));
    return 0;  
}