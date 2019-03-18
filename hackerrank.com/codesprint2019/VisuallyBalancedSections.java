package hackerrank.women.codesprint2019;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.toList;


public class VisuallyBalancedSections {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, t).forEach(tItr -> {
            try {
                int n = Integer.parseInt(bufferedReader.readLine().trim());

                List<Integer> colors = IntStream.range(0, n).mapToObj(i -> {
                    try {
                        return bufferedReader.readLine().replaceAll("\\s+$", "");
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                })
                        .map(String::trim)
                        .map(Integer::parseInt)
                        .collect(toList());

                int result = Result.visuallyBalancedSections(colors);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }

    private static class Result {

        /*
         * Complete the 'visuallyBalancedSections' function below.
         *
         * The function is expected to return an INTEGER.
         * The function accepts INTEGER_ARRAY colors as parameter.
         */

        public static int visuallyBalancedSections(List<Integer> colors) {
            int n = colors.size();
            Map<Integer, Integer> map;
            // color, count
            int odd = 0, answer = 0;
            for (int i = 0; i < n; i++) {
                map = new HashMap<>();
                odd = 0;
                for (int j = i; j < n; j++) {
                    int cc = colors.get(j);
                    map.putIfAbsent(cc, 0);
                    int prev = map.get(cc);
                    if (prev % 2 != 0)
                        odd--;
                    else odd++;
                    map.put(cc, prev + 1);
                    if (odd <= 1)
                        answer++;
                }
            }
            return answer;
        }

        public static void main(String[] args) {
            System.out.println(visuallyBalancedSections(Arrays.asList(1, 2, 1, 2)));
        }

    }
}
