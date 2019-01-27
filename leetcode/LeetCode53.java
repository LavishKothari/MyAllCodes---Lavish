public class LeetCode53 {
    public static void main(String[] args) {
        System.out.println(new LeetCode53().maxSubArray(new int[]{-10, -2, -3, -1})); // -1
        System.out.println(new LeetCode53().maxSubArray(new int[]{-1, -6, -9, -9})); // -1
        System.out.println(new LeetCode53().maxSubArray(new int[]{-5, -8, 6, -8, -7})); // 6
        System.out.println(new LeetCode53().maxSubArray(new int[]{4, 6, -11, 7, 8, 0, -3, 10}));// 22
        System.out.println(new LeetCode53().maxSubArray(new int[]{-5, 6})); // 6
    }

    public int maxSubArray(int[] nums) {
        if (nums.length == 0)
            return 0;
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (currentSum < 0)
                currentSum = 0; // should I initialize it to 0

            currentSum = currentSum + nums[i];
            if (maxSum < currentSum)
                maxSum = currentSum;
        }
        return maxSum;
    }
}
