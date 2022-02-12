#include <stdio.h>

int isNegative(int num)
{
    if(num < 0) 
        return 1;
    else 
        return 0;
}

/*
OBS: na linha 21, é calculado isNegative do vetor da posição n-1 porque não exite a posição n no vetor,
pois a indexação em C começa no 0.
*/
int qtdNegativos(int v[], int n)
{
    if(n==0) 
        return 0;
    else 
        return isNegative(v[n-1]) + qtdNegativos(v, n-1);
}

int main()
{
    int n = 3;
    int v[n];
    
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    
    printf("Quantidade de negativos: %d\n", qtdNegativos(v, n));
    return 0;
}


