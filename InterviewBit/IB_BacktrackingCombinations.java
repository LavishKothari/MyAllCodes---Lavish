package ib;

import java.util.ArrayList;
import java.util.Collections;

public class IB_BacktrackingCombinations {
    public static void main(String[] args) {
        System.out.println(new IB_BacktrackingCombinations().combine(4, 2));
    }

    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        int x = 1 << n;
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        for (int i = 0; i < x; i++) {
            if (countBits(i) == k) {
                int ci = i;
                int counter = 0;
                ArrayList<Integer> tempList = new ArrayList<>();
                while (ci != 0) {
                    counter++;
                    if ((ci & 1) == 1) {
                        tempList.add(counter);
                    }
                    ci >>= 1;
                }
                result.add(tempList);
            }
        }
        Collections.sort(result, (a, b) -> {
            for (int i = 0; i < a.size() && i < b.size(); i++) {
                int p = a.get(i).compareTo(b.get(i));
                if (p != 0) return p;
            }
            return Integer.compare(a.size(), b.size());
        });
        return result;
    }

    private int countBits(int n) {
        int counter = 0;
        while (n != 0) {
            counter++;
            n = (n & (n - 1));
        }
        return counter;
    }
}
