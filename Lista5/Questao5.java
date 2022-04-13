package Lista5;

class Struct{
    int item;
    boolean existe;  //existe ou não solução
}

public class Questao5 {
    public static void main(String[] args){
        int[] itens = {1000, 2000, 1500, 500, 2500};
        int n = itens.length;
        //Struct LCS[][] = new Struct[m+1][m+1];
        //inicializarStruct(LCS,m);
        System.out.print(diferencaMin(itens, n));
    }

    public static void inicializarStruct(Struct[][] LCS, int m){
        for(int i=0; i<m+1; i++){
            for(int j=0; j<m+1; j++){   
                LCS[i][j] = new Struct();
            }
        }
    }

    public static int diferencaMin(int[] itens, int n){
        int soma = 0;
        for(int i=0; i<n; i++){
            soma += itens[i];
        }
        int y = soma/2 + 1;

        // dp[i] devolve se é possível obter i como
        // soma dos elementos 
        // dd é a variável auxiliar que usamos
        // para ignorar duplicatas
        boolean dp[] = new boolean[y];
        boolean dd[] = new boolean[y];

        //inicializando dp e dd
        for(int i=0; i<y; i++){
            dp[i] = false;
            dd[i] = false;
        }

        dd[0] = true; //caso da soma ser 0
        for(int i=0; i<n; i++){
            //atualizando dd[k] se k for formado
            //usando elementos de 1 a i+1
            for(int j=0; j+itens[i] < y; j++){
                if(dp[j])
                    dd[j+itens[i]] = true;
            }

            //atualizando dd
            for(int j=0; j < y; j++){
                if(dd[j])
                    dp[j] = true;
                dd[j] = false;
            }
        }

        //verificando se o numero de soma/2 até 1 
        //é possível obter como soma
        for(int i=y-1; i >= 0; i--){
            if(dp[i])
                return (soma - 2 * i);
        }
        return 0;
        

    }
        

}
