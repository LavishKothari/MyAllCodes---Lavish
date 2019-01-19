public class LeetCode91 {
    public static void main(String[] args) {
        System.out.println(new LeetCode91().numDecodings("12"));
        System.out.println(new LeetCode91().numDecodings("226"));
        System.out.println(new LeetCode91().numDecodings("0"));
        System.out.println(new LeetCode91().numDecodings("10"));
        System.out.println(new LeetCode91().numDecodings("01"));


    }

    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        dp[0] = s.charAt(0) != '0' ? 1 : 0;
        for (int i = 1; i < s.length(); i++) {
            dp[i] = s.charAt(i) != '0' ? dp[i - 1] : 0;
            char a = s.charAt(i - 1);
            char b = s.charAt(i);
            if (checkGood(a, b)) {
                if (i - 2 >= 0)
                    dp[i] += dp[i - 2];
                else dp[i] = dp[i] + 1;
            }
        }
        return dp[s.length() - 1];
    }

    private boolean checkGood(char a, char b) {
        if(a=='0')
            return false;
        int temp = (a - '0') * 10 + b - '0';
        return temp > 0 && temp <= 26;
    }


}
