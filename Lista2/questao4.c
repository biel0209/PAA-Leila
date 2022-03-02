#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 10

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

void preencherVetor(int *vet)
{
    int intersecao = gerarAleatorio(0, (TAM/2)-1) + (int)TAM/2;
    int ultimo_gerado = 10;
    for (int i = 0; i < TAM; i++){
            if (i <= intersecao){
                vet[i] = gerarAleatorio(ultimo_gerado, 100);
            }else{
                vet[i]= (-1) * gerarAleatorio(1,100);
            }
            ultimo_gerado = vet[i];
    }
}

void imprimirVetor(int *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("Posicao: %d -- Chave: %d\n", i,vet[i]); 
    }
}

int buscaBinaria(int *v, int e, int d)
{    
    if (e > d) return -1;
    int m = (e + d)/2;  
    if (v[m] > 0 && v[m+1] < 0) return m;
    else{
        if (v[m] > 0)
            return buscaBinaria(v,m+1,d);
        else
            return buscaBinaria(v,e,m-1);
    }
    
}

int buscarLimites(int *vet)
{   
    int inferior=0, superior=1;
    int val = vet[0];
    while(val > 0){
        inferior = superior;
        superior = superior*2;
        val = vet[superior];
    }
    return buscaBinaria(vet, inferior, superior);
}

int main()
{
    srand(time(NULL));
    int reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);

    int indice = buscarLimites(reg);
    printf("Indice do último elemento válido: %d\n", indice);

    return 0;
}