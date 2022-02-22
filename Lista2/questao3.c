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
    int intersecao = gerarAleatorio(0, TAM/2-1) + (int)TAM/2;
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

int buscarData(Registro *v) { 
   int e = -1, d = TAM; // atenção!
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m].qtd_casos > v[m-1].qtd_casos) e = m;
      else d = m; 
   }
   return d;
}

int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);
    int indice = buscarData(reg)-1;
    printf("Dia com mais casos: %d/0%d/%d - Quantidade de casos: %d\n", 
        reg[indice].dia, reg[indice].mes, reg[indice].ano, reg[indice].qtd_casos);    
    return 0;
}