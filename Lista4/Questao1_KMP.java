package Lista4;

public class Questao1_KMP{
    public static void main(String[] args){
        String padrao = "mar"; 
        String texto1 = "marararmarmararmar";
        String texto2 = "marmarararmarararmarmarmarmararar";
        String texto3 = "marararmarmararmarmararmarmar";
        int resp = KMP(texto1, texto1.length(), padrao, padrao.length());
        System.out.println(resp);
    }

    /*public static void computaNext(String P, int m, int next[]){
        next[0] = -1;
        next[1] = 0;
        int i;
        for(i=2; i<m; i++){
            int j = next[i-1];
            while(P.charAt(i-1) != P.charAt(j) && j>0)
                j = next[j];
            next[i] = j;
        }
    }*/

    public static void computaNext(String P, int m, int next[]){
        next[0] = 0;
        int n=0;
        int i=1;
        while(i<m){
            if(P.charAt(i) == P.charAt(n)){
                t++;
            }
        }
    }

    public static int KMP(String T, int n, String P, int m){
        int cont=0;
        int next[] = new int[m];
        computaNext(P, m, next);
        int i=0, j=0, index = -1;
        while(index == -1 && i<n){
            if( P.charAt(j) == T.charAt(i)){
                j++;
                i++;
            }else{
                if(j==0){
                    i++;
                }else{
                    j = next[j-1];
                }
            }if (j == m){
                cont++;
                index = i-m;
                j = next[j-1];
            }
        }
        return cont;
    }
}   