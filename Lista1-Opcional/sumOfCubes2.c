#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
long long int a, b;

int testarCubos(long long int x)
{
    a = 1;
    b = (long long int)pow(x, 1.0/3.0);
    while(a <= b){
        long long int atual = a*a*a + b*b*b;
        if(atual == x){
            return 1;
        }
        if(atual < x)
            a++;
        else
            b--;
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
        if(testarCubos(x))
            vet[i] = 1; 
        else
            vet[i] = 0; 
    }
    
    for(int i=0; i<qtd_testes; i++){
        if(vet[i] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;  
}