import java.util.Scanner;

class MAXLN {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int i=1;
        while (t-- > 0) {
            double n = sc.nextDouble();
            System.out.println("Case "+i+": "+(4 * n * n + 0.25));
            i++;
        }
    }

}
