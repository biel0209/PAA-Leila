package Lista5;

public class minEditDistance {
    public static void main(String[] args){
        String str1 = "sunday";
        String str2 = "saturday";
        char[] X = str1.toCharArray();
        char[] Y = str2.toCharArray();
        int m = X.length;
        int n = Y.length;
        int M[][] = new int[m+1][n+1];
        searchDistance(X, m, Y, n, M);
    }

    public static int min(int a, int b, int c){
        if(a <= b && a <= c) 
            return a;
        else if(b <= a && b <= c)
            return b;
        else
            return c;
    }

    public static void searchDistance(char[] X, int m, char[] Y, int n, int[][] M){
        int x, y, z;
        for(int i=0; i<=m; i++){
            M[i][0] = i;
        }

        for(int j=1; j<=n; j++){
            M[0][j] = j;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                x = 1 + M[i-1][j];
                y = 1 + M[i][j-1];
                if(X[i-1] == Y[j-1])
                    z = M[i-1][j-1];
                else
                    z = M[i-1][j-1] +1 ;
                M[i][j] = min(x, y, z);
            }
        }
        System.out.println("Minima distancia de edicao: " + M[m][n]);
    }

}
