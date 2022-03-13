#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 2 //quantidade de lojas
#define N 3 //quantidade de clientes por loja
#define ANO_ATUAL 2022
#define MES_ATUAL 3 //março

typedef struct data{
    int dia, mes, ano;
}Data;

typedef struct registro{
    long cpf, telefone;             
    char nome[15], email[45];
    int i, j;
    Data data_nascimento;  
    int idade;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

long gerarCpf()
{
    char *aux = malloc(11*sizeof(char));
    char *ptr;
    for (int i = 0; i < 11; i++){
        if(i==0)
            aux[i] = gerarAleatorio(1,9) + '0';
        else
            aux[i] = gerarAleatorio(0,9) + '0';
    }
    return atol(aux);
}

void preencherMatriz(Registro mat[][N])
{
    char auxNome[15], auxEmail[45];
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            snprintf(auxNome, 15, "P%d%d", i+1,j+1);
            strcpy(mat[i][j].nome, auxNome);
            snprintf(auxEmail, 45, "P%d%d@example.com", i+1, j+1);
            strcpy(mat[i][j].email, auxEmail);
            mat[i][j].cpf = gerarCpf();
            mat[i][j].telefone = gerarAleatorio(100000000, 899999999);
            mat[i][j].data_nascimento.dia = gerarAleatorio(1, 30);
            mat[i][j].data_nascimento.mes = gerarAleatorio(1, 12);
            mat[i][j].data_nascimento.ano = gerarAleatorio(1950, 54);
        }
    }
}

void imprimirMatriz(Registro mat[][N])
{
    for (int i = 0; i < M; i++){
        printf("-----Loja %d-----\n", i+1);
        for(int j = 0; j < N; j++){
            printf("CPF: %ld\tNome: %s\tNascimento: %d/%d/%d\tEmail: %s\tTelefone: %ld\n", 
                        mat[i][j].cpf, mat[i][j].nome, mat[i][j].data_nascimento.dia,
                        mat[i][j].data_nascimento.mes, mat[i][j].data_nascimento.ano,
                        mat[i][j].email, mat[i][j].telefone);
        }
    }
}

void imprimirVetor(Registro *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("CPF: %ld\tNome: %s\tNascimento: %d/%d/%d\tEmail: %s\tTelefone: %ld\n", 
                    vet[i].cpf, vet[i].nome, vet[i].data_nascimento.dia,
                    vet[i].data_nascimento.mes, vet[i].data_nascimento.ano,
                    vet[i].email, vet[i].telefone);
        
    }
}

void trocar(Registro *vet, int a, int b)
{
    Registro aux;
    
    strcpy(aux.email, vet[b].email);
    aux.cpf = vet[b].cpf;
    aux.telefone = vet[b].telefone;
    strcpy(aux.nome, vet[b].nome);
    aux.data_nascimento.dia = vet[b].data_nascimento.dia;
    aux.data_nascimento.mes = vet[b].data_nascimento.mes;
    aux.data_nascimento.ano = vet[b].data_nascimento.ano;
    aux.i = vet[b].i;
    aux.j = vet[b].j;

    strcpy(vet[b].email, vet[a].email);
    vet[b].cpf = vet[a].cpf;
    vet[b].telefone = vet[a].telefone;
    strcpy(vet[b].nome, vet[a].nome);
    vet[b].data_nascimento.dia = vet[a].data_nascimento.dia;
    vet[b].data_nascimento.mes = vet[a].data_nascimento.mes;
    vet[b].data_nascimento.ano = vet[a].data_nascimento.ano;
    vet[b].i = vet[a].i;
    vet[b].j = vet[a].j;

    strcpy(vet[a].email, aux.email);
    vet[a].cpf = aux.cpf;
    vet[a].telefone = aux.telefone;
    strcpy(vet[a].nome, aux.nome);
    vet[a].data_nascimento.dia = aux.data_nascimento.dia;
    vet[a].data_nascimento.mes = aux.data_nascimento.mes;
    vet[a].data_nascimento.ano = aux.data_nascimento.ano;
    vet[a].i = aux.i;
    vet[a].j = aux.j;
}

void maxHeapify(Registro *vet, int n, int i)
{
    int maior = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq].cpf > vet[i].cpf)
        maior = esq;
    
    if (dir < n && vet[dir].cpf > vet[maior].cpf)
        maior = dir;
   
    if (maior != i){
        trocar(vet, maior, i);  
        maxHeapify(vet, n, maior);
    }
}


void montaMaxHeap(Registro *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        maxHeapify(vet, n, i);
    }
}

void heapSortMax(Registro *vet, int n)
{
    montaMaxHeap(vet, n);
    for (int i=n-1; i>=1; i--){
        trocar(vet, 0, i);
        maxHeapify(vet, i, 0);
    }
}

void minHeapify(Registro *vet, int n, int i)
{
    int menor = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && vet[esq].cpf < vet[i].cpf)
        menor = esq;
    
    if (dir < n && vet[dir].cpf < vet[menor].cpf)
        menor = dir;
   
    if (menor != i){
        trocar(vet, menor, i);  
        minHeapify(vet, n, menor);
    }
}


void montaMinHeap(Registro *vet, int n)
{
    for(int i = n/2 - 1; i>=0; i--){
        minHeapify(vet, n, i);
    }
}

void heapSortMin(Registro *vet, int n)
{
    montaMinHeap(vet, n);
    for (int i=n-1; i>=1; i--){
        trocar(vet, 0, i);
        minHeapify(vet, i, 0);
    }
}

void ordenarVetores(Registro mat[M][N])
{
    for (int i=0; i<M; i++){
        heapSortMax(mat[i], N);
    }
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            mat[i][j].i = i;
            mat[i][j].j = j;
        }
    }
}


void kWayMerge(Registro mat[][N], Registro *heap, Registro *vetFinal, int m, int n)
{
    int tamV = m*n; //tamanho que o vetor final terá
    for (int i=0; i<m; i++){
        strcpy(heap[i].email, mat[i][0].email);
        heap[i].cpf = mat[i][0].cpf;
        heap[i].telefone = mat[i][0].telefone;
        strcpy(heap[i].nome, mat[i][0].nome);
        heap[i].data_nascimento.dia = mat[i][0].data_nascimento.dia;
        heap[i].data_nascimento.mes = mat[i][0].data_nascimento.mes;
        heap[i].data_nascimento.ano = mat[i][0].data_nascimento.ano;
        heap[i].i = mat[i][0].i;
        heap[i].j = mat[i][0].j;
    }
    montaMinHeap(heap, M);
    for (int i=0; i<tamV; i++){ 
        strcpy(vetFinal[i].email, heap[0].email);
        vetFinal[i].cpf = heap[0].cpf;
        vetFinal[i].telefone = heap[0].telefone;
        strcpy(vetFinal[i].nome, heap[0].nome);
        vetFinal[i].data_nascimento.dia = heap[0].data_nascimento.dia;
        vetFinal[i].data_nascimento.mes = heap[0].data_nascimento.mes;
        vetFinal[i].data_nascimento.ano = heap[0].data_nascimento.ano;
        vetFinal[i].i = heap[0].i;
        vetFinal[i].j = heap[0].j;

        if(heap[0].j  < n-1){
            int auxI = heap[0].i;
            int auxJ = heap[0].j;
            strcpy(heap[0].email, mat[auxI][auxJ + 1].email);
            heap[0].cpf = mat[auxI][auxJ + 1].cpf;
            heap[0].telefone = mat[auxI][auxJ + 1].telefone;
            strcpy(heap[0].nome, mat[auxI][auxJ + 1].nome);
            heap[0].data_nascimento.dia = mat[auxI][auxJ + 1].data_nascimento.dia;
            heap[0].data_nascimento.mes = mat[auxI][auxJ + 1].data_nascimento.mes;
            heap[0].data_nascimento.ano = mat[auxI][auxJ + 1].data_nascimento.ano;
            heap[0].i = mat[auxI][auxJ + 1].i;    
            heap[0].j = mat[auxI][auxJ + 1].j;
        }else{
            heap[0].cpf = 99999999999;
        }
        minHeapify(heap, m, 0);
    }
}

void countingSort(Registro *a, Registro *b, int n, int maior)
{
    Registro c[maior];
    for(int i=0; i<maior; i++){
        c[i].idade = 0;
    }
    for(int j=0; j<n; j++){
        c[a[j].idade].idade = c[a[j].idade].idade + 1;
    }
    for(int i=0; i<maior; i++){
        c[i].idade = c[i].idade + c[i-1].idade;
    }
    for(int j=n-1; j>=0; j--){
        b[c[a[j].idade].idade].idade = a[j].idade;
        c[a[j].idade].idade = c[a[j].idade].idade - 1;
    }
    imprimirVetor(b,n);
}

int calcIdade(Data data)
{
    if(data.mes > MES_ATUAL)
        return ANO_ATUAL - data.ano - 1;
    else
        return ANO_ATUAL - data.ano;
}

void buscarFaixa(Registro *a, Registro *b, int n, Data data)
{
    int maiorIdade = -1;
    for(int i=0; i<n; i++){
        a[i].idade = calcIdade(a[i].data_nascimento);
        if(a[i].idade > maiorIdade)
            maiorIdade = a[i].idade;
    }
    countingSort(a, b, M*N, maiorIdade);
}


int main()
{
    //srand(time(NULL));
    Registro mat[M][N];
    Registro heap[M];
    Registro vetFinal[M*N];
    //Pre processamento dos vetores
    preencherMatriz(mat);
    ordenarVetores(mat);
    //imprimirMatriz(mat);
    kWayMerge(mat, heap, vetFinal, M, N);
    printf("-----Vetor ordenado-----\n");
    imprimirVetor(vetFinal,  M*N);

    //Quinta questao
    Registro vetFinal2[M*N];
    buscarFaixa(vetFinal, vetFinal2, M*N, vetFinal[M*N-1].data_nascimento);
    return 0;
}


 
