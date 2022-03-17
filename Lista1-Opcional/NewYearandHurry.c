#include <stdio.h>
 
int main()
{
    int totalMinutos = 4*60;  
    int n, k;
    scanf("%d",&n);
    scanf("%d",&k);
    int tempoGasto = 0;
    int aux;
    int cont=0;
    int i=1;
    while(i<=n && tempoGasto + k <= totalMinutos){
        aux = tempoGasto + 5*i;
        if(aux + k <= totalMinutos){
            tempoGasto = tempoGasto + 5*i;   
            cont++; 
        }
        i++;
    }
    printf("%d\n",cont);
    return 0;
}