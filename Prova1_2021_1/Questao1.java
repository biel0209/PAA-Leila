package Prova1_2021_1;

public class Questao1{
    public static void main(String[] args){
        String[] texto = new String[4];
        texto[0] = "arte";
        texto[1] = "cafe";
        texto[2] = "caju";
        texto[3] = "casa";
        String p = "cama";
        System.out.println(buscarIndice(texto, 0, 4-1, p));
    }

    public static int buscarIndice(String A[], int esq, int dir, String p){
        if(esq == dir)
            if (A[esq].compareToIgnoreCase(p) <= 0 ){
                return esq;
            }else
                return -1;
        else{
            int meio = (esq+dir)/2 + 1;
            if(A[meio].compareToIgnoreCase(p) > 0){
                return buscarIndice(A, esq, meio-1, p);
            }else{
                return buscarIndice(A, meio, dir, p);
            }
        }
    }
}   
