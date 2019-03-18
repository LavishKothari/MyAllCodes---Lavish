package com.codechef.codemania2019;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

/*
    1 2 3 -10 -10 -2000
    2100

    1 2 3 -10 -10 -2000 -10 -10 -10 -3000
    4970

    -2500 1 2 3 -10 -10 -2000 -10 -10 -10 -3000
    4970

    dp[#flipped][i] standard solution is after flipping nothing

    dp[0][i] -> max(dp[0][i-1] + arr[i], arr[i])
    dp[1][i] -> max(dp[1][i-1] + arr[i], dp[0][i-1] - arr[i], -arr[i])
    dp[2][i] -> max(dp[2][i-1] + arr[i], dp[1][i-1]-arr[i])


 */
public class COMA19D {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stz;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        List<Long> list = Arrays.stream(br.readLine().split(" "))
                .mapToLong(Long::valueOf)
                .boxed()
                .collect(Collectors.toList());

        if (list.size() < 2) {
            System.out.println(max(list.get(0), -list.get(0)));
            return;
        }

        long[][] dp = new long[3][n];
        dp[0][0] = list.get(0);
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(list.get(i),
                    dp[0][i - 1] + list.get(i));
        }

        dp[1][0] = -list.get(0);
        for (int i = 1; i < n; i++) {
            dp[1][i] = max(dp[1][i - 1] + list.get(i),
                    dp[0][i - 1] - list.get(i),
                    -list.get(i));
        }

        dp[2][0] = Integer.MIN_VALUE;
        dp[2][1] = -list.get(0) - list.get(1); // assuming list is of lenght 2 or greater than 2.
        for (int i = 2; i < n; i++) {
            dp[2][i] = max(dp[2][i - 1] + list.get(i),
                    dp[1][i - 1] - list.get(i));
        }

        long result = list.get(0);
        for (int i = 0; i < n; i++) {
            result = max(result, max(dp[0][i], dp[1][i], dp[2][i]));
        }
        System.out.println(result);
    }

    private static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    private static long max(long... arr) {
        long result = arr[0];
        for (int i = 0; i < arr.length; i++)
            if (result < arr[i])
                result = arr[i];
        return result;
    }
}
