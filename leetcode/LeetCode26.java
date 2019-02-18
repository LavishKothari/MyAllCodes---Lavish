public class LeetCode26 {
    public static void main(String[] args) {
        System.out.println(new LeetCode26().removeDuplicates(new int[]{}));
        System.out.println(new LeetCode26().removeDuplicates(new int[]{1}));
        System.out.println(new LeetCode26().removeDuplicates(new int[]{1, 2}));
        System.out.println(new LeetCode26().removeDuplicates(new int[]{1, 2, 3}));
        System.out.println(new LeetCode26().removeDuplicates(new int[]{1, 1, 2, 2, 3, 3, 4}));
        System.out.println(new LeetCode26().removeDuplicates(new int[]{1, 1, 1, 1, 1, 1}));
        System.out.println(new LeetCode26().removeDuplicates(new int[]{1, 1, 2}));
    }

    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int cc = 0, answer = 0;
        for (int i = 1; i < nums.length; ) {
            while (i < nums.length && nums[i] == nums[cc]) i++;
            swap(nums, i, cc + 1);
            if (i == nums.length)
                answer = cc;
            else answer = cc + 1;
            cc++;
            i++;
        }
        return answer + 1;
    }

    private void swap(int[] nums, int a, int b) {
        if (a >= nums.length || b >= nums.length) return;
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
