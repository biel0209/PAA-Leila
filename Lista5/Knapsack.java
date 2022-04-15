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
        Matriz P[][] = new Matriz[n+1][k+1];
        inicializarMatriz(P, n, k);
        mochila(S, n, k, P);
    }

    public static void inicializarMatriz(Matriz[][] P, int n, int k){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=k; j++){
                P[i][j] = new Matriz();
            }
        }
    }

    public static void mochila(int[] S, int n, int k, Matriz[][] P){
        P[0][0].existe = true;
        for(int j=1; j<=k; j++){
            P[0][j].existe = false;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                P[i][j].existe = false;
                if (P[i-1][j].existe){
                    P[i][j].existe = true;
                    P[i][j].pertence = false;
                }else if (j - S[i-1] >= 0){
                    if(P[i-1][j-S[i-1]].existe){
                        P[i][j].existe = true;
                        P[i][j].pertence = true;
                    }
                }
            }
        }
        

        System.out.println("Existe solucao? "+P[n][k].existe); 

        imprimirSolucao(S, n, k, P);  
    }

    public static void imprimirSolucao(int[] S, int n, int k, Matriz[][] P){
        int j = k;
        int i = n;
        while(j >= 0 && i > 0){
            if(P[i][j].pertence != P[i-1][j].pertence){ //se um é false e outro é true
                if(P[i][j].pertence){   //se P[i][j] é true, entao S[i-1] faz parte da solução
                    System.out.println(S[i-1]);
                    j -= S[i-1];
                }else{
                    System.out.println(S[i-2]);  //se P[i-1][j] é true, entao S[i-2] faz parte da solução
                    j -= S[i-2];
                }
            }
            i--;
        }   
    }
}
