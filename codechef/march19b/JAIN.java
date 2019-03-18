package com.codechef.march19b;
/*
1
3
aaooaoaooa
uiieieiieieuuu
aeioooeeiiaiei

1
5
a
e
i
o
u

1
7
aeiou
ae
a
e
i
o
u


1
4
aeiou
aeiou
aei
iou

 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class JAIN {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final int LIMIT = (1 << 5) - 1;
    private static final char[] carray = new char[]{'a', 'e', 'i', 'o', 'u'};

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            List<String> list = new ArrayList<>(n);
            for (int i = 0; i < n; i++)
                list.add(br.readLine());

            System.out.println(findAnswer(list));
        }
    }

    private static long findAnswer(List<String> list) {
        long answer = 0;

        // a map to pre-compute the string to number mapping
        Map<String, Integer> numbersMap = list.stream()
                .collect(Collectors.toMap(Function.identity(), JAIN::getNumber, (a, b) -> a));

        // this map gives you the number of elements/strings in this bucket
        Map<Integer, Long> buckets = IntStream.rangeClosed(1, LIMIT)
                .boxed()
                .collect(Collectors.toMap(Function.identity(), i ->
                        list.stream()
                                .filter(cs -> numbersMap.get(cs) == i)
                                .count()
                ));

        for (int i = 1; i <= LIMIT; i++)
            for (int j = i + 1; j <= LIMIT; j++)
                if ((i | j) == LIMIT)
                    answer += buckets.get(i) * buckets.get(j);

        // for strings of type aeiou or iouae or eioau ...
        long x = buckets.get(LIMIT);
        return answer + (x * (x - 1)) / 2;
    }

    private static int getNumber(String s) {
        int result = 0;
        for (int i = 0; result != LIMIT && i < s.length(); i++)
            result |= getNumber(s.charAt(i));
        return result;
    }

    private static int getNumber(char c) {
        if (c == 'a') return 1;
        if (c == 'e') return 2;
        if (c == 'i') return 4;
        if (c == 'o') return 8;
        if (c == 'u') return 16;
        throw new IllegalArgumentException("the character must be amongst a,e,i,o or u");
    }
}
