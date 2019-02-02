import java.util.Deque;
import java.util.LinkedList;

public class LeetCode84 {
    public static void main(String[] args) {
        System.out.println(new LeetCode84().largestRectangleArea(new int[]{2, 1, 5, 6, 2, 3})); // 10
        System.out.println(new LeetCode84().largestRectangleArea(new int[]{6, 2, 5, 4, 5, 1, 6})); // 12
        System.out.println(new LeetCode84().largestRectangleArea(new int[]{1, 1})); // 2
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        if (n == 0)
            return 0;
        int[] prevSmaller = new int[n]; // stores index of previous smaller element
        Deque<Integer> stack = new LinkedList<>();
        for (int i = 0; i < n; i++)
            prevSmaller[i] = -1; // whose prevSmaller don’t exists
        for (int i = 0; i < n; i++) {
            if (stack.size() == 0)
                stack.push(i);
            else if (heights[stack.peek()] < heights[i]) {
                prevSmaller[i] = stack.peek();
                stack.push(i);
            } else if (heights[stack.peek()] >= heights[i]) {
                while (stack.size() != 0 && heights[stack.peek()] >= heights[i]) {
                    stack.pop();
                }
                if (stack.size() == 0)
                    prevSmaller[i] = -1;
                else prevSmaller[i] = stack.peek();
                stack.push(i);
            }
        }
        stack.clear();
        int[] nextSmaller = new int[n]; // stores index of next smaller element
        for (int i = 0; i < n; i++) {
            nextSmaller[i] = -1;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (stack.size() == 0)
                stack.push(i);
            else if (heights[stack.peek()] < heights[i]) {
                nextSmaller[i] = stack.peek();
                stack.push(i);
            } else if (heights[stack.peek()] >= heights[i]) {
                while (stack.size() != 0 && heights[stack.peek()] >= heights[i]) {
                    stack.pop();
                }
                if (stack.size() == 0)
                    nextSmaller[i] = -1;
                else nextSmaller[i] = stack.peek();
                stack.push(i);
            }
        }
        //printArray(prevSmaller);
        //printArray(nextSmaller);
        int max = heights[0];
        for (int i = 0; i < n; i++) {
            int prev = prevSmaller[i];
            int next = nextSmaller[i] == -1 ? n : nextSmaller[i]; // CAUTION
            int c = (next - prev - 1) * heights[i];
            if (max < c)
                max = c;
        }
        return max;
    }

    private void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

}
