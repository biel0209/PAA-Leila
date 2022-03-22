package Lista4;

class Indice{
    int quantidade;
    int texto;
}

public class Questao1_KMP{
    public static void main(String[] args){
        String padrao = "mar";
        int n = 4; 
        String [] texto = new String[n];
        texto[0] = "marararmarmararmar";
        texto[1] = "marararmarararmarmarmarmararar";
        texto[2] = "ararmarmarmarmararmarmararmarmar";  
        texto[3] = "ararmarmarmararararmararmarararmarmarararmar";
        maisRelevante(texto, texto.length, padrao, padrao.length());
    }

    public static void maisRelevante(String T[], int n, String P, int m){
        //Busca de cada quantidade de ocorrencias de P em cada Texto
        Indice index[] = new Indice[n];
        for(int i=0; i<n; i++){
            index[i] = new Indice();
            index[i].quantidade = KMP(T[i], T[i].length(), P, m);
            index[i].texto = i;
        }

        //Buscar o(s) texto(s) mais relevante(s)
        Indice maior = new Indice();
        maior.quantidade = index[0].quantidade;
        maior.texto = index[0].texto;
        for(int i=0; i<n; i++){
            if(maior.quantidade < index[i].quantidade){
                maior.quantidade = index[i].quantidade;
                maior.texto = index[i].texto;
            }
        }

        System.out.println("Texto(s) mais relevante(s):");
        //Buscar repetidos
        for(int i=0; i<n; i++){
            if(maior.quantidade == index[i].quantidade){
                System.out.println("Texto de indice " + index[i].texto +
                                    " Quantidade de ocorrencias: " +
                                    index[i].quantidade);
            }
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


