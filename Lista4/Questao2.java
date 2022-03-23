package Lista4;

class Indice{
    int quantidade;
    int texto;
}

public class Questao1_Horspool{
    public static void main(String[] args){
        String padrao = "mar";
        int n = 4; 
        String [] texto = new String[n];
        texto[0] = "marararmarmararmar";
        texto[1] = "marararmarararmarmarmarmararar";
        texto[2] = "ararmarmarmarmararmarmararmarmar";
        texto[3] = "ararmarmarmararararmararmarararmarmarararmar";;
        maisRelevante(texto, texto.length, padrao, padrao.length());
    }

    public static void maisRelevante(String T[], int n, String P, int m){
        //Busca de cada quantidade de ocorrencias de P em cada Texto
        Indice index[] = new Indice[n];
        for(int i=0; i<n; i++){
            index[i] = new Indice();
            index[i].quantidade = Horspool(T[i], T[i].length(), P, m);
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

    public static void computaDesloc(String P, int m, int D[], int tam){
        for(int j=0; j<tam; j++)
            D[j] = m;
        for(int j=0; j<=m-2; j++)
            D[P.charAt(j)] = m-1-j;
    }

    public static int Horspool(String T, int n, String P, int m){
        int qtdOcorrencias=0;
        int D[] = new int[256];
        computaDesloc(P, m, D, 256);
        int i=m-1;
        while(i<=n-1){
            int k=0;
            while(k<=m-1 && P.charAt(m-1-k) == T.charAt(i-k))
                k++;
            if(k==m)
                qtdOcorrencias++;
            i = i + D[T.charAt(i)];
        }
        return qtdOcorrencias;
    }
}   
