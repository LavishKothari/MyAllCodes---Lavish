import java.util.Scanner;
import java.util.TreeSet;

class HPYNOS {

    private static long get(long n) {
        long sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    private static int solve(long n) {
        TreeSet<Long> s = new TreeSet<>();
        s.add(n);
        int count = 0;
        while (true) {
//            System.out.println("-> "+n);
            n = get(n);
            if (n == 1)
                return count + 1;
            if (s.contains(n))
                return -1;
            else s.add(n);
            count++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(solve(n));
    }
}
