#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    if (varrerVetor(vet2, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}