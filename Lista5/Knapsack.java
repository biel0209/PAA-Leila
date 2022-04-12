package Lista5;

class Matriz{
    boolean existe;
    boolean pertence;
}

public class Knapsack {
    public static void main(String[] args){
        int[] S = {10,20,30};
        int n = S.length;
        int k = 50;
        Matriz P[][] = new Matriz[n][k];
        inicializarMatriz(P, n, k);
        mochila(S, n, k, P);
    }

    public static void inicializarMatriz(Matriz[][] P, int n, int k){
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                P[i][j] = new Matriz();
            }
        }
    }

    public static void mochila(int[] S, int n, int k, Matriz[][] P){
        P[0][0].existe = true;
        for(int j=1; j<k; k++){
            P[0][j].existe = false;
        }
        for(int i=1; i<n; n++){
            for(int j=0; j<k; k++){
                P[i][j].existe = false;
                if (P[i-1][j].existe){
                    P[i][j].existe = true;
                    P[i][j].pertence = false;
                }else if (j - S[i] >= 0){
                    if(P[i-1][j-S[i]].existe)
                        P[i][j].existe = true;
                        P[i][j].pertence = true;
                }
            }
        }
        System.out.print(P[n-1][k-1]); 

    }
}
