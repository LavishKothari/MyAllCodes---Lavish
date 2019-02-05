public class LeetCode34 {
    public static void main(String[] args) {
        {
            int answer[] = new LeetCode34().searchRange(new int[]{5, 7, 7, 8, 8, 10}, 8);
            System.out.println(answer[0] + " " + answer[1]);
        }
        {
            int answer[] = new LeetCode34().searchRange(new int[]{5, 7, 7, 8, 8, 10}, 6);
            System.out.println(answer[0] + " " + answer[1]);
        }
        {
            int answer[] = new LeetCode34().searchRange(new int[]{5}, 6);
            System.out.println(answer[0] + " " + answer[1]);
        }
        {
            int answer[] = new LeetCode34().searchRange(new int[]{5}, 5);
            System.out.println(answer[0] + " " + answer[1]);
        }
        {
            int answer[] = new LeetCode34().searchRange(new int[]{5, 7}, 7);
            System.out.println(answer[0] + " " + answer[1]);
        }
        {
            int answer[] = new LeetCode34().searchRange(new int[]{6, 6, 6, 6}, 6);
            System.out.println(answer[0] + " " + answer[1]);
        }
        {
            int answer[] = new LeetCode34().searchRange(new int[]{}, 6);
            System.out.println(answer[0] + " " + answer[1]);
        }


    }

    public int[] searchRange(int[] nums, int target) {
        return new int[]{lower(nums, target), higher(nums, target)};
    }

    private int lower(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                if (isProperLow(nums, mid)) return mid;
                else high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else high = mid - 1;
        }
        return -1;
    }

    private boolean isProperLow(int[] nums, int index) {
        return index == 0 || nums[index - 1] != nums[index];
    }

    /*
     * {},2 return value = -1
     * {2}, 3 return value = -1
     * {2}, 2 return value = 0
     */
    private int higher(int[] nums, int target) {
        int high = nums.length - 1;
        int low = 0;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                if (isProperHigh(nums, mid))
                    return mid;
                else low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return -1;
    }

    private boolean isProperHigh(int[] nums, int index) {
        return index + 1 == nums.length || nums[index + 1] != nums[index];
    }

}
