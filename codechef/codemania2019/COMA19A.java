package com.codechef.codemania2019;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class COMA19A {
    private static final BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stz;

    public static void main(String[] args) throws Exception {
        stz = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stz.nextToken());
        int q = Integer.parseInt(stz.nextToken());

        List<Integer> list = new ArrayList<>(q);
        for(int i=0;i<q;i++)
            list.add(Integer.parseInt(br.readLine()));

        System.out.println(findAnswer(list, n, q));

    }
    private static int findAnswer(List<Integer> list, int n, int q) {

        Collections.sort(list);
        int sum = 0;
        for(int i=0;i<q;i++) {
            sum+=list.get(i);
            if(sum > n)
                return i;
        }
        return q;
    }
}
