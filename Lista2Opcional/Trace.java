package Lista2Opcional;

import java.util.Scanner;

public class Trace{
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    int[] array = new int[n];
    
    for (int i = 0; i < n; ++i)
        array[i] = input.nextInt();
    
    heapSort(array, n);
    int somaRaio = 0;
    for (int i = 0; i < n; ++i)
        somaRaio += array[i] * array[i] * (1 - i % 2 * 2);

    System.out.println(Math.PI * somaRaio);
    input.close();
  }

  public static void trocar(int[] array, int a, int b){
    int aux;
    aux = array[b];
    array[b] = array[a];
    array[a] = aux;
  }

  public static void minHeapify(int[] array, int n, int i){
    int menor = i;
    int esq = (2*i)+1;
    int dir = (2*i)+2;
    if (esq < n && array[esq] < array[i])
        menor = esq;
    
    if (dir < n && array[dir] < array[menor])
        menor = dir;

    if (menor != i){
        trocar(array, menor, i);  
        minHeapify(array, n, menor);
    }
  } 

  public static void montaMinHeap(int[] array, int n)
  {
      for(int i = n/2 - 1; i>=0; i--){
          minHeapify(array, n, i);
      }
  }

  public static void heapSort(int[] array, int n)
  {
      montaMinHeap(array, n);
      for (int i=n-1; i>=1; i--){
          trocar(array, 0, i);
          minHeapify(array, i, 0);
      }
  }
}
