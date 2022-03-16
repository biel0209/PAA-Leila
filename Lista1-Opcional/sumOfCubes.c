#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

int buscar(long chave, long *vet, long x)
{
    for(long a=0; a*a*a<x; a++){
        if(vet[a] == chave)
            return 1;
    }
    return 0;
}

int teste(long x)
{
    int limite = pow(x, 1.0/3.0)+1;
    long vet[limite];
    for(long a=1; a*a*a<x; a++)
        vet[a] = a*a*a;
    for(long b=1; b*b*b<x; b++){
        if( buscar(x-(b*b*b), vet, x) )
            return 1;
    }
    
    return 0;
}

int main()
{
    clock_t t = clock();

    //Algoritmo
    int qtd_testes;
    long x;
    scanf("%d",&qtd_testes);
    for(int i=0; i<qtd_testes; i++){
        scanf("%ld",&x);
        if(teste(x))
            printf("YES\n");
        else
            printf("NO\n");

    }
    //Algoritmo
    
    double Tempo = (clock() - t) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.\n", Tempo);
    return 0;
}


 
