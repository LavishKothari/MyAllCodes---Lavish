package com.codechef.march19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class SUBPRNJL {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            List<Integer> tempList = Arrays.stream(br.readLine().split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
            int k = tempList.get(1);
            List<Integer> list = Arrays.stream(br.readLine().split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
            System.out.println(findAnswer(list, k));
        }
    }

    private static int[][] req(List<Integer> list, int k) {
        int n = list.size();
        int[][] result = new int[n][n];
        for (int i = 0; i < n; i++) {
            PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
            PriorityQueue<Integer> minHeap = new PriorityQueue<>();
            for (int j = i; j < n; j++) {
                int position = position(i, j + 1, k);
                maxHeap.offer(list.get(j));
                while (maxHeap.size() > position)
                    minHeap.offer(maxHeap.poll());
                while (maxHeap.size() < position)
                    maxHeap.offer(minHeap.poll());
                result[i][j] = maxHeap.peek();
            }
        }
        return result;
    }

    private static int position(int l, int r, int k) {
        int len = r - l;
        int m = getM(k, len);
        return len - (len - ((k - 1) % len) - 1) / m;
    }

    private static int getM(int k, int len) {
        if (k % len == 0) return k / len;
        else return k / len + 1;
    }

    private static int findAnswer(List<Integer> list, int k) {
        int p = 2001;
        int q = list.size();
        int[][] dp = new int[p][q];
        for (int i = 1; i < p; i++)
            dp[i][0] = list.get(0) == i ? 1 : 0;
        for (int i = 1; i < p; i++)
            for (int j = 1; j < q; j++)
                dp[i][j] = dp[i][j - 1] + (list.get(j) == i ? 1 : 0);

        int[][] req = req(list, k);
        int n = list.size(), answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int F = getOccurrence(req[i][j], dp, i, j + 1);
                if (getOccurrence(F, dp, i, j + 1) >= 1)
                    answer++;
            }
        }
        return answer;
    }

    private static int getOccurrence(int x, int[][] dp, int l, int r) {
        if (l >= r) return 0;
        return l == 0 ? dp[x][r - 1] : dp[x][r - 1] - dp[x][l - 1];
    }
}
