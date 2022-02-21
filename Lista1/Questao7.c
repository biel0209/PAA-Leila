#include <stdio.h>
#include <stdlib.h>
#define NA 3
#define NB 5

int nc=0;

int* intersecao(int a[], int b[], int *c, int na, int nb)
{
    for(int i=0; i<na; i++){
        for(int j=0; j<nb; j++){
            if (a[j] == b[i]){
                nc++;
            }
        }
    }
    c = malloc(nc * sizeof(int));
    nc=0;
    for(int i=0; i<na; i++){
        for(int j=0; j<nb; j++){
            if (a[j] == b[i]){
                c[nc] = b[i];
                nc++;
            }
        }
    }
    return c;
}

int main()
{
    int a[NA] = {1,3,7};
    int b[NB] = {1,2,3,6,7};
    int *c; 

    if (NA > NB)
        c = intersecao(a,b, c,NA,NB);    
    else
        c = intersecao(a,b, c,NB,NA); 

    for(int i=0; i<nc; i++) {
        printf("%d ", c[i]);  
    }
    
    return 0;
}


