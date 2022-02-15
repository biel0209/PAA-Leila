#include <stdio.h>

void selectionSort(int v[], int n)
{
    for(int i=0; i<n-1; i++){
        int menor = i;
        for(int j=i+1; j<n; j++){
            if (v[j] < v[menor])
                menor = j;
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;  
    }
}

void concatV3(int v1[], int v2[], int v3[], int n1, int n2)
{
    for(int i=0; i<n1; i++)
        v3[i] = v1[i];
    for(int i=0; i<n2; i++)
        v3[i+n1] = v2[i];

    for(int i=0; i<n1+n2; i++){
        for(int j=i+1; j<n1+n2; j++){
            if (v3[i] == v3[j])
                v3[j] = -1;
        }
    }
    selectionSort(v3, n1+n2);
}

int main()
{
    int v1[3] = {2,7,9};
    int v2[5] = {5,7,9,12,15};
    int v3[3+5];

    concatV3(v1,v2,v3,3,5); 

    for(int i=0; i<3+5; i++) {
        if (v3[i] != -1)
            printf("%d ", v3[i]);  

    }
    return 0;
}


