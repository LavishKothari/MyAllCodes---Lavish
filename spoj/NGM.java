import java.util.Scanner;

class NGM {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n % 10 == 0)
            System.out.println(2);
        else {
            System.out.println(1);
            System.out.println(n % 10);
        }
    }

}
