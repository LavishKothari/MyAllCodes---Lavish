package com.codechef.march19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class CHONQ {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> tempList = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .boxed()
                    .collect(Collectors.toList());
            int k = tempList.get(1);
            List<Integer> list = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .boxed()
                    .collect(Collectors.toList());

            System.out.println(findAnswer(list, k));

        }

    }

    private static int findAnswer(List<Integer> list, int k) {
        int n = list.size();
        int min = Integer.MAX_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            long cr = 0;
            int counter = 1;
            for (int j = i; j < n; j++) {
                cr += list.get(j) / counter++;
            }
            if (cr <= k) {
                min = Math.min(min, i + 1);
            }
        }

        return min != Integer.MAX_VALUE ? min : n + 1;
    }
}