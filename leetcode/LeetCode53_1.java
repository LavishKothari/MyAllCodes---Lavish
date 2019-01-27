public class LeetCode53_1 {
    public static void main(String[] args) {
        System.out.println(new LeetCode53_1().maxSubArray(new int[]{-10, -2, -3, -1})); // -1
        System.out.println(new LeetCode53_1().maxSubArray(new int[]{-1, -6, -9, -9})); // -1
        System.out.println(new LeetCode53_1().maxSubArray(new int[]{-5, -8, 6, -8, -7})); // 6
        System.out.println(new LeetCode53_1().maxSubArray(new int[]{4, 6, -11, 7, 8, 0, -3, 10}));// 22
        System.out.println(new LeetCode53_1().maxSubArray(new int[]{-5, 6})); // 6
    }

    /**
     * A dynamic programming solution
     */
    public int maxSubArray(int[] nums) {
        /*
         * dp[i] stores the sum of contiguous sub-array
         * that ends at ith index and has max sum
         */
        int[] dp = new int[nums.length];
        int max;
        max = dp[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (dp[i - 1] + nums[i] > nums[i])
                dp[i] = dp[i - 1] + nums[i];
            else dp[i] = nums[i];
            if (max < dp[i])
                max = dp[i];
        }
        return max;
    }

}
