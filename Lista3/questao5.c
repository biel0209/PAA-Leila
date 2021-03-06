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
    long telefone; 
    char cpf[12];            
    char nome[15], email[45];
    int i, j;
    Data data_nascimento;  
    int idade;
}Registro;

int gerarAleatorio(int inferior, int superior)
{
    return inferior + rand() % superior;
}

char* gerarCpf()
{
    char *aux = malloc(11*sizeof(char));
    for (int i = 0; i < 11; i++){
        if(i==0)
            aux[i] = gerarAleatorio(1,9) + '0';
        else
            aux[i] = gerarAleatorio(0,9) + '0';
    }
    return aux;
}

//Recebe duas strings e retorna true se a primeira for menor que a segunda ou false caso contrario
int compararCpf(char *str1, char *str2)
{
    for(int i=0; i<11; i++){
        if(str1[i] < str2[i])
            return 1;
        else if(str1[i] > str2[i])
            return 0;
    }
    return 1;
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
            strcpy(mat[i][j].cpf, gerarCpf());
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
            printf("CPF: %s\tNome: %s\tNascimento: %d/%d/%d\tEmail: %s\tTelefone: %ld\n", 
                        mat[i][j].cpf, mat[i][j].nome, mat[i][j].data_nascimento.dia,
                        mat[i][j].data_nascimento.mes, mat[i][j].data_nascimento.ano,
                        mat[i][j].email, mat[i][j].telefone);
        }
    }
}

void imprimirVetor(Registro *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("CPF: %s\tNome: %s\tNascimento: %d/%d/%d\tEmail: %s\tTelefone: %ld\tIdade: %d\n", 
                    vet[i].cpf, vet[i].nome, vet[i].data_nascimento.dia,
                    vet[i].data_nascimento.mes, vet[i].data_nascimento.ano,
                    vet[i].email, vet[i].telefone, vet[i].idade);
        
    }
}

void imprimirVetor2(Registro *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("Idade: %d\n", vet[i].idade);
        
    }
}

void imprimirVetor3(int *vet, int n)
{
    for (int i = 0; i < n; i++){
        printf("i: %d Idade: %d\n", i,vet[i]);
        
    }
}


void trocar(Registro *vet, int a, int b)
{
    Registro aux;
    
    strcpy(aux.email, vet[b].email);
    strcpy(aux.cpf, vet[b].cpf);
    aux.telefone = vet[b].telefone;
    strcpy(aux.nome, vet[b].nome);
    aux.data_nascimento.dia = vet[b].data_nascimento.dia;
    aux.data_nascimento.mes = vet[b].data_nascimento.mes;
    aux.data_nascimento.ano = vet[b].data_nascimento.ano;
    aux.i = vet[b].i;
    aux.j = vet[b].j;

    strcpy(vet[b].email, vet[a].email);
    strcpy(vet[b].cpf, vet[a].cpf);
    vet[b].telefone = vet[a].telefone;
    strcpy(vet[b].nome, vet[a].nome);
    vet[b].data_nascimento.dia = vet[a].data_nascimento.dia;
    vet[b].data_nascimento.mes = vet[a].data_nascimento.mes;
    vet[b].data_nascimento.ano = vet[a].data_nascimento.ano;
    vet[b].i = vet[a].i;
    vet[b].j = vet[a].j;

    strcpy(vet[a].email, aux.email);
    strcpy(vet[a].cpf, aux.cpf);
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
    if (esq < n && compararCpf(vet[i].cpf, vet[esq].cpf))
        maior = esq;
    
    if (dir < n && compararCpf(vet[maior].cpf, vet[dir].cpf))
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
    if (esq < n && compararCpf(vet[esq].cpf, vet[i].cpf))
        menor = esq;
    
    if (dir < n && compararCpf(vet[dir].cpf, vet[menor].cpf))
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
        strcpy(heap[i].cpf, mat[i][0].cpf);
        heap[i].telefone = mat[i][0].telefone;
        strcpy(heap[i].nome, mat[i][0].nome);
        heap[i].data_nascimento.dia = mat[i][0].data_nascimento.dia;
        heap[i].data_nascimento.mes = mat[i][0].data_nascimento.mes;
        heap[i].data_nascimento.ano = mat[i][0].data_nascimento.ano;
        heap[i].i = mat[i][0].i;
        heap[i].j = mat[i][0].j;
    }
    montaMinHeap(heap, m);
    for (int i=0; i<tamV; i++){ 
        strcpy(vetFinal[i].email, heap[0].email);
        strcpy(vetFinal[i].cpf, heap[0].cpf);
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
            strcpy(heap[0].cpf, mat[auxI][auxJ + 1].cpf);
            heap[0].telefone = mat[auxI][auxJ + 1].telefone;
            strcpy(heap[0].nome, mat[auxI][auxJ + 1].nome);
            heap[0].data_nascimento.dia = mat[auxI][auxJ + 1].data_nascimento.dia;
            heap[0].data_nascimento.mes = mat[auxI][auxJ + 1].data_nascimento.mes;
            heap[0].data_nascimento.ano = mat[auxI][auxJ + 1].data_nascimento.ano;
            heap[0].i = mat[auxI][auxJ + 1].i;    
            heap[0].j = mat[auxI][auxJ + 1].j;
        }else{
            strcpy(heap[0].cpf, "99999999999");
        }
        minHeapify(heap, m, 0);
    }
}

void countingSort(Registro *a, int *c, int n, int maior)
{
    for(int i=0; i<=maior; i++)
        c[i] = 0;
    for(int j=0; j<n; j++)
        c[a[j].idade]++;
    for(int i=1; i<=maior; i++)
        c[i] = c[i] + c[i-1];
    //imprimirVetor3(c,maior+1);
}

int calcIdade(Data data)
{
    if(data.mes > MES_ATUAL)
        return ANO_ATUAL - data.ano - 1;
    else
        return ANO_ATUAL - data.ano;
}

void buscarFaixa(Registro *a, int n)
{
    int inferior, superior, qtd;
    int maiorIdade = -1;
    int resp=1;
    int cont=0;
    int *c;
    while(resp!=0){
        printf("\n-----Buscar quantidade de clientes por faixa de idade-----\n");
        printf("Digite a menor idade: ");
        scanf("%d", &inferior);
        printf("Digite a maior idade: ");
        scanf("%d", &superior);
        if(cont==0){
            for(int i=0; i<n; i++){
                a[i].idade = calcIdade(a[i].data_nascimento);
                if(a[i].idade > maiorIdade)
                    maiorIdade = a[i].idade;
            }
            printf("-----Vetor ordenado-----\n");
            imprimirVetor(a, M*N);
            printf("------------------------\n");
            c = malloc((maiorIdade+1)*sizeof(int));
            countingSort(a, c, n, maiorIdade);
        }
        if(inferior > maiorIdade)
            qtd = 0;
        else if(superior > maiorIdade)
            qtd = c[maiorIdade] - c[inferior-1];
        else
            qtd = c[superior] - c[inferior-1];
        printf("Quantidade de clientes com idades entre %d e %d: %d\n", inferior, superior, qtd);
        cont++;
        printf("Tecle 1 para continuar pesquisando ou 0 para finalizar o programa: ");
        scanf("%d", &resp);
    }
}

int main()
{
    srand(time(NULL));
    Registro mat[M][N];
    Registro heap[M];
    Registro vetFinal[M*N];
    //Pre processamento dos vetores
    preencherMatriz(mat);
    ordenarVetores(mat);
    //imprimirMatriz(mat);
    kWayMerge(mat, heap, vetFinal, M, N);
    //imprimirVetor(vetFinal,  M*N);

    //Quinta questao
    buscarFaixa(vetFinal, M*N);
    return 0;
}


 
