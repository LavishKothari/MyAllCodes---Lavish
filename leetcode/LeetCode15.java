import java.util.*;

class Solution15 {

    public static void main(String[] args) {
        int[] array = new int[]{-1, 0, 1, 2, -1, -4};
        List<List<Integer>> list = new Solution15().threeSum(array);
        System.out.println(list);

    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Set<List<Integer>> resultSet = new HashSet<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            int count = 1;
            if (map.containsKey(i)) {
                count += map.get(i);
            }
            map.put(i, count);
        }

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int currentKey = entry.getKey();
            int currentValue = entry.getValue();
            map.put(currentKey, currentValue - 1);
            List<List<Integer>> twoSumLists = find2SumPossible(map, -currentKey);
            if (twoSumLists.size() > 0) {
                for (List<Integer> oneTwoSumList : twoSumLists) {
                    List<Integer> tempList = new ArrayList<>();
                    tempList.add(currentKey);
                    tempList.addAll(oneTwoSumList);
                    Collections.sort(tempList); // sorting an array of 3 elements
                    resultSet.add(tempList);
                }
            }
            map.put(currentKey, currentValue);
        }
        for (List<Integer> element : resultSet) {
            result.add(element);
        }
        return result;
    }

    private List<List<Integer>> find2SumPossible(Map<Integer, Integer> map, int sum) {
        List<List<Integer>> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int currentKey = entry.getKey();
            int currentValue = entry.getValue();
            if (currentValue > 0) {
                map.put(currentKey, currentValue - 1);
                int requiredNumber = sum - currentKey;
                if (map.containsKey(requiredNumber) && map.get(requiredNumber) > 0) {
                    list.add(Arrays.asList(new Integer[]{currentKey, requiredNumber}));
                }
                map.put(currentKey, currentValue);
            }
        }
        return list;
    }
}
