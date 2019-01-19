import java.util.*;

public class LeetCode78 {
    public static void main(String[] args) {
        System.out.println(new LeetCode78().subsets(new int[]{1,2}));
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        int x = 1 << nums.length;
        for (int i = 0; i < x; i++) {
            List<Integer> cl = new ArrayList<>();
            int counter=0;
            int j=i;
            while (j != 0) {
                if ((j & 1) == 1) {
                    cl.add(nums[counter]);
                }
                j = (j >> 1);
                counter++;
            }
            result.add(cl);
        }
        return result;
    }

    public List<List<Integer>> subsets1(int[] nums) {
        List<List<Integer>> result = get(nums, 0);
        return result;
    }

    public List<List<Integer>> get(int[] nums, int counter) {
        if (counter == nums.length) {
            List<List<Integer>> lists = new ArrayList<>();
            lists.add(new ArrayList<>());
            return lists;
        }

        List<List<Integer>> result = get(nums, counter + 1);
        List<List<Integer>> newR = new ArrayList<>(result);
        for (List<Integer> list : result) {
            List<Integer> cl = new ArrayList<>(list);
            cl.add(nums[counter]);
            newR.add(cl);
        }
        return newR;
    }

}
