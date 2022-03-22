package Lista4;

class Indice{
    int indice;
    int quantidade;
    int texto;
}

public class Questao1_KMP{
    public static void main(String[] args){
        String padrao = "mar";
        int n = 3; 
        String [] texto = new String[n];
        texto[0] = "marararmarmararmar";
        texto[1] = "marmarararmarararmarmarmarmararar";
        texto[2] = "marararmarmararmarmararmarmar";
        maisRelevante(texto, texto.length, padrao, padrao.length());
    }

    public static void maisRelevante(String T[], int n, String P, int m){
        Indice index[] = new Indice[n];
        for(int i=0; i<n; i++){
            index[i] = KMP(T[i], T[i].length(), P, m);
            index[i].texto = i;
        }
        for(int i=0; i<n; i++){
            System.out.println("Texto "+i+1+" Quantidade de ocorrencias: "+
                                index[i].quantidade + "Index da primeira ocorrencia: "+
                                index[i].indice);
        }
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
                    next[i] = 0;
                    i++;
                }
            }
        }
    }

    public static Indice KMP(String T, int n, String P, int m){
        Indice index = new Indice();
        index.quantidade = 0;
        int next[] = new int[m];
        computaNext(P, m, next);
        int i=0, j=0;
        index.indice = -1;
        while(i<n){
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
                index.quantidade = index.quantidade + 1;
                index.indice = i-j;
                j = next[j-1];
            }
        }
        return index;
    }
}   