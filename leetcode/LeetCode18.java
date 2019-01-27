/*
Time complexity - O(n^2)
Space complexity - O(n^2)

test cases:
{1, 2, 3, 4, 1} target = 12 // should return an empty list
*/

import java.util.*;

public class LeetCode18 {
    public static void main(String[] args) {
        System.out.println(new LeetCode18().fourSum(new int[]{1, 0, -1, 0, -2, 2}, 0));
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Map<Integer, List<List<Integer>>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int cs = nums[i] + nums[j];
                map.putIfAbsent(cs, new ArrayList<List<Integer>>());
                map.get(cs).add(Arrays.asList(new Integer[]{i, j}));
            }
        }
        Set<List<Integer>> result = new HashSet<>();
        for (Map.Entry<Integer, List<List<Integer>>> entry : map.entrySet()) {
            int a = entry.getKey();
            int b = target - a;
            if (map.containsKey(b)) {
                acc(entry.getValue(), map.get(b), result, nums);
            }
        }
        List<List<Integer>> finalResult = new ArrayList<>();
        finalResult.addAll(result);
        return finalResult;
    }

    private void acc(List<List<Integer>> list1, List<List<Integer>> list2, Set<List<Integer>> result, int[] nums) {
        for (List<Integer> pair1 : list1) {
            for (List<Integer> pair2 : list2) {
                assert pair1.size() == 2;
                assert pair2.size() == 2;
                if (checkIfDistinct(pair1.get(0), pair1.get(1), pair2.get(0), pair2.get(1))) {
                    int w = nums[pair1.get(0)];
                    int x = nums[pair1.get(1)];
                    int y = nums[pair2.get(0)];
                    int z = nums[pair2.get(1)];

                    List<Integer> tempList = new ArrayList<>(4);
                    tempList.addAll(Arrays.asList(new Integer[]{w, x, y, z}));
                    Collections.sort(tempList); // this is to find unique quadruples
                    result.add(tempList);
                }
            }
        }
    }

    private boolean checkIfDistinct(int a, int b, int c, int d) {
        Set<Integer> set = new HashSet<>();
        set.addAll(Arrays.asList(new Integer[]{a, b, c, d}));
        return set.size() == 4;
    }
}
