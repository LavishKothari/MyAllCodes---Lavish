// {1, 2} target = 3 solution should be {0,1}
// {2, 2} target = 4 solution should be {0,1}
/*
extra space - O(n)
time complexity - O(n)
*/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode1 {
    public static void main(String[] args) {
        int []r1 = new LeetCode1().twoSum(new int[]{1, 2}, 3);
        System.out.println(r1[0] + " " + r1[1]);
        int []r2 = new LeetCode1().twoSum(new int[]{2, 2}, 4);
        System.out.println(r2[0] + " " + r2[1]);
    }

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.putIfAbsent(nums[i], new ArrayList<>());
            map.get(nums[i]).add(i);
        }
        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
            int toBeSearched = target - entry.getKey();
            if (toBeSearched == entry.getKey() && entry.getValue().size() > 1) {
                return new int[]{entry.getValue().get(0), entry.getValue().get(1)};
            } else if (map.containsKey(toBeSearched) && map.get(toBeSearched).size() > 0) {
                return new int[]{entry.getValue().get(0), map.get(toBeSearched).get(0)};
            }
        }
        // should never be the case
        return new int[]{-1, -1};
    }


}
