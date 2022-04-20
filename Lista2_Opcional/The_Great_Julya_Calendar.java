package Lista2_Opcional;

import java.util.Scanner;

public class The_Great_Julya_Calendar {
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    String num = String.valueOf(n);
    int cont=0;
    while(Integer.parseInt(num) != 0 && Integer.parseInt(num) > 0){
      int maiorDigito = buscarMaiorDigito(num);
      num = String.valueOf(Integer.parseInt(num) - maiorDigito);
      cont++;
    }
    System.out.println(cont);
    input.close();
  }      

  public static int buscarMaiorDigito(String num){
    char maior = num.charAt(0);
    for(int i=0; i < num.length(); i++){
      if(num.charAt(i) == 9)
        return 9;
      else if(num.charAt(i) > maior)
        maior = num.charAt(i);
    }
    return Character.getNumericValue(maior);
  }
}
