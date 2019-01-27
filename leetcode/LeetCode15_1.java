import java.util.*;
/*
    Time complexity - O(n^2)
    Space complexity - O(n)
*/

public class LeetCode15_1 {
    public static void main(String[] args) {
        System.out.println(new LeetCode15_1().threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
        System.out.println(new LeetCode15_1().threeSum(new int[]{1, 2, 3}));
        System.out.println(new LeetCode15_1().threeSum(new int[]{0, 0, 0}));
        System.out.println(new LeetCode15_1().threeSum(new int[]{-2, 0, 0, 2, 2}));
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            List<List<Integer>> lists = findPair(i + 1, -nums[i], nums);
            for (List<Integer> cl : lists) {
                result.add(Arrays.asList(new Integer[]{nums[i], cl.get(0), cl.get(1)}));
            }
        }
        return new ArrayList<>(result);
    }

    private List<List<Integer>> findPair(int start, int target, int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = start, j = nums.length - 1; i < j; ) {
            if (nums[i] + nums[j] < target) {
                i++;
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                result.add(Arrays.asList(new Integer[]{nums[i], nums[j]}));
                i++;
                j--;
            }
        }
        return result;
    }
}
