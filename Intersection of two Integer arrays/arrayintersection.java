//by Siddharth Saurabh (https://github.com/siddhartthecoder)
   import java.util.*;

   public class arrayintersection {

    public static void main(String[] args) {

     Scanner sc = new Scanner(System.in);

     System.out.println("enter number of elements in first array");

     int n = sc.nextInt();

     int arr1[] = new int[n];

     System.out.println("enter elements");

     for (int i = 0; i < n; i++) { //for reading array 1
      arr1[i] = sc.nextInt();

     }

     System.out.println("enter number of elements in second array");

     int m = sc.nextInt();

     int arr2[] = new int[m];

     System.out.println("enter elements");

     for (int i = 0; i < m; i++) { //for reading array 2
      arr2[i] = sc.nextInt();

     }
     System.out.println("The intersection is :");
     //Intersection logic
     for (int i = 0; i < arr1.length; i++) {
      for (int j = 0; j < arr2.length; j++) {
       if (arr1[i] == arr2[j]) {
        System.out.print(" " + arr2[j] + " ");
       }
      }
     }
     System.out.println("");

    }

   }
