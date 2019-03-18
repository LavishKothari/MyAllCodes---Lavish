package com.codechef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CLIPLX {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stz;

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            stz = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(stz.nextToken());
            int y = Integer.parseInt(stz.nextToken());

            System.out.println(findAnswer(x, y));
        }
    }

    private static int findAnswer(int x, int y) {
        for (int i = 0; i <= y; i++) {
            int w = i;
            int t = y - w;

            if (2 * w + t >= x) {
                return w;
            }
        }
        throw new IllegalArgumentException("invalid input");
    }
}
