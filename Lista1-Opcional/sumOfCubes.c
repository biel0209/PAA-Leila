#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int teste()
{
    int resp=0;
    int a;
    double x = 1; 
    int b;
    int limite = pow(x, 1.0/3.0)+1;
    for(a=1; a<=limite; a++){
        for(b=1; b<=limite; b++){
            int aux = pow(a, 3) + pow(b, 3);
            if(aux == x){
                printf("x=%.0f\ta=%d\tb=%d\n",x,a,b);
                return 1;
            }
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


 
