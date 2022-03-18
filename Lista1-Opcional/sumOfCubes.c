#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
 
int buscar(long long int chave, long long int vet[], long long int x)
{
    
    for(long a=0; (a*a*a)<x; a++){
        if(vet[a] == chave)
            return 1;
    }
    return 0;
}
 
int teste(long long int x)
{
    long limite = pow(x, 1.0/3.0)+1;
    long long int vet[limite];
    for(long a=1; a<=limite; a++)
        vet[a-1] = (a*a*a);
    for(long b=1; b<=limite; b++){
        if( buscar(x-(b*b*b), vet, x) )
            return 1;
    }
    return 0;
}
 
int main()
{
    int qtd_testes;
    long long int x;
    scanf("%d",&qtd_testes);
    int vet[qtd_testes];
    for(int i=0; i<qtd_testes; i++){
        scanf("%lld",&x);
        if(teste(x))
            vet[i] = 1; 
        else
            vet[i] = 0; 
    }
    //dfdfg
 
    
    for(int i=0; i<qtd_testes; i++){
        if(vet[i] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    
    return 0;
    
}