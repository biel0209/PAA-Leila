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

void preencherVetor(int *vet, int n)
{
    for(int i=0; i<n; i++){
        scanf("%d",&vet[i]);
    }
}

int main()
{
    int qtd_testes;
    scanf("%d",&qtd_testes);
    for(int i=0; i<qtd_testes; i++){
        int lenght;
        scanf("%d",&lenght);
        int vet[lenght];
        preencherVetor(vet, lenght);
        mergeSort(vet, 0, lenght-1);
        for (int i=lenght-1; i >= 0; i--)
            printf("%d ", vet[i]);
        printf("\n");
    }
    return 0;  
}