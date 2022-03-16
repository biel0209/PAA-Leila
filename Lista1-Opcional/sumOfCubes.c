#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int buscar(long chave, long *vet, long x)
{
    for(long a=0; a<x; a++){
        if(vet[a] == chave)
            return 1;
    }
    return 0;
}

int teste()
{
    int resp=0;
    long a;
    long x = 36575; 
    float limite2 = pow(x, 1.0/3.0)+1;

    int limite = pow(x, 1.0/3.0)+1;
    long vet[limite];
    long b;


    
    for(a=1; a*a*a<x; a++){
        vet[a] = a*a*a;
    }
    
    for(b=1; b*b*b<x; b++){
        if(buscar( x-(b*b*b), vet, x) ){
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


 
