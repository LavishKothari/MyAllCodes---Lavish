import java.util.Scanner;

class CRDS {
    private final static long M = 1000007;
    private static long sum(long n){
        return ((n*(n+1))/2)%M;
    }
    private static long solve(int n){
        return (sum(n)*2 + sum(n-1))%M;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            System.out.println(solve(n));
        }
    }
}
