package com.codechef.bion2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class VWL {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        br.readLine();
        String str = br.readLine();
        if (str.chars()
                .filter(a -> isVovel((char) a))
                .distinct()
                .count() >= 4)
            System.out.println("Yes");
        else System.out.println("No");
    }

    private static boolean isVovel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
