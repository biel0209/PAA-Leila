package Lista2_Opcional;

import java.util.Scanner;

public class Make_Product_Equal_One{
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    double[] numeros = new double[n+1];
    double[][] dp = new double[n+1][2];
    double[][] absolutos = new double[n+1][2];

    for(int i=1; i <= n; i++)
      numeros[i] = input.nextInt();

    for(int i=1; i <= n; i++){
      absolutos[i][0] = Math.abs(numeros[i] + 1);
      absolutos[i][1] = Math.abs(numeros[i] - 1);
    }

    dp[0][1] = Double.MAX_VALUE;

    for(int i=1; i <= n; i++){
      double aux = dp[i-1][0] + absolutos[i][1];
      double aux2 = dp[i-1][1] + absolutos[i][0];
      dp[i][0] = Math.min(aux, aux2);

      aux = dp[i-1][0] + absolutos[i][0];
      aux2 = dp[i-1][1] + absolutos[i][1];
      dp[i][1] = Math.min(aux, aux2);
    }

    System.out.println(dp[n][0]);
    input.close();
  } 
}
