import java.util.*;

/**
 * https://www.interviewbit.com/problems/2-sum/
 *
 * Time complexity = O(n)
 * space complexity = O(n)
 */
public class IB_2Sum {
    public static void main(String[] args) {
        System.out.println(new IB_2Sum().twoSum(Arrays.asList(2, 7, 11, 15), 9));
        System.out.println(new IB_2Sum().twoSum(Arrays.asList(-10, -10, -10), -5));
    }

    public ArrayList<Integer> twoSum(final List<Integer> list, int sum) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < list.size(); i++) {
            map.putIfAbsent(list.get(i), new ArrayList<>());
            map.get(list.get(i)).add(i);
        }
        Pair answer = null;
        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
            int a = entry.getKey();
            int b = sum - a;
            if (a == b) {
                if (entry.getValue().size() > 1) {
                    Pair cp = new Pair(entry.getValue().get(0), entry.getValue().get(1));
                    if (answer == null || answer.compareTo(cp) == 1) {
                        answer = cp;
                    }
                }
            } else {
                if (map.containsKey(b)) {
                    Pair cp = new Pair(map.get(a).get(0), map.get(b).get(0));
                    if (answer == null || answer.compareTo(cp) == 1) {
                        answer = cp;
                    }
                }
            }
        }
        ArrayList<Integer> finalResult = new ArrayList<>(2);
        if (answer == null) // means no such two numbers exist
            return finalResult;
        finalResult.add(answer.x + 1);
        finalResult.add(answer.y + 1);
        return finalResult;
    }

    private static class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
            if (this.x > this.y) swap();
        }

        private void swap() {
            int temp = x;
            x = y;
            y = temp;
        }

        @Override
        public int compareTo(Pair p) {
            if (y < p.y) return -1;
            else if (y > p.y) return 1;
            else if (x < p.x) return -1;
            else if (x > p.x) return 1;
            else return 0;
        }
    }

}
