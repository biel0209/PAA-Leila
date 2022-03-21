package Lista4;

public class Questao1_KMP{
    public static void main(String[] args){
        String padrao = "marmar";
        String texto1 = "marararmarmararmar";
        String texto2 = "marmarararmarararmarmarmarmararar";
        String texto3 = "marararmarmararmarmararmarmar";
        int resp = KMP(texto1, texto1.length(), padrao, padrao.length());
        System.out.println(resp);
    }

    public static void computaNext(String P, int m, int[] next){
        next[0] = 0;
        int k=0;
        for(int i=1; i<m; i++){
            while(P.charAt(k+1) != P.charAt(i) && k>0){
                k = next[k];
            }
            if (P.charAt(k+1) == P.charAt(i))
                k++;
            next[i] = k;
        }
    }

    public static int KMP(String T, int n, String P, int m){
        int next[] = new int[m];
        computaNext(P, m, next);
        int q=0, index = -1;
        for(int i=1; i<n; i++){
            while(P.charAt(q+1) != T.charAt(i) && q>0)
                q = next[q];
            if (P.charAt(q+1) == T.charAt(i))
                q++;
            if(q == m){
                index = i-m;
                q = next[q];
            }
        }
        return index;
    }
}   