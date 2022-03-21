package Lista4;

public class Questao1_KMP{
    public static void main(String[] args){
        String padrao = "marmar";
        String texto1 = "marararmarmararmar";
        String texto2 = "marmarararmarararmarmarmarmararar";
        String texto3 = "marararmarmararmarmararmarmar";
        System.out.println("oi");

        //System.out.println(KMP(texto1, texto1.length(), padrao, padrao.length()));
    }

    public static void computaNext(String P, int m, int[] next){
        next[0] = -1;
        next[1] = 0;
        for(int i=2; i<m; i++){
            int j = next[i-1] + 1;
            while(P.charAt(i-1) != P.charAt(j) && j>0){
                j = next[j]+1;
                next[i] = j;
            }
        }
    }

    public static int KMP(String T, int n, String P, int m){
        int[] next = new int[m];
        computaNext(P, m, next);
        int i=0, j=0, index = -1;
        while(index == -1 && i<=n){
            if (P.charAt(j) == T.charAt(i)){
                j++;
                i++;
            }else{
                j = next[j]+1;
                if(j==0){
                    j = 1;
                    i++;
                }

            }
            if(j == m+1)
                index = i-m;
        }
        return index;
    }
}