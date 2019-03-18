package hackerrank.women.codesprint2019;

import java.io.*;
import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.toList;

public class NameTheProduct {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> names = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
                .collect(toList());

        String result = Result.productName(names);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }

    private static class Result {

        /*
         * Complete the 'productName' function below.
         *
         * The function is expected to return a STRING.
         * The function accepts STRING_ARRAY names as parameter.
         */

        public static String productName(List<String> names) {
            // Write your code here
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < 5; i++) {
                final int ci = i;
                int[] count = new int[26];
                names.stream()
                        .forEach(e -> count[e.charAt(ci) - 'a']++);
                int min = Arrays.stream(count).min().getAsInt();
                int cc = 0;

                for (int j = 25; j >= 0; j--)
                    if (count[j] == min) {
                        cc = j;
                        break;
                    }
                result.append((char) (cc + 'a'));
            }
            return result.toString();
        }

    }
}
