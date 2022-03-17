#include <stdio.h>
#include <stdlib.h>

void trocar(int *arr, int a, int b)
{
    int aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}

int partition(int *arr, int esq, int dir)
{
    int pivo = arr[dir];
    int i = (esq - 1);
    for(int j = esq; j <= dir - 1; j++){
        if (arr[j] < pivo){
            i++;
            trocar(arr, i, j);
        }
    }
    trocar(arr, i + 1, dir);
    return i + 1;
}

void quickSort(int *arr, int esq, int dir)
{
    if (esq < dir){
        int pivo = partition(arr, esq, dir);
        quickSort(arr, esq, pivo - 1);
        quickSort(arr, pivo + 1, dir);
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

    quickSort(vet, 0, n - 1);
    
    if (varrerVetor(vet, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}