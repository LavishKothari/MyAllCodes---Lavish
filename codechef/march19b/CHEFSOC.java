package com.codechef.march19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class CHEFSOC {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            Integer.parseInt(br.readLine());
            List<Integer> list = Arrays.stream(br.readLine().split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
            List<List<Integer>> result = new ArrayList<>();
            findAnswer(list, 0, new ArrayList<>(), result);
            System.out.println(result.size());
        }
    }

    private static void findAnswer(List<Integer> list,
                                   int ci,
                                   List<Integer> cl,
                                   List<List<Integer>> result) {

        if (cl.contains(ci) || ci == list.size() || !isValid(ci, list.size()))
            return;

        List<Integer> tempList = new ArrayList<>(cl);
        tempList.add(ci);
        result.add(tempList);

        for (int j = 1; j <= list.get(ci); j++) {
            if (isValid(ci + j, list.size()))
                findAnswer(list, ci + j, tempList, result);
            if (isValid(ci - j, list.size()))
                findAnswer(list, ci - j, tempList, result);
        }
    }

    private static boolean isValid(int index, int size) {
        return index >= 0 && index < size;
    }

    private static void swap(List<Integer> list, int a, int b) {
        int n = list.size();
        if (a < 0 || a >= n || b < 0 || b >= n)
            throw new IllegalArgumentException("indices should be valid");
        int temp = list.get(a);
        list.set(a, list.get(b));
        list.set(b, temp);
    }
}