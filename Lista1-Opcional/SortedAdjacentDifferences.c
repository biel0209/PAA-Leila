#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void bubbleSort2(long *vet, int n)
{
    for (int i = 0; i < n; i++){  
        for (int j = 0; j < n-2; j++){
            if (abs(vet[j]-vet[j+1]) > abs(vet[j+1]-vet[j+2])){
                long temp = vet[j];
                vet[j] = vet[j+2];
                vet[j+2] = temp;
            }
        }
   }
}

void bubbleSort(long *vet, int n)
{
    for (int i = 0; i < n-1; i++){  
        for (int j = 0; j < n-i-1; j++){
            if (vet[j] > vet[j+1]){
                long temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
   }
   
}

void rearranjarVetor(long *vet, long *vetRearr, int n)
{   
    
    for (long i = 0, k=0; i < n; i+=2){
        long menorDiferenca = labs(vet[0]-vet[1]);
        long index = 0;
        for (long j = 1; j < n-1; j++){
            if (labs(vet[j]-vet[j+1]) < menorDiferenca){
                menorDiferenca = labs(vet[j]-vet[j+1]);
                index = j;
            }
        }
        vetRearr[i] = vet[index];
        vetRearr[i+1] = vet[index+1];

        
        /*for (int i=0; i < n; i++)
            printf("%ld ", vetRearr[i]);
        printf("\n");*/
    }

}
 
int main()
{
    int qtd_testes;
    long n = 10;
    long vet[10] = {9, 0, 5, 3, 7, 2, 3, 8, 10, 15};
    long vetRearr[10];
    //scanf("%d",&qtd_testes);


    /*
    for(int i=0; i<qtd_testes; i++){
        scanf("%ld",&x);
        if(testarCubos(x))
            vet[i] = 1; 
        else
            vet[i] = 0; 
    }*/
    rearranjarVetor(vet, vetRearr, n);

    for (int i=0; i < n; i++)
        printf("%ld ", vetRearr[i]);
    printf("\n");
    
    

    return 0;  
}