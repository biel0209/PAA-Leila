package Lista2_Opcional;

import java.util.HashMap;
import java.util.Scanner;

public class The_Great_Julya_Calendar_Version2{
  public static int numPassos(int n){
    HashMap<Integer,Integer> dp = new HashMap<Integer,Integer>();

    // Casos bases
    dp.put(0, 0);
    dp.put(1, 1);

    if (!dp.containsKey(n))
      dp.put(n, 1 + Math.min(n % 2 +
          numPassos(n / 2), n % 3 +
          numPassos(n / 3)));
  
    return dp.get(n);
  }

  public static void main(String[] args){
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();

    System.out.println(String.valueOf((numPassos(n))));
    input.close();
  }
}

// This code is contributed by Amit Katiyar
