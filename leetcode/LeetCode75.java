public class LeetCode75 {
    public static void main(String[] args) {
        int[] arr = new int[]{1,0,1};
        new LeetCode75().sortColors(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }

    }

    public void sortColors(int[] nums) {
        int c1 = 0, c2 = nums.length - 1;
        for (int i = 0; i < nums.length; i++) {
            if (i > c2) {
                break;
            }
            if (nums[i] == 0) {
                swap(nums, i, c1);
                c1++;
            } else if (nums[i] == 2) {
                swap(nums, i, c2);
                c2--;
                i--;
            }
        }
    }

    private void swap(int[] nums, int a, int b) {
        if (a >= 0 && b >= 0) {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
        }
    }

}
