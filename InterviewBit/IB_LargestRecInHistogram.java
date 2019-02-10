import java.util.*;
import java.util.stream.Collectors;

public class IB_LargestRecInHistogram {
    public static void main(String[] args) {
        System.out.println(new IB_LargestRecInHistogram().largestRectangleArea(
                new ArrayList<>(Arrays.asList(2, 1, 5, 6, 2, 3)))); // 10
        System.out.println(new IB_LargestRecInHistogram().largestRectangleArea(
                new ArrayList<>(Arrays.asList(6, 2, 5, 4, 5, 1, 6)))); // 12
        System.out.println(new IB_LargestRecInHistogram().largestRectangleArea(
                new ArrayList<>(Arrays.asList(1, 1)))); // 2
    }

    public int largestRectangleArea(ArrayList<Integer> list) {
        List<Integer> nextSmaller = nextSmaller(list);
        List<Integer> prevSmaller = prevSmaller(list);
        int max = 0;
        for (int i = 0; i < list.size(); i++) {
            int ns = nextSmaller.get(i);
            int ps = prevSmaller.get(i);
            int right = (ns == -1 ? list.size() : ns);
            int left = ps;
            int cm = list.get(i) * (right - left - 1);
            max = Math.max(max, cm);
        }
        return max;
    }

    private List<Integer> prevSmaller(ArrayList<Integer> list) {
        ArrayList<Integer> cl = new ArrayList<>(list);
        Collections.reverse(cl);
        // next greater of reverse
        List<Integer> result = nextSmaller(cl);
        Collections.reverse(result);
        return result.stream()
                .map(a -> a == -1 ? a : list.size() - 1 - a)
                .collect(Collectors.toList());
    }

    private List<Integer> nextSmaller(ArrayList<Integer> list) {
        Deque<Integer> stack = new ArrayDeque<>(list.size());
        ArrayList<Integer> result = new ArrayList<>(list.size());
        for (int i = 0; i < list.size(); i++)
            result.add(-1);
        for (int i = 0; i < list.size(); i++) {
            int current = list.get(i);
            if (stack.size() == 0) {
                stack.push(i);
                continue;
            }
            if (list.get(stack.peek()) <= current) stack.push(i);
            else {
                while (stack.size() > 0 && list.get(stack.peek()) > current) {
                    result.set(stack.pop(), i);
                }
                stack.push(i);
            }
        }
        return result;
    }
}
