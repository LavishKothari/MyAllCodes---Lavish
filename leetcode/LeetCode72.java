public class LeetCode72 {
    public static void main(String[] args) {
        System.out.println(new LeetCode72().minDistance1("sea", "ate"));
    }

    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= word1.length(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.length(); i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]); // for insertion or deletion of char
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1]) + 1; // for replacement of char
                }
            }
        }
        return dp[word1.length()][word2.length()];

    }

    // with O(n) space complexity
    public int minDistance1(String word1, String word2) {
        int[][] dp = new int[2][word2.length() + 1];
        dp[1][0] = 1;
        for (int j = 0; j < word2.length(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.length(); i++) {
            int dpiIndex = i & 1; // int dpiIndex = i % 2;
            dp[dpiIndex][0] = i; // CATION: this is important - you might miss this
            int otherIndex = dpiIndex ^ 1;

            for (int j = 1; j <= word2.length(); j++) {
                int diff = 0;
                if (word1.charAt(i - 1) != word2.charAt(j - 1)) {
                    diff++;
                }
                dp[dpiIndex][j] = min3(dp[otherIndex][j] + 1,
                        dp[dpiIndex][j - 1] + 1,
                        diff + dp[otherIndex][j - 1]);
            }
        }
        return dp[word1.length() & 1][word2.length()];
    }

    private int min3(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}
