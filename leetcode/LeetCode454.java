import java.util.*;

public class LeetCode454 {
    public static void main(String[] args) {
        int[] a = new int[]{1, 2};
        int[] b = new int[]{-2, -1};
        int[] c = new int[]{-1, 2};
        int[] d = new int[]{0, 2};

        System.out.println(new LeetCode454().fourSumCount(a, b, c, d));
    }

    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> h1 = getAllPossibleSum(A, B);
        Map<Integer, Integer> h2 = getAllPossibleSum(C, D);
        int answer = 0;
        for (Map.Entry<Integer, Integer> entry : h1.entrySet()) {
            int currentKey = entry.getKey();
            if (h2.containsKey(-currentKey)) {
                answer += (entry.getValue() * h2.get(-currentKey));
            }
        }
        return answer;
    }

    private Map<Integer, Integer> getAllPossibleSum(int[] a, int[] b) {
        Map<Integer, Integer> result = new HashMap<>();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {
                int sum = a[i] + b[j];
                int count = 1;
                if (result.containsKey(sum))
                    count += result.get(sum);
                result.put(sum, count);
            }
        }
        return result;
    }

}
