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
        int q = 3354393, d = 32;
        
        //Pre processamento do texto
        int h2=0;
        for (int i=0; i < m; i++)  
            h2 = (h2*d + T.charAt(i))%q;
            
        //Busca da quantidade de ocorrencias de cada P no Texto
        for(int i=0; i<m; i++){
            /*int qtd =*/ Rabin_Karp(T, n, P[i], m, q, d, h2);
            /*System.out.println("Padrao de indice " + i +
                    " Quantidade de ocorrencias no texto: " +
                    quantidade);*/
        }
    }

    public static void Rabin_Karp(String T, int n, String P, int m, int q, int d, int h2){
        int h1 = 0, dM = 1;
        for(int i=0; i < m-1; i++)
            dM = (dM*d)%q;
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
