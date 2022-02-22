#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define TAM 10

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

void preencherVetor(int *vet)
{
    int intersecao = gerarAleatorio(0, TAM/2-1) + (int)TAM/2;
    int ultimo_gerado = 10;
    for (int i = 0; i < TAM; i++){
            if (i <= intersecao){
                vet[i] = gerarAleatorio(ultimo_gerado, 100);
            }else{
                vet[i]= __INT_MAX__ * (-1);
            }
            ultimo_gerado = vet[i];
    }
}

void imprimirVetor(int *vet)
{
    for (int i = 0; i < TAM; i++){
        printf("%d\n", vet[i]); 
    }
}

int buscarData(int *v) { 
   int e = -1, d = TAM;
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m] > v[m-1]) e = m;
      else d = m; 
   }
   return d;
}

int main()
{
    srand(time(NULL));
    int reg[TAM];
    preencherVetor(reg);
    imprimirVetor(reg);
    printf("%d\n", buscarData(reg));
    return 0;
}