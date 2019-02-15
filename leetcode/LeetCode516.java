public class LeetCode516 {
    public static void main(String[] args) {
        System.out.println(new LeetCode516().longestPalindromeSubseq("")); // 0
        System.out.println(new LeetCode516().longestPalindromeSubseq("bbbab")); // 4
        System.out.println(new LeetCode516().longestPalindromeSubseq("cbbd")); // 2
    }

    public int longestPalindromeSubseq(String s) {
        if (s == null || s.length() == 0) return 0;
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j >= n) break;
                int diff = s.charAt(i) == s.charAt(j) ? 2 : 0;
                dp[i][j] = max3(dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] + diff);
            }
        }

        return dp[0][n - 1];
    }

    private int max3(int a, int b, int c) {
        return Math.max(Math.max(a, b), c);
    }

}
