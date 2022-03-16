#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int buscar(long long chave, long long *vet, long long x)
{
    for(long long a=0; a<=x; a++){
        if(vet[a] == chave)
            return 1;
    }
    return 0;
}

int teste()
{
    int resp=0;
    long long a;
    long long x = 703657519796; 
    int limite = pow(x, 1.0/3.0)+1;
    long long vet[8895];
    long long b;
    
    for(a=1; a*a*a<=x; a++){
        vet[a] = a*a*a;
    }
    
    for(b=1; b<=x; b++){
        if(buscar(x-(b*b*b), vet, x)){
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    //int a=2;
    //int b=3;
    //int x = 16;
    /*
    Se x=16 e a = 1, no máximo, b = raiz cubica de x - 1 
    vet[b] 
    */
    
    
    printf("resposta=%d\n",teste());
    
    return 0;
}


 
