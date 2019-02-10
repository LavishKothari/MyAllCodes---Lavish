import java.util.*;

/**
 * https://www.interviewbit.com/problems/4-sum/
 *
 * Time complexity O(n^2)
 * Space complexity O(n^2)
 */
public class IB_4Sum {

    public static void main(String[] args) {
        ArrayList<Integer> list1 = new ArrayList<>(Arrays.asList(1, 0, -1, 0, -2, 2));
        ArrayList<Integer> list2 = new ArrayList<>(Arrays.asList(4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8));

        // [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
        System.out.println(new IB_4Sum().fourSum(list1, 0));

        // [[-8, -7, 3, 9], [-8, -5, 1, 9], [-8, -5, 3, 7], [-8, -4, 2, 7], [-8, -3, -1, 9], [-8, -3, 1, 7], [-8, -3, 4, 4], [-8, -2, 3, 4], [-8, -1, 2, 4], [-8, -1, 3, 3], [-8, 1, 2, 2], [-7, -7, 2, 9], [-7, -7, 4, 7], [-7, -5, 2, 7], [-7, -4, -1, 9], [-7, -4, 1, 7], [-7, -4, 4, 4], [-7, -3, -2, 9], [-7, -3, 3, 4], [-7, -2, -1, 7], [-7, -2, 2, 4], [-7, -2, 3, 3], [-7, -1, 1, 4], [-7, -1, 2, 3], [-5, -5, -2, 9], [-5, -5, 3, 4], [-5, -4, -3, 9], [-5, -4, -1, 7], [-5, -4, 2, 4], [-5, -4, 3, 3], [-5, -3, -2, 7], [-5, -3, 1, 4], [-5, -3, 2, 3], [-5, -2, 1, 3], [-5, -2, 2, 2], [-5, -1, 1, 2], [-4, -4, -4, 9], [-4, -4, -2, 7], [-4, -4, 1, 4], [-4, -4, 2, 3], [-4, -3, -3, 7], [-4, -3, 1, 3], [-4, -3, 2, 2], [-4, -2, -1, 4], [-4, -2, 1, 2], [-3, -3, -1, 4], [-3, -3, 1, 2], [-3, -2, -1, 3]]
        System.out.println(new IB_4Sum().fourSum(list2, -3));

    }

    public ArrayList<ArrayList<Integer>> fourSum(ArrayList<Integer> list, int s) {

        Map<Integer, List<Pair>> sum = new HashMap<>();
        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                int current = list.get(i) + list.get(j);
                sum.putIfAbsent(current, new ArrayList<>());
                // adding the index and not the elements
                sum.get(current).add(new Pair(i, j));
            }
        }

        Set<ArrayList<Integer>> answer = new HashSet<>();
        for (Map.Entry<Integer, List<Pair>> entry : sum.entrySet()) {
            int a = entry.getKey();
            int b = s - a;
            if (a == b) {
                if (sum.get(a).size() > 1) {
                    for (int i = 0; i < sum.get(a).size(); i++) {
                        for (int j = i + 1; j < sum.get(a).size(); j++) {
                            Pair ap = sum.get(a).get(i);
                            Pair bp = sum.get(a).get(j);
                            addPair(list, answer, ap, bp);
                        }
                    }
                }
            } else {
                if (sum.containsKey(b)) {
                    for (Pair ap : sum.get(a)) {
                        for (Pair bp : sum.get(b)) {
                            addPair(list, answer, ap, bp);
                        }
                    }
                }
            }
        }
        ArrayList<ArrayList<Integer>> result = new ArrayList<>(answer.size());
        result.addAll(answer);
        Collections.sort(result, (l1, l2) -> {
            for (int i = 0; i < l2.size() && i < l1.size(); i++) {
                if (l1.get(i) != l2.get(i)) {
                    return Integer.compare(l1.get(i), l2.get(i));
                }
            }
            return Integer.compare(l1.size(), l2.size());
        });
        return result;
    }

    private void addPair(List<Integer> list, Set<ArrayList<Integer>> answer, Pair ap, Pair bp) {
        Set<Integer> tempSet = new HashSet<>();
        tempSet.addAll(Arrays.asList(ap.x, ap.y, bp.x, bp.y));
        if (tempSet.size() < 4)
            return;
        ArrayList<Integer> tempList = new ArrayList<>(4);
        tempList.add(list.get(ap.x));
        tempList.add(list.get(ap.y));
        tempList.add(list.get(bp.x));
        tempList.add(list.get(bp.y));
        Collections.sort(tempList); // essential to remove duplicates
        answer.add(tempList);
    }

    private static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}
