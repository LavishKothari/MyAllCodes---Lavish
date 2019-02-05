public class LeetCode33 {
    public static void main(String[] args) {
        System.out.println(new LeetCode33().search(new int[]{4, 5, 6, 7, 0, 1, 2}, 0)); // 4
        System.out.println(new LeetCode33().search(new int[]{4, 5, 6, 7, 0, 1, 2}, 4)); // 0
        System.out.println(new LeetCode33().search(new int[]{4, 5, 6, 7, 0, 1, 2}, 2)); // 6
        System.out.println(new LeetCode33().search(new int[]{4, 5, 6, 7, 0, 1, 2}, 5)); // 1
        System.out.println(new LeetCode33().search(new int[]{4, 5, 6, 7, 0, 1, 2}, 1)); // 5
        System.out.println(new LeetCode33().search(new int[]{4, 5, 6, 7, 10, 1, 2}, 0)); // -1
        System.out.println(new LeetCode33().search(new int[]{}, 0)); // -1
        System.out.println(new LeetCode33().search(new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 0)); // -1
        System.out.println(new LeetCode33().search(new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 9)); // 9
        System.out.println(new LeetCode33().search(new int[]{1}, 0)); // -1
        System.out.println(new LeetCode33().search(new int[]{1, 2}, 1)); // 0
        System.out.println(new LeetCode33().search(new int[]{2, 1}, 1)); // 1
    }

    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return -1;
        int pivot = findPivot(nums);
        if (nums[nums.length - 1] > target)
            return binSearch(nums, pivot, nums.length - 1, target);
        else if (nums[nums.length - 1] == target)
            return nums.length - 1;
        else return binSearch(nums, 0, pivot - 1, target);
    }

    private int binSearch(int[] nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    private int findPivot(int[] nums) {
        if (nums[0] < nums[nums.length - 1] || nums.length == 1)
            return 0;
        // if the execution is here, it is rotated by at least 1 element
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isProperPivot(nums, mid))
                return mid;
            if (isProperPivot(nums, low))
                return low;
            if (isProperPivot(nums, high))
                return high;
            if (nums[low] < nums[mid])
                low = mid + 1;// because of this low can cross the pivot
            else if (nums[low] > nums[mid])
                high = mid - 1;
        }
        // should never be the case
        return -1;
    }

    private boolean isProperPivot(int[] nums, int index) {
        return index != 0 && nums[index - 1] > nums[index];
    }

}
