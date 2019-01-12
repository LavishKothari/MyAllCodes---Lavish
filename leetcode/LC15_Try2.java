import java.util.*;

class Solution15_Try2 {

    public static void main(String[] args) {
        int[] array = new int[]{-1, 0, 1, 2, -1, -4, 0, 0, 0};
        // -4 -1 -1 0 1 2
        List<List<Integer>> list = new Solution15_Try2().threeSum(array);
        System.out.println(list);

    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        Set<Integer> found = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (found.contains(nums[i]) && nums[i] != 0)
                continue;
            // for both on the left
            List<List<Integer>> list1 = find2SumPossible(nums, 0, i, -nums[i]);
            for (List<Integer> currentList : list1) {
                List<Integer> tempList = Arrays.asList(currentList.get(0), currentList.get(1), nums[i]);
                Collections.sort(tempList);
                result.add(tempList);
            }

            // for one in left and one in right
            for (int j = i + 1; j < nums.length; j++) {
                int searchInLeft = -nums[i] - nums[j];
                if (found.contains(searchInLeft)) {
                    result.add(Arrays.asList(new Integer[]{searchInLeft, nums[i], nums[j]}));
                }
            }

            // at the end
            found.add(nums[i]);
        }

        return result;
    }

    /*
     * start inclusive and end exclusive
     */
    private List<List<Integer>> find2SumPossible(int[] nums, int start, int end, int requiredSum) {
        List<List<Integer>> result = new ArrayList<>();
        if (start >= nums.length || end < 0 || start > end)
            return result;

        for (int i = start, j = end - 1; i < j; ) {
            int currentSum = nums[i] + nums[j];
            if (currentSum == requiredSum) {
                result.add(Arrays.asList(new Integer[]{nums[i], nums[j]}));
                i++;
                j--;
            } else if (currentSum < requiredSum) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
}
