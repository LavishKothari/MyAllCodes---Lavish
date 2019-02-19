package ib;

import java.util.*;

public class IB_BacktrackingSubset {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3, 4));
        System.out.println(new IB_BacktrackingSubset().subsets(list));
    }

    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> list) {
        Comparator<ArrayList<Integer>> cmp = (a, b) -> {
            for (int i = 0; i < a.size() && i < b.size(); i++) {
                int x = a.get(i).compareTo(b.get(i));
                if (x != 0) return x;
            }
            return Integer.compare(a.size(), b.size());
        };
        TreeSet<ArrayList<Integer>> result = new TreeSet<>(cmp);
        if (list == null || list.size() == 0) {
            result.add(new ArrayList<>());
            return new ArrayList<>(result);
        }
        int n = list.size();
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            ArrayList<Integer> tempList = new ArrayList<>();
            int ci = i, counter = 0;
            while (ci != 0) {
                if ((ci & 1) == 1)
                    tempList.add(list.get(counter));
                ci >>= 1;
                counter++;
            }
            Collections.sort(tempList);
            result.add(tempList);
        }
        return new ArrayList<>(result);
    }

}
