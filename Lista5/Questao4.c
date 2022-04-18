public class Main
{
	public static void main(String[] args) {
		int m = 200; //tamanho da rodovia
		int[] postos = {60,70,120,140};
		int[] precos = {10,12,10,2};
		int distMin = 51;
		
		maximoLucro(postos, postos.lenght, precos, m, distMin);
	}
	
	public static void maximoLucro(int[] postos, int n, int[] precos, int m, int distMin) {
		int[] P = new int[m+1]; //array para guardar os subproblemas
		for(int i=0; i <= m; i++)
            P[i] = 0;
            
        
        for(int i=1; i <= m; i++){
            
        }
	}
}
