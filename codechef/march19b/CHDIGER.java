package com.codechef.march19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class CHDIGER {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Long> list = Arrays.stream(br.readLine().split(" "))
                    .map(String::trim)
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            long n = list.get(0);
            int d = (int) ((long) list.get(1));

            System.out.println(findAnswer(n, d));
        }
    }

    private static long findAnswer(long n, int d) {
        long min = n;
        int initialSize = size(n);
        for (int j = 0; j < initialSize; j++) {
            long tempMin = n;
            for (int i = 0; i < initialSize; i++) {
                long tempN = remove(n, i);
                tempN = append(tempN, d);
                if (tempN < tempMin)
                    tempMin = tempN;
            }
            n = tempMin;
            if (n < min)
                min = n;
        }
        return min;
    }

    private static long remove1(long n, int i) {
        int size = size(n);
        String prefix = Long.valueOf(n).toString().substring(0, size - i - 1);
        String suffix = size - i < size ?
                Long.valueOf(n).toString().substring(size - i) : "";
        String temp = prefix + suffix;
        if (temp.length() == 0)
            return 0;
        return Long.valueOf(temp);
    }

    private static long remove(long n, int d) {
        long pow = 1, result = 0;
        int size = size(n);
        for (int i = 0; i < size; i++) {
            if (i != d) {
                result = result + (n % 10) * pow;
                pow *= 10;
            }
            n /= 10;
        }
        return result;
    }

    private static long append(long n, int d) {
        return n * 10 + d;
    }

    private static int size(long n) {
        int size = 0;
        while (n != 0) {
            size++;
            n /= 10;
        }
        return size;
    }
}
