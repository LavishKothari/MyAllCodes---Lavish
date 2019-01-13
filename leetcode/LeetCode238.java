import java.util.Arrays;

public class LeetCode238 {

    public static void main(String[] args) {
        System.out.println(new LeetCode238().productExceptSelf(new int[]{1, 2, 3, 4}));
    }

    public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        int cp = 1;
        for (int i = 0; i < nums.length; i++) {
            result[i] = cp;
            cp *= nums[i];
        }
        cp = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            result[i] *= cp;
            cp *= nums[i];
        }
        return result;
    }

}
