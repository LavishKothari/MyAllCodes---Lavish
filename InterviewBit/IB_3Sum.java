import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * https://www.interviewbit.com/problems/3-sum/
 * <p>
 * Time complexity = O(n^2)
 * Space complexity = O(1)
 */
public class IB_3Sum {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(-1, 2, 1, -4));
        System.out.println(new IB_3Sum().threeSumClosest(list, 1)); // 2
    }

    public int threeSumClosest(ArrayList<Integer> A, int sum) {
        if (A == null || A.size() < 3)
            throw new IllegalArgumentException("the list either null or of size less than 3");

        List<Integer> list = new ArrayList<>(A);
        Collections.sort(list);
        int answer = list.get(0) + list.get(1) + list.get(2);
        for (int i = 0; i < list.size() - 1; i++) {
            int cs = list.get(i) + findClosestSum(list, i + 1, list.size() - 1, sum - list.get(i));
            if (Math.abs(cs - sum) < Math.abs(answer - sum))
                answer = cs;
        }
        return answer;
    }

    // assuming that the list is sorted.
    private int findClosestSum(List<Integer> list, int start, int end, int sum) {
        int closest = list.get(start) + list.get(end);
        for (int i = start, j = end; i < j; ) {
            int cs = list.get(i) + list.get(j);
            if (Math.abs(cs - sum) < Math.abs(closest - sum))
                closest = cs;
            if (cs < sum) {
                i++;
            } else if (cs > sum) {
                j--;
            } else if (cs == sum) {
                return cs;
            }
        }
        return closest;
    }

}
