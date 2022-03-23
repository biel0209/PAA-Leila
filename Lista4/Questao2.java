//package Lista4;

public class Main{
    public static void main(String[] args){
        String texto = "ararammarmarmararararmararmarararammarmarararmar";
        int p = 3; 
        String [] padrao = new String[p];
        padrao[0] = "mar";
        padrao[1] = "arm";
        padrao[2] = "ram";
        buscarOcorrencias(texto, texto.length(), padrao, padrao.length);
    }

    public static void buscarOcorrencias(String T, int n, String P[], int m){
        //Busca de cada quantidade de ocorrencias de P em cada Texto
        Indice index[] = new Indice[n];
        for(int i=0; i<n; i++){
            index[i] = new Indice();
            index[i].quantidade = Rabin_Karp(T[i], T[i].length(), P, m);
            index[i].texto = i;
        }

 

        System.out.println("Texto(s) mais relevante(s):");
        //Buscar repetidos
        for(int i=0; i<m; i++){
            System.out.println("Texto de indice " + index[i].texto +
                                " Quantidade de ocorrencias: " +
                                index[i].quantidade);
            
        }
    }

    public static void preProcess(String T, int n, String P, int m, int q, int d){
        int h1 = 0, h2 = 0, dM = 1;
        for(int i=0; i < m-1; i++)
            dM = (dM*d)%q;
        for (int i=0; i < m; i++)  //Pre processamento do texto
            h2 = (h2*d + T.charAt(i))%q;
        
    }

    public static int Rabin_Karp(String T, int n, String P, int m, int q, int d, int h1, int dM){
        for (int i=0; i < m; i++) //Pre processamento do padrao
            h1 = (h1*d + P.charAt(i))%q;
        for (int i=0; i < m; i++){
            if(h1 == h2)
                System.out.println("Pattern found at index " + i);
            if(i < n-m){
                h2 = (h2 + (d*q - T.charAt(i)*dM))%q;
                if(h2<0)
                    h2 = h2+q;
            }
            
        }
    }
}   
