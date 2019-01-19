import java.util.*;

public class LeetCode79 {

    public static void main(String[] args) {
        char[][] arr = new char[3][4];
        arr[0] = new char[]{'A', 'B', 'C', 'E'};
        arr[1] = new char[]{'S', 'F', 'C', 'S'};
        arr[2] = new char[]{'A', 'D', 'E', 'E'};

        System.out.println(new LeetCode79().exist(arr, "ABCCED"));
        System.out.println(new LeetCode79().exist(arr, "SEE"));
        System.out.println(new LeetCode79().exist(arr, "ABCB"));

    }

    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0)) {
                    boolean b = find(board, new HashSet<Integer>(), i * n + j, word, 0);
                    if (b)
                        return b;
                }
            }
        }
        return false;
    }

    private boolean find(char[][] board, Set<Integer> covered, int start, String word, int counter) {
        int m = board.length;
        int n = board[0].length;
        covered.add(start);
        counter++;
        if(counter == word.length())
            return true;
        int x = start / n;
        int y = start % n;
        boolean b = false;
        if (x - 1 >= 0 && board[x - 1][y] == word.charAt(counter) && notCovered(covered, x - 1, y, n)) {
            b = (b || find(board, covered, (x - 1) * n + y, word, counter));
        }
        if (y - 1 >= 0 && board[x][y - 1] == word.charAt(counter) && notCovered(covered, x, y - 1, n)) {
            b = (b || find(board, covered, x * n + y - 1, word, counter));
        }
        if (x + 1 < m && board[x + 1][y] == word.charAt(counter) && notCovered(covered, x + 1, y, n)) {
            b = (b || find(board, covered, (x + 1) * n + y, word, counter));
        }
        if (y + 1 < n && board[x][y + 1] == word.charAt(counter) && notCovered(covered, x, y + 1, n)) {
            b = (b || find(board, covered, x * n + y + 1, word, counter));
        }
        covered.remove(start);
        return b;
    }

    private boolean notCovered(Set<Integer> covered, int a, int b, int n) {
        return !covered.contains(a * n + b);
    }

}
