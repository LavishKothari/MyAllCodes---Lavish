import java.util.Scanner;

class FENCE1 {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                break;
//            System.out.println(Math.round(n / (2 * Math.PI) * 100.0 * n) / 100.0);
            System.out.format("%.2f\n",n / (2 * Math.PI) * n);
        }
    }
}
