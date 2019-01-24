public class LeetCode162 {
    public static void main(String[] args) {
        System.out.println(new LeetCode162().findPeakElement(new int[]{1, 2, 3, 4, 3}));
    }

    public int findPeakElement(int[] nums) {
        int low = 0, high = nums.length - 1;
        while (low <= high) {// TODO check if this is correct
            if (isPeak(nums, low))
                return low;
            if (isPeak(nums, high))
                return high;
            int mid = (low + high) / 2;
            if (isPeak(nums, mid))
                return mid;

            if (nums[mid] <= nums[high])
                low = mid + 1;
            else if (nums[mid] <= nums[low])
                high = mid - 1;
            else {
                if (nums[mid] < nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }


        }
        return -1; // this should never happen
    }

    private boolean isPeak(int[] nums, int index) {
        if (nums.length == 1)
            return true;
        if (index == 0) {
            return nums[0] > nums[1];
        }
        if (index == nums.length - 1) {
            return nums[nums.length - 1] > nums[nums.length - 2];
        }
        return nums[index] > nums[index + 1] && nums[index] > nums[index - 1];
    }

}
