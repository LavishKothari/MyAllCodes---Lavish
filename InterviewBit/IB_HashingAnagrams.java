package ib;

import java.util.*;

public class IB_HashingAnagrams {
    public static void main(String[] args) {
        System.out.println(new IB_HashingAnagrams().anagrams(Arrays.asList("cat", "dog", "god", "tca")));
    }

    public ArrayList<ArrayList<Integer>> anagrams(final List<String> list) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        boolean[] visited = new boolean[list.size()]; // all initially false;

        for (int i = 0; i < list.size(); i++) {
            ArrayList<Integer> tempList = new ArrayList<>();
            tempList.add(i + 1);
            if (visited[i]) continue;
            visited[i] = true;
            for (int j = i + 1; j < list.size(); j++) {
                if (visited[j]) continue;
                if (isAnagram(list.get(i), list.get(j))) {
                    visited[j] = true;
                    tempList.add(j + 1);
                }
            }
            result.add(tempList);
        }
        return result;
    }

    private boolean isAnagram(String a, String b) {
        int[] ca = new int[26];
        int[] cb = new int[26];

        for (int i = 0; i < a.length(); i++) {
            int cc = a.charAt(i);
            ca[cc - 'a']++;
        }
        for (int i = 0; i < b.length(); i++) {
            int cc = b.charAt(i);
            cb[cc - 'a']++;
        }

        for (int i = 0; i < 26; i++)
            if (ca[i] != cb[i]) return false;
        return true;

    }
}
