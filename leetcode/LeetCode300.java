import java.util.*;

public class LeetCode300 {
    public static void main(String[] args) {
        System.out.println(new LeetCode300().lengthOfLIS(new int[]{10, 9, 2, 5, 3, 7, 101, 18}));

    }

    public int lengthOfLIS(int[] arr) {
        // this list always be sorted
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            int res = Collections.binarySearch(list, arr[i]);
            if (res < 0) {
                res++;
                res = -res;
                if (res == list.size())
                    list.add(arr[i]);
                else
                    list.set(res, arr[i]);
            }
        }

        return list.size();
    }
}
