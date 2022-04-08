package Lista5;

class Matriz{
    int tam;
    char dir;
}

class Dados_Covid{
    String data;
    int mortes;
}

public class Questao2 {
    public static void main(String[] args){
        Dados_Covid[] X = new Dados_Covid[9];
        int m = X.length;
        inicializarDados(X, m);
        Matriz LCS[][] = new Matriz[m+1][m+1];
        inicializarMatriz(LCS,m);
        maiorSequencia(X, m, m, LCS);
    }

    public static void inicializarMatriz(Matriz[][] LCS, int m){
        for(int i=0; i<m+1; i++){
            for(int j=0; j<m+1; j++){
                LCS[i][j] = new Matriz();
            }
        }
    }

    public static void inicializarDados(Dados_Covid[] X, int m){
        X[0] = new Dados_Covid(); X[0].data = "01/02/2021"; X[0].mortes = 800;
        X[1] = new Dados_Covid(); X[1].data = "02/02/2021"; X[1].mortes = 900;
        X[2] = new Dados_Covid(); X[2].data = "03/02/2021"; X[2].mortes = 850;
        X[3] = new Dados_Covid(); X[3].data = "04/02/2021"; X[3].mortes = 955;
        X[4] = new Dados_Covid(); X[4].data = "05/02/2021"; X[4].mortes = 750;
        X[5] = new Dados_Covid(); X[5].data = "06/02/2021"; X[5].mortes = 1100;
        X[6] = new Dados_Covid(); X[6].data = "07/02/2021"; X[6].mortes = 1005;
        X[7] = new Dados_Covid(); X[7].data = "08/02/2021"; X[7].mortes = 1215;
        X[8] = new Dados_Covid(); X[8].data = "09/02/2021"; X[8].mortes = 1155;
    }

    public static void merge(Dados_Covid[] vet, int esq, int m, int dir)
    {
        int i, j, k;
        int n1 = m - esq + 1;
        int n2 = dir - m;
    
        Dados_Covid[] A = new Dados_Covid[n1];
        Dados_Covid[] B = new Dados_Covid[n2];
        for (i = 0; i < n1; i++)
            A[i] = vet[esq + i];
        for (j = 0; j < n2; j++)
            B[j] = vet[m + 1 + j];
    
        i = 0;
        j = 0; 
        k = esq; 
        while (i < n1 && j < n2) {
            if (A[i].mortes <= B[j].mortes) {
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
    
    public static void mergeSort(Dados_Covid[] vet, int esq, int dir){
        if (esq < dir) {
            int m = esq + (dir - esq) / 2;
            mergeSort(vet, esq, m);
            mergeSort(vet, m + 1, dir);
            merge(vet, esq, m, dir);
        }
    }


    public static void maiorSequencia(Dados_Covid[] X, int m, int n, Matriz[][] LCS){
        Dados_Covid[] Y = new Dados_Covid[m];
        //Copiando dados de X para Y
        for(int j=0; j<m; j++){
            Y[j] = X[j];
        }

        //ordenar vetor Y
        mergeSort(Y, 0, m-1);
        
        for(int i=0; i<=m; i++){
            LCS[i][0] = new Matriz();
            LCS[i][0].tam = 0;
            LCS[i][0].dir = '*';
        }

        for(int j=0; j<=n; j++){
            LCS[0][j] = new Matriz();
            LCS[0][j].tam = 0;
            LCS[0][j].dir = '*';
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(X[i-1].mortes == Y[j-1].mortes){
                    LCS[i][j].tam = 1 + LCS[i-1][j-1].tam;
                    LCS[i][j].dir = 'D';
                }else{
                    if(LCS[i-1][j].tam >= LCS[i][j-1].tam){
                        LCS[i][j].tam = LCS[i-1][j].tam;
                        LCS[i][j].dir = 'A';
                    }else{
                        LCS[i][j].tam = LCS[i][j-1].tam;
                        LCS[i][j].dir = 'E';
                    }
                }
            }
        }
        System.out.println("Tamanho da maior sequencia ordenada: " + LCS[m][n].tam);
        imprimeLCS(LCS, m, n, X);
    }

    public static void imprimeLCS(Matriz[][] LCS, int i, int j, Dados_Covid[] X){
        if (!(i==0 || j==0)){
            if(LCS[i][j].dir == 'D'){
                imprimeLCS(LCS, i-1, j-1, X);
                System.out.print(X[i-1].data + ": " + X[i-1].mortes + " mortes"); 
                System.out.println(""); 
            }else{
                if(LCS[i][j].dir == 'A')
                    imprimeLCS(LCS, i-1, j, X);
                else
                    imprimeLCS(LCS, i, j-1, X);
            }
        }
    }

}
