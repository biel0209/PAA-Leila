package Lista2_Opcional;

import java.math.BigDecimal;
import java.util.Scanner;

public class Dreamoon_and_WiFi_Version2 {
  public static void main(String[] args){

    Scanner input = new Scanner(System.in);
    String str1 = "--+++---+-";
    String str2 = "??????????";
    // String str1 = input.nextLine();
    // String str2 = input.nextLine();
    char[] s1 = str1.toCharArray();
    char[] s2 = str2.toCharArray();

    int lin = 50, col = 50;
    int tam1 = s1.length-1;
    int tamDp = 100;

    for(int i=1; i <= tam1; i++){
      if(s1[i] == '+')
        col++;
      else
        col--;
    }

    double[][] dp = new double[tamDp][tamDp];
    dp[0][lin] = 1;

    for(int i=1; i <= tam1; i++){
      if(s2[i] == '+'){
        for(int j=1; j<tamDp; j++){
          dp[i][j] = dp[i-1][j-1];
        }
      }
      else if(s2[i] == '-'){
        for(int j=0; j<tamDp-1; j++){
          dp[i][j] = dp[i-1][j+1];
        }
      }
      else if(s2[i] == '?'){
        for(int j=1; j<tamDp-1; j++){
          dp[i][j] = (double)(0.5*dp[i-1][j-1]) + (double)(0.5*dp[i-1][j+1]);
        }
      }
    }
    System.out.println(dp[tam1][col]);
    input.close();
  } 
}
