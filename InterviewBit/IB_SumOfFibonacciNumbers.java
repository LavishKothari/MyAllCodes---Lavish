import java.util.ArrayList;
import java.util.List;

public class IB_SumOfFibonacciNumbers {
    public static void main(String[] args) {
        System.out.println(new IB_SumOfFibonacciNumbers().fibsum(15));
    }
    /*
        dp[i][j] = using the first i elements from the
        fibonacci series, what is the solution for sum j

        dp[i][j] = min(dp[i-1][j], dp[i][j-(ith fib)]

     */

    private static void print(int[][] dp) {
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++)
                System.out.print(dp[i][j] + " ");
            System.out.println();
        }
    }

    public int fibsum(int number) {
        List<Integer> fib = new ArrayList<>();
        fib.add(1);
        fib.add(1);
        while (true) {
            int x = fib.get(fib.size() - 1);
            int y = fib.get(fib.size() - 2);
            if (x + y > number)
                break;

            fib.add(x + y);
        }

        int[][] dp = new int[fib.size() + 1][number + 1];
        for (int i = 0; i <= number; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= fib.size(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= fib.size(); i++) {
            for (int j = 1; j <= number; j++) {
                if (j % fib.get(i - 1) == 0) {
                    dp[i][j] = j / fib.get(i - 1);
                } else {
                    if (j - fib.get(i - 1) >= 0)
                        dp[i][j] = Math.min(dp[i - 1][j], 1 + dp[i][j - fib.get(i - 1)]);
                    else dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[fib.size()][number];
    }
}
