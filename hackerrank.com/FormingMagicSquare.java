package hackerrank;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class FormingMagicSquare {

    private static final Scanner scanner = new Scanner(System.in);

    private static boolean isMagicSquare(int[][] s) {
        // assuming this is a square matrix
        int n = s.length;
        int magicNumber = 0;
        for (int i = 0; i < n; i++) {
            magicNumber += s[0][i];
        }
        int leftDiagonal = 0, rightDiagonal = 0;
        for (int i = 0; i < n; i++) {
            leftDiagonal += s[i][i];
            rightDiagonal += s[i][n - i - 1];
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += s[i][j];
                colSum += s[j][i];
            }
            if (rowSum != magicNumber) return false;
            if (colSum != magicNumber) return false;
        }
        if (leftDiagonal != magicNumber || rightDiagonal != magicNumber)
            return false;
        return true;
    }

    private static int[][] get2DMat(List<Integer> list) {
        int n = 3, counter = 0;
        int[][] mat = new int[3][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = list.get(counter++);
            }
        }
        return mat;
    }

    private static List<List<Integer>> getAllShuffles(List<Integer> list) {
        List<List<Integer>> result = new ArrayList<>();
        getShufflesHelper(list, 0, result);
        return result;
    }

    private static void getShufflesHelper(List<Integer> list,
                                          int counter, List<List<Integer>> result) {
        if (counter == list.size()) {
            List<Integer> tempList = new ArrayList<>(list);
            result.add(tempList);
        }
        for (int i = counter; i < list.size(); i++) {
            swap(list, counter, i);
            getShufflesHelper(list, counter + 1, result);
            swap(list, counter, i);
        }
    }

    private static void swap(List<Integer> list, int a, int b) {
        int temp = list.get(a);
        list.set(a, list.get(b));
        list.set(b, temp);
    }

    private static int calDist(int[][] a, int[][] b) {
        int n = 3, answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                answer += Math.abs(a[i][j] - b[i][j]);
            }
        }
        return answer;
    }

    // Complete the formingMagicSquare function below.
    static int formingMagicSquare(int[][] s) {
        List<Integer> list = IntStream.range(1, 10)
                .boxed()
                .collect(Collectors.toList());
        List<List<Integer>> shuffles = getAllShuffles(list);

        int minDist = Integer.MAX_VALUE;
        for (List<Integer> cl : shuffles) {
            int[][] c2d = get2DMat(cl);
            if (isMagicSquare(c2d)) {
                int dist = calDist(s, c2d);
                minDist = Math.min(minDist, dist);
            }
        }
        return minDist;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] s = new int[3][3];

        for (int i = 0; i < 3; i++) {
            String[] sRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int sItem = Integer.parseInt(sRowItems[j]);
                s[i][j] = sItem;
            }
        }

        int result = formingMagicSquare(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
