#include <stdio.h>
#include <stdlib.h>

void merge(long *vet, long esq, long m, long dir)
{
    long i, j, k;
    long n1 = m - esq + 1;
    long n2 = dir - m;
  
    long A[n1], B[n2];
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
  
void mergeSort(long *vet, long esq, long dir)
{
    if (esq < dir) {
        long m = esq + (dir - esq) / 2;
        mergeSort(vet, esq, m);
        mergeSort(vet, m + 1, dir);
        merge(vet, esq, m, dir);
    }
}

void rearranjarVetor(long *vet, long *vetRearr, int n)
{   
    
    long esq = 0;
    long dir = n-1;
    for (long i = n-1; i >= 0; i--){
        if(i % 2 == 1){
            vetRearr[i] = vet[esq];
            esq++;
        }else{
            vetRearr[i] = vet[dir];
            dir--;
        }
    }

}
int main()
{
    int qtd_testes;
    long n = 6;
    long vet[6] = {5,-2,4,8,6,5};
    long vetRearr[6];
    //scanf("%d",&qtd_testes);


    /*
    for(int i=0; i<qtd_testes; i++){
        scanf("%ld",&x);
        if(testarCubos(x))
            vet[i] = 1; 
        else
            vet[i] = 0; 
    }*/
    mergeSort(vet, 0, n-1);
    rearranjarVetor(vet, vetRearr, n);

    for (int i=0; i < n; i++)
        printf("%ld ", vetRearr[i]);
    printf("\n");
    return 0;  
}