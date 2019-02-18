public class LeetCode11 {
    public static void main(String[] args) {
        System.out.println(new LeetCode11().maxArea(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7}));
    }

    public int maxArea(int[] height) {
        if (height == null || height.length == 0)
            return 0;
        int max = 0;
        for (int i = 0, j = height.length - 1; j > i; ) {
            max = Math.max(max, (j - i) * Math.min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return max;
    }
}
