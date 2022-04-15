package Lista5;

public class Questao5_Longa {
    public static void main(String[] args){
        int[] S = {1000, 2000, 1500, 500, 2500};
        int n = S.length;
        diferencaMin(S, n);
    }

    public static void diferencaMin(int S[], int n) {
		int soma = 0;
		for (int i = 0; i < n; i++)
			soma += S[i];

		//array para armazenar resultados dos subproblemas
		boolean P[][] = new boolean[n + 1][soma + 1]; 
	
		// Inicializa a primeira coluna como verdadeira.
        // A soma 0 é possível com todos os elementos.      
		for (int i = 0; i <= n; i++) 
			P[i][0] = true;
		

		// Inicializa a primeira linha como false, exceto P[0][0].
        // Com 0 elementos, nenhuma outra soma, exceto 0, é possível.
		for (int j = 1; j <= soma; j++) 
			P[0][j] = false;
		

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= soma; j++) {
				// Se o elemento não fizer parte da solução
				P[i][j] = P[i - 1][j];

				// Se o elemento fizer parte da solução
				if (S[i - 1] <= j)
					P[i][j] |= P[i - 1][j - S[i - 1]];
			}
        }


		// Buscar o maior j tal que P[n][j] é true
		// O valor máximo de j é soma/2
		int difMin = Integer.MAX_VALUE;
        for (int j = soma / 2; j >= 0; j--) {
			if (P[n][j] == true) {
				difMin = soma - 2 * j;
                break;
			}
		}

        //k sera o tamanho de um dos subconjuntos
        int k = (soma-difMin)/2; 
	
        printSolucao(S, n, k, P);
	}

    public static void printSolucao(int[] S, int n, int k, boolean[][] P){
        int j = k;
        int i = n;
        System.out.print("Subconjunto 1: ");
        while(j >= 0 && i > 0){
            if(P[i][j] != P[i-1][j]){ //se um é false e outro é true
                if(P[i][j]){   //se P[i][j] é true, entao S[i-1] faz parte da solução
                    System.out.print(S[i-1]+" ");
                    j -= S[i-1];
                    S[i-1] = -1;
                }else{
                    System.out.print(S[i-2]+" ");  //se P[i-1][j] é true, entao S[i-2] faz parte da solução
                    j -= S[i-2];
                    S[i-2] = -1;
                }
            }
            i--;
        }   

        System.out.print("\nSubconjunto 2: ");
        for (i = 0; i < n; i++) {
			if(S[i] != -1)
                System.out.print(S[i]+" ");
		}
    }
}
