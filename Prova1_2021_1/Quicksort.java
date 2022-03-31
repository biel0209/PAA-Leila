package Prova1_2021_1;

public class Quicksort {

    void quickSort(String[] X, int esq, int dir) {

        String pivo = "amarelo";
        int L = esq;
        int R = dir;

        while (L < R) {
            while ((X[L] == "azul" || X[L] == "amarelo") && (L <= dir)){
                L++;
            }

            while (X[R] == "verde" && (R >= esq)) {
                R--;
            }

            if (L < R) {
                String aux = X[L];
                X[L] = X[R];
                X[R] = aux;
            }
        }

        for (int i = 0; i < X.length; i++){
            System.out.println(X[i]);
        }  
    }

    public static void main(String args[]) {

        Quicksort sort = new Quicksort();

        String[] cores = {"verde", "azul", "verde", "amarelo", "amarelo", "verde", "verde", "amarelo", "azul", "amarelo"};

        sort.quickSort(cores, 0, cores.length-1);
    }
}
