import java.util.ArrayList;
import java.util.List;

public class LeetCode54 {
    public static void main(String[] args) {
        System.out.println(new LeetCode54().spiralOrder(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
        System.out.println(new LeetCode54().spiralOrder(new int[][]{{1, 2, 3}}));
        System.out.println(new LeetCode54().spiralOrder(new int[][]{{1}, {2}, {3}}));

        System.out.println(new LeetCode54().spiralOrder(new int[][]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}));
        System.out.println(new LeetCode54().spiralOrder(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}));
        System.out.println(new LeetCode54().spiralOrder(new int[][]{{1, 2, 3}, {4, 5, 6}}));
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix == null || matrix.length == 0)
            return result;

        int upper = -1, right = matrix[0].length, lower = matrix.length, left = -1;
        int x = left + 1;
        int y = upper + 1;
        while (upper < lower && left < right) {

            if (!xySanity(x, y, upper, lower, left, right)) break;
            for (; x < right; x++)
                result.add(matrix[y][x]);
            x--;
            y++;
            upper++;
            if (!xySanity(x, y, upper, lower, left, right)) break;
            for (; y < lower; y++)
                result.add(matrix[y][x]);
            x--;
            y--;
            right--;
            if (!xySanity(x, y, upper, lower, left, right)) break;
            for (; x > left; x--)
                result.add(matrix[y][x]);
            x++;
            y--;
            lower--;
            if (!xySanity(x, y, upper, lower, left, right)) break;
            for (; y > upper; y--)
                result.add(matrix[y][x]);
            left++;
            x++;
            y++;
        }
        return result;

    }

    private boolean xySanity(int x, int y, int upper, int lower, int left, int right) {
        return (x > left && x < right && y > upper && y < lower);
    }

}
