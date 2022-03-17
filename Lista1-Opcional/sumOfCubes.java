import java.util.Scanner;
import java.math.BigInteger;


public class Main
{
	public static void main(String[] args) {
	    Scanner input = new Scanner(System.in);
	    
		int qtd_testes;
        //scanf("%d",&qtd_testes);
        for(int i=0; i<1; i++){
            //printf("digite: ");
            long x = input.nextLong();
            System.out.println("" + x);
            int qtd = teste(x);
            if(qtd == 1)
                System.out.println("yes");
            else
                System.out.println("no");
        //703657519796
        }
	}
    public static int buscar(long chave, long[] vet, long x, long limite)
    {
        //System.out.println("\nbuscar" + x);
        for(long a=0; a<limite; a++){
            if(vet[(int) a] == chave)
                return 1;
        }
        return 0;
    }
    
    public static int teste(long x)
    {
        
        System.out.println("\nteste1" + x);
        long limite = (long) Math.pow(x, 1.0/3.0);
  
    
        long vet[] = new long[ (int) limite];
        for(long a=1;  a < limite; a++)
            vet[ (int) a-1] = a*a*a;
        System.out.println("\nteste2" + x);
        
        for(long b=1; b<limite; b++){
            if( buscar(x-(b*b*b), vet, x, limite) == 1 ){
                return 1;
            }
        }
        System.out.println("\nteste3" + x);
    
        return 0;
    }
}




 
