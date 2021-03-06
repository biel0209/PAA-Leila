package Lista5;

class Matriz{
    int tam;
    char dir;
}

public class LCS {
    public static void main(String[] args){
        String str1 = "abc";
        String str2 = "ach";
        char[] X = str1.toCharArray();
        char[] Y = str2.toCharArray();
        int m = X.length;
        int n = Y.length;
        Matriz LCS[][] = new Matriz[m+1][n+1];
        inicializarMatriz(LCS,m,n);
        maiorSequencia(X, m, Y, n, LCS);
        imprimeLCS(LCS, m, n, X);
    }

    public static void inicializarMatriz(Matriz[][] LCS, int m, int n){
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                LCS[i][j] = new Matriz();
            }
        }
    }

    public static void maiorSequencia(char[] X, int m, char[] Y, int n, Matriz[][] LCS){
        for(int i=0; i<=m; i++){
            LCS[i][0].tam = 0;
            LCS[i][0].dir = '*';
        }

        for(int j=1; j<=n; j++){
            LCS[0][j].tam = 0;
            LCS[0][j].dir = '*';
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(X[i-1] == Y[j-1]){
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
        System.out.println("Tamanho da maior sequencia comum: " + LCS[m][n].tam);
    }

    public static void imprimeLCS(Matriz[][] LCS, int i, int j, char[] X){
        if (!(i==0 || j==0)){
            if(LCS[i][j].dir == 'D'){
                imprimeLCS(LCS, i-1, j-1, X);
                System.out.print(X[i-1]);
            }else{
                if(LCS[i][j].dir == 'A')
                    imprimeLCS(LCS, i-1, j, X);
                else
                    imprimeLCS(LCS, i, j-1, X);
            }
        }
    }

}
