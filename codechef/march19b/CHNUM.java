package com.codechef.march19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class CHNUM {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stz;

    public static void main(String[] args) throws IOException {

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            List<Integer> list = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .boxed()
                    .collect(Collectors.toList());

            long pos = list.stream()
                    .filter(i -> i >= 0)
                    .count();

            long neg = list.stream()
                    .filter(i -> i <= 0)
                    .count();

            long x = Math.max(pos, neg);
            long y = Math.min(pos, neg);
            if (y == 0) y = x;
            System.out.println(x + " " + y);
        }

    }
}
