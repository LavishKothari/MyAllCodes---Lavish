public class LeetCode152 {
    public static void main(String[] args) {
        System.out.println(new LeetCode152().maxProduct(new int[]{2,3,-2,4}));
    }
    public int maxProduct(int[] nums) {
        int[] max = new int[nums.length];
        int[] min = new int[nums.length];

        max[0] = min[0] = nums[0];

        for(int i=1;i<nums.length;i++) {
            max[i] = max3(max[i-1]*nums[i], min[i-1]*nums[i], nums[i]);
            min[i] = min3(max[i-1]*nums[i], min[i-1]*nums[i], nums[i]);
        }
        int answer = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++) {
            answer = Math.max(answer, max[i]);
        }
        return answer;
    }

    private int max3(int a, int b, int c) {
        return Math.max(c, Math.max(a,b));
    }

    private int min3(int a, int b, int c) {
        return Math.min(c, Math.min(a,b));
    }

}
