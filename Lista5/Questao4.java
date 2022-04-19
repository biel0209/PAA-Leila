package Lista5;

class Vetor{
    int soma;
    int ultValor;
    int indice;
}

public class Questao4{

	public static void main(String[] args) {
		int m = 200; //tamanho da rodovia
		int[] postos = {60,70,120,140};
		int[] precos = {10,12,10,2};
		int distMin = 51;
		maximoLucro(postos, postos.length, precos, m, distMin);
	}

    public static void inicializarArray(Vetor[] P, int m){
	    for(int i=0; i <= m; i++)
            P[i] = new Vetor();
	}
	
	public static int max(int a, int b){
	    if (a>b)
	        return a;
	    else    
	        return b;
	}

	
	public static void maximoLucro(int[] postos, int n, int[] precos, int m, int distMin) {
		
        Vetor[] P = new Vetor[m+1]; //array para guardar os subproblemas
        inicializarArray(P, m);
  
        for(int i=0; i <= m; i++){
            P[i].soma = 0;
            P[i].ultValor = 0;
            P[i].indice = -1;
        }
        int distAtual = 0; //indice para o array postos e precos
        for(int i=1; i <= m; i++){
            if (distAtual < n){
                if(postos[distAtual] != i)
                    P[i] = P[i-1];
                else{
                    if(i <= distMin){
                        P[i].soma = max(P[i-1].soma, precos[i-1]);
                        if (P[i].soma == P[i-1].soma){
                            P[i].ultValor = P[i-1].ultValor;
                            P[i].indice = P[i-1].indice;
                        }else{
                            P[i].ultValor = precos[i-1];
                            P[i].indice = i-1;
                        }

                    }else{
                        P[i].soma = max(P[i-distMin-1].soma + precos[distAtual], P[i-1].soma);
                        if(P[i].soma == P[i-distMin-1].soma + precos[distAtual]){
                            P[i].ultValor = precos[distAtual];
                            P[i].indice = distAtual;
                        }else{
                            P[i].ultValor = P[i-1].ultValor;
                            P[i].indice = P[i-1].indice;
                        }
                    }
                    distAtual++;
                }
            }else
                P[i] = P[i-1];
        }
        System.out.println("Lucro maximo: "+P[m].soma);
        imprimePostos(P, m, postos);
	}

    public static void imprimePostos(Vetor[] P, int m, int[] postos){
        int ultSoma = P[m].soma;
        System.out.print("Postos escolhidos: ");
        for(int i=m; i >= 0 && ultSoma > 0; i--){
            if(ultSoma == P[i].soma){
                if(P[i].ultValor == 0){
                    System.out.print(postos[P[i].indice] + " ");
                }else{
                    System.out.print(postos[P[i].indice] + " ");
                    ultSoma = P[i].soma - P[i].ultValor;
                }
            }
        } 
        System.out.println("");
    }
}
