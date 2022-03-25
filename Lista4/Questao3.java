package Lista4;

public class Questao3{
    public static void main(String[] args){
        String padrao = "mar";
        String texto = "ararmarmararmar";
        int resp =  KMP(texto, texto.length(), padrao, padrao.length());
        System.out.println(resp);
    }

    public static void computaNext(String P, int m, int next[]){
        next[0] = 0;
        int n=0;
        int i=1;
        while(i<m){
            if(P.charAt(i) == P.charAt(n)){
                n++;
                next[i] = n;
                i++;
            }else{
                if(n != 0) {
                    n = next[n-1];
                }else{
                    next[i] = n;
                    i++;
                }
            }
        }
    }

    public static int KMP(String T, int n, String P, int m){
        int qtdOcorrencias = 0;
        int next[] = new int[m];
        computaNext(P, m, next);
        int i=0, j=0;
        while(i<n){
            if( P.charAt(j) == T.charAt(i) ){
                j++;
                i++;
            }
            if (j == m){
                qtdOcorrencias++;
                j = next[j-1];
            }
            else if( P.charAt(j) != T.charAt(i) ){
                if(j==0)
                    i++;
                else
                    j = next[j-1];
            }
        }
        return qtdOcorrencias;
    }
}   


