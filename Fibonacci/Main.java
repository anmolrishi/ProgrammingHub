import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Fibonacci();

    }
    private static void Fibonacci() {
        int n;
        double num1 = 0, num2 = 1, num;
        Scanner scan = new Scanner(System.in);
        System.out.println("Введіть n");
        n = scan.nextInt();
        for (int i = 0; i < n; i++) {
            num = num1 + num2;
            num1 = num2;
            num2 = num;
            int numint = (int) num;
            System.out.println("" + numint);
        }
    }
}
