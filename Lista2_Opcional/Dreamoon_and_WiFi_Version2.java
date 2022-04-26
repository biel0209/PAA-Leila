package Lista2_Opcional;

import java.util.Scanner;

public class Dreamoon_and_WiFi_Version2 {
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);

    String str1 = "++-+-";
    String str2 = "+-+-+";
    char[] s1 = str1.toCharArray();
    char[] s2 = str2.toCharArray();

    int level = 50, pos = 50;
    int len1 = s1.length-1;

    for(int i=1; i <= len1; i++){
      if(s1[i] == '+')
        pos++;
      else
        pos--;
    }

    double[][] dp = new double[100][100];
    dp[0][level] = 1;

    for(int i=1; i <= len1; i++){
      if(s2[i] == '+'){
        for(int j=1; j<100; j++){
          dp[i][j] = dp[i-1][j-1];
        }
      }
      if(s2[i] == '-'){
        for(int j=0; j<99; j++){
          dp[i][j] = dp[i-1][j+1];
        }
      }
      if(s2[i] == '?'){
        for(int j=1; j<99; j++){
          dp[i][j] = 0.5*dp[i-1][j-1] + 0.5*dp[i-1][j+1];
        }
      }
    }
    System.out.println(dp[len1][pos]);
    input.close();
  }


  
}
