import java.util.Arrays;

class Solution416 {
    public static void main(String[] args) {
        System.out.println(new Solution416().canPartition(new int[]{1, 5, 11, 5}));
    }

    public boolean canPartition(int[] nums) {

        int s=0;
        Arrays.stream(nums).sum();

        int sum = Arrays.stream(nums).sum();

        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;

        boolean[][] dp = new boolean[nums.length + 1][sum + 1];
        for (int j = 0; j < sum + 1; j++) {
            dp[0][j] = false;
        }
        for (int i = 0; i < nums.length + 1; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < nums.length + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                dp[i][j] = dp[i - 1][j] || ((j - nums[i - 1]) >= 0 ? dp[i - 1][j - nums[i - 1]] : false);
            }
        }
//        for (int i = 0; i < dp.length; i++) {
//            for (int j = 0; j < dp[i].length; j++) {
//                System.out.print(" " + dp[i][j]);
//            }
//            System.out.println();
//        }
        return dp[nums.length][sum];

    }
}

