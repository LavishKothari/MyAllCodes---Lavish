public class LeetCode287 {
    public static void main(String[] args) {
        System.out.println(new LeetCode287().findDuplicate(new int[]{3, 1, 3, 4, 2}));
    }

    public int findDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; ) {
            int cn = nums[i] - 1;
            int ci = i;
            if (ci != cn) {
                if (cn == nums[cn] - 1) return cn + 1;
                swap(nums, cn, ci);
            }
            if (nums[i] - 1 == i) i++;
        }
        throw new IllegalArgumentException("array not valid");
    }

    private void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
