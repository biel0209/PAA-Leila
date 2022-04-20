package Lista2_Opcional;

import java.util.Scanner;
import java.util.ArrayList;

public class Dreamoon_and_WiFi {
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);

    String str1 = "+-+-";
    String str2 = "+-??";
    char[] s1 = str1.toCharArray();
    char[] s2 = str2.toCharArray();

    int posFinal = posicaoFinal(s1);

    ArrayList<Integer> posicoesFinais = new ArrayList();

    buscarPossibilidades(s2, 0, posicoesFinais);

    int cont=0;
    for(int i=0; i < posicoesFinais.size(); i++){
      if(posicoesFinais.get(i) == posFinal)
        cont++;
    }

    double probabilidade = (double) cont/posicoesFinais.size();
    System.out.println(probabilidade);

    input.close();
  }

  public static int posicaoFinal(char[] str){
    int posFinal = 0;
    for(int i=0; i<str.length; i++){
      if(str[i] == '+')
        posFinal++;
      else
        posFinal--;
    }
    return posFinal;
  }

  public static void buscarPossibilidades(char[] str, int index, ArrayList<Integer> posicoesFinais)
  {
      if (index == str.length){
          posicoesFinais.add(posicaoFinal(str));
          return;
      }

      if (str[index] == '?'){
          str[index] = '-';
          buscarPossibilidades(str, index + 1, posicoesFinais);
           
          str[index] = '+';
          buscarPossibilidades(str, index + 1, posicoesFinais);

          str[index] = '?';
      }else
          buscarPossibilidades(str, index + 1, posicoesFinais);
  }
  
}
