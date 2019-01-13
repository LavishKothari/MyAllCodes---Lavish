public class LeetCode279 {
    public static void main(String[] args) {
        System.out.println(new LeetCode279().numSquares(13));
    }

    public int numSquares(int n) {
        int x = findNumber(n);
        int[][] dp = new int[n + 1][x + 1];
        for (int i = 1; i <= n; i++) {
            dp[i][1] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= x; j++) {
                int min = Integer.MAX_VALUE;
                if (i - j * j >= 0)
                    min = Math.min(min, dp[i - j * j][j] + 1);
                min = Math.min(min, dp[i][j - 1]);
                dp[i][j] = min;
            }

        }
//        for (int i = 0; i < dp.length; i++) {
//            for (int j = 0; j < dp[i].length; j++) {
//                System.out.print(dp[i][j] + " ");
//            }
//            System.out.println();
//        }
        return dp[n][x];
    }

    /**
     * This method returns number whose square is just before n. If n is itself perfect square, it returns n
     */
    private int findNumber(int n) {
        for (int i = 1; ; i++) {
            if (i * i > n)
                return (i - 1);
        }
    }


}
