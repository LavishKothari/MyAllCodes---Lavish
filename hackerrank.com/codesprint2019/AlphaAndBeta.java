package hackerrank.women.codesprint2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class AlphaAndBeta {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<Integer> list = Arrays.stream(br.readLine().split(" "))
                .map(i -> Integer.parseInt(i))
                .distinct()
                .collect(Collectors.toList());
        alphaBeta(list);
    }

    private static int alphaBeta(List<Integer> list) {
        list = list.stream().distinct().collect(Collectors.toList());
        if (list.size() == 1)
            return 0;
        int max = list.stream().max(Integer::compareTo).get();
        return list.stream()
                .filter(i -> i != max)
                .max(Integer::compareTo).get();
    }
}
