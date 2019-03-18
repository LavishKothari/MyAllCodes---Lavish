package com.codechef.bion2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;
import java.util.List;
import java.util.TreeSet;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class MATHP {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static TreeSet<Long> set = new TreeSet<>();

    static {
        int N = 320000;
        long N_MAX = 100000000000l;
        BitSet isPrime;
        List<Integer> primes;

        isPrime = new BitSet();
        isPrime.set(0, N, true);
        isPrime.flip(0);
        isPrime.flip(1);

        for (int i = 2; i * i <= N; i++) {
            for (int j = i * i; isPrime.get(i) && j <= N; j += i) {
                isPrime.set(j, false);
            }
        }
        primes = IntStream.rangeClosed(2, N)
                .boxed()
                .filter(i -> isPrime.get(i))
                .collect(Collectors.toList());
        for (int i = 0; i < primes.size(); i++) {
            for (int j = 0; j < primes.size(); j++) {
                long p = power(primes.get(i), primes.get(j));
                if (p > N_MAX)
                    break;
                set.add(p);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            sb.append(findAnswer(Long.parseLong(br.readLine())));
            sb.append('\n');
        }
        System.out.println(sb.toString());
    }

    private static long findAnswer(long n) {
        if (n < 4)
            return -1;
        return set.floor(n);
    }

    private static long power(long a, long b) {
        if (b == 1) return a;
        if (b == 0) return 1;

        long temp = power(a, b / 2);
        if (b % 2 == 0) return temp * temp;
        return temp * temp * a;
    }
}
