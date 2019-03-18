package hackerrank.women.codesprint2019;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'strangelyCompatible' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING_ARRAY students as parameter.
     */
    public static void main(String[] args) {
        System.out.println(strangelyCompatible(Arrays.asList("abc", "abd", "bbd")));
        System.out.println(strangelyCompatible(Arrays.asList("a", "a", "d", "a", "c", "b")));
        System.out.println(strangelyCompatible(Arrays.asList("abcde","edcba")));


    }

    public static int strangelyCompatible(List<String> students) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < students.size(); i++) {
            String cs = students.get(i);
            map.putIfAbsent(cs, 0);
            int cv = map.get(cs);
            map.put(cs, cv + 1);
        }
        int answer = 0;
        for (int i = 0; i < students.size(); i++) {
            answer += findFor(students.get(i), map);
        }
        return answer / 2;
    }

    private static int findFor(String str, Map<String, Integer> map) {
        int answer = 0;
        char[] carray = str.toCharArray();
        for (int i = 0; i < str.length(); i++) {
            char cc = str.charAt(i);
            for (int j = 0; j < 26; j++) {
                char rc = (char) (j + 'a');
                if (rc == cc)
                    continue;
                carray[i] = rc;

                String cstr = new String(carray);
                if (map.containsKey(cstr))
                    answer += map.get(cstr);
            }
            carray[i] = cc;
        }
        return answer;
    }
}

public class StrangelyCompatible {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        int m = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> students = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
                .collect(toList());

        int result = Result.strangelyCompatible(students);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
