#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define TAM 15

typedef struct registro{
    int dia, mes, ano;
    int qtd_casos;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

void preencherVetor(Registro *vet)
{
    int intersecao = (int)TAM/2;
    int ultimo_gerado = 100;
    for (int i = 0; i < TAM; i++){
            vet[i].dia = i+1;
            vet[i].mes = 3;
            vet[i].ano = 2022;
            if (i <= intersecao){
                vet[i].qtd_casos = gerarAleatorio(ultimo_gerado, 1000);
            }else{
                vet[i].qtd_casos = gerarAleatorio(0, ultimo_gerado);
            }
            ultimo_gerado = vet[i].qtd_casos;
    }
}

void imprimirVetor(Registro *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("%d/0%d/%d - Quantidade de casos: %d\n", 
                        vet[i].dia = i+1, vet[i].mes = 3, 
                        vet[i].ano = 2022, vet[i].qtd_casos);
    }
}


int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);
    return 0;
}