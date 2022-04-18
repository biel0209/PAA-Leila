public class Main
{
	public static void main(String[] args) {
		int m = 200; //tamanho da rodovia
		int[] postos = {60,70,120,140};
		int[] precos = {10,12,10,2};
		int distMin = 51;
		
		maximoLucro(postos, postos.length, precos, m, distMin);
	}
	
	public static int max(int a, int b){
	    if (a>b)
	        return a;
	    else    
	        return b;
	}
	
	public static void maximoLucro(int[] postos, int n, int[] precos, int m, int distMin) {
		int[] P = new int[m+1]; //array para guardar os subproblemas
		for(int i=0; i <= m; i++)
            P[i] = 0;
        int distAtual = 0;
        for(int i=1; i <= m; i++){
            if (distAtual < n){
                if(postos[distAtual] != i)
                    P[i] = P[i-1];
                else{
                    if(i <= distMin){
                        P[i] = max(P[i-1], precos[i-1]);
                        if(P[i] == precos[i-1])
                            System.out.println(precos[i-1]);

                    }else{
                        P[i] = max(P[i-distMin-1] + precos[distAtual], P[i-1]);
                        if(P[i] == P[i-distMin-1] + precos[distAtual])
                            System.out.println(precos[distAtual]);
                    }
                    distAtual++;
                }
            }else
                P[i] = P[i-1];
        }
        System.out.println(P[m]);
	}
}
