#include <stdio.h>
#include <stdlib.h>

void countingSort(int *vet, int *vet2, int n)
{
    int maior = vet[0];
    for(int i=0; i<n; i++){
        if(vet[i] > maior)
            maior = vet[i];
    }
    int c[maior];
    for(int i=0; i<=maior; i++)
        c[i] = 0;
    for(int j=0; j<n; j++)
        c[vet[j]]++;
    for(int i=1; i<=maior; i++)
        c[i] = c[i] + c[i-1];
    for(int j=n-1; j>=0; j--){
        vet2[c[vet[j]]-1] = vet[j];
        c[vet[j]]--;
    }
}

int varrerVetor(int *vet, int n)
{
    for(int i=0; i<n-2; i++){
        if (vet[i] + vet[i+1] > vet[i+2])
            return 1;
    }
    return 0;
}

int main()
{ 
    int n;
    scanf("%d",&n);
    int vet[n], vet2[n];
    for(int i=0; i<n; i++){
        scanf("%d",&vet[i]);
    }

    countingSort(vet,vet2,n);

    if (varrerVetor(vet2, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}