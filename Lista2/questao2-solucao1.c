#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 10
#define LIM 5

typedef struct registro{
    char nome[5];
    int qtd_amigos;
}Registro;

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

void bubbleSort(Registro *vetor) 
{
    int k, j; 
    char auxNome[5];
    int aux;
    for (k = 1; k < TAM; k++){
        for (j = 0; j < TAM - 1; j++) {
            if (vetor[j].qtd_amigos < vetor[j+1].qtd_amigos) {

                strcpy(auxNome, vetor[j].nome);
                aux = vetor[j].qtd_amigos;

                strcpy(vetor[j].nome, vetor[j+1].nome);
                vetor[j].qtd_amigos = vetor[j+1].qtd_amigos;

                strcpy(vetor[j+1].nome, auxNome);
                vetor[j+1].qtd_amigos = aux;
            }
        }
    }
}

int buscarIguais(Registro *vet, int n, int chave, int contador, int indice)
{
    
    if (contador > n){
        
        return indice;
    }
    if(vet[n].qtd_amigos == chave){
        indice=n;
    }
    return buscarIguais(vet, n-1, chave, contador, indice);
}

int ignorarIguais(Registro *vet, int contador, int indice)
{
    
    if (contador <= indice){
        vet[contador].qtd_amigos = -1;
        contador++;
        return ignorarIguais(vet, contador, indice);
    }else{
        return 0;
    }
}

int maisInfluentes(Registro *reg, Registro *vet, int contador, int contador2)
{
    if(contador==LIM)
        return -1;
    else{
        if(contador==0)
            bubbleSort(reg);
        if(contador>=3 && reg[contador].qtd_amigos == reg[contador+1].qtd_amigos){
            int indice = buscarIguais(reg, TAM-1, reg[contador2].qtd_amigos, contador, -1);
            int sorteado = gerarAleatorio(contador, indice);
            strcpy(vet[contador].nome, reg[sorteado].nome);
            vet[contador].qtd_amigos = reg[sorteado].qtd_amigos;
            //int temp = ignorarIguais(reg, contador, indice);
            contador2 = indice+1; 
            
        }else{
            strcpy(vet[contador].nome, reg[contador].nome);
            vet[contador].qtd_amigos = reg[contador].qtd_amigos;
            contador2++;
        }
        contador++;
        return maisInfluentes(reg, vet, contador, contador2);
    }
}


int main()
{
    srand(time(NULL));
    Registro reg[TAM];
    Registro influentes[LIM];
    preencherVetor(reg);
    
    imprimirVetor(reg, TAM);
    printf("\n\n");
    maisInfluentes(reg, influentes,0,0);
    
    imprimirVetor(influentes, LIM);
    return 0;
}
