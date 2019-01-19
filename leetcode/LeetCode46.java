import java.util.*;

public class LeetCode46 {

    public static void main(String[] args) {
        System.out.println(new LeetCode46().permute(new int[]{1, 2, 3}));
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        permute(nums, 0, result);
        return result;
    }

    private void permute(int[] nums, int counter, List<List<Integer>> result) {
        if (counter == nums.length) {
            List<Integer> cl = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                cl.add(nums[i]);
            }
            result.add(cl);
            return;
        }
        for (int i = counter; i < nums.length; i++) {
            swap(nums, counter, i);
            permute(nums, counter + 1, result);
            swap(nums, counter, i);
        }
    }

    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

}
