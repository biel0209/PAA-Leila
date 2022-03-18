#include <stdio.h>
#include <stdlib.h>

void merge(int *vet, int esq, int m, int dir)
{
    int i, j, k;
    int n1 = m - esq + 1;
    int n2 = dir - m;
  
    int A[n1], B[n2];
    for (i = 0; i < n1; i++)
        A[i] = vet[esq + i];
    for (j = 0; j < n2; j++)
        B[j] = vet[m + 1 + j];
  
    i = 0, j = 0; 
    k = esq; 
    while (i < n1 && j < n2) {
        if (A[i] <= B[j]) {
            vet[k] = A[i];
            i++;
        }
        else {
            vet[k] = B[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        vet[k] = A[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        vet[k] = B[j];
        j++;
        k++;
    }
}
  
void mergeSort(int *vet, int esq, int dir)
{
    if (esq < dir) {
        int m = esq + (dir - esq) / 2;
        mergeSort(vet, esq, m);
        mergeSort(vet, m + 1, dir);
        merge(vet, esq, m, dir);
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
    
    mergeSort(vet, 0, n - 1);
    
    if (varrerVetor(vet, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
