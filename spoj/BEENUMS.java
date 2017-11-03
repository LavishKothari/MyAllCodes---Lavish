import java.util.Scanner;

class BEENUMS {
    private static boolean isPerfectSquare(long n){
        long x = (long)Math.sqrt(n);
        while(x*x<n) {
            x++;
        }
        if(x*x>n)
            return false;
        return true;
    }
    private static void solve(long n){
        if(isPerfectSquare(12*n-3))
            System.out.println('Y');
        else System.out.println('N');
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(true){
            int n = sc.nextInt();
            if(n==-1)
                break;
            solve((long)n);
        }
    }
}
