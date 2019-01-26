import java.util.*;

public class LeetCode329_1 {

    private static final int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public static void main(String[] args) {
        System.out.println(new LeetCode329_1().longestIncreasingPath(new int[][]{})); // prints 0
        System.out.println(new LeetCode329_1().longestIncreasingPath(new int[][]{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}})); // prints 4
        System.out.println(new LeetCode329_1().longestIncreasingPath(new int[][]{{1, 7, 8, 1}, {1, 6, 9, 1}, {1, 5, 10, 11}, {1, 1, 13, 12}})); // prints 10
        System.out.println(new LeetCode329_1().longestIncreasingPath(new int[][]{{1, 2}})); // prints 2
    }

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0)
            return 0;
        int m = matrix.length;
        int n = matrix[0].length;
        boolean visited[][] = new boolean[m][n]; // all are initially false
        List<Integer> order = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(i, j, visited, m, n, matrix, order);
                }
            }
        }
        Collections.reverse(order); // linear ordering

        int length[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                length[i][j] = 1; // initialize all the length to 1.
        }
        int max = 1;
        for (int currentNode : order) { // picking the nodes in the linearized order.
            int x = currentNode / n, y = currentNode % n;
            for (int[] cd : dir) {
                int a = cd[0] + x;
                int b = cd[1] + y;
                if (a >= 0 && b >= 0 && a < m && b < n &&
                        matrix[a][b] > matrix[x][y] && length[a][b] < length[x][y] + 1) {
                    length[a][b] = length[x][y] + 1; // updating distance of children
                    max = length[a][b] > max ? length[a][b] : max; // updating max if required
                }
            }
        }
        return max;
    }

    private void dfs(int x, int y, boolean visited[][], int m, int n, int[][] matrix, List<Integer> order) {
        for (int[] cd : dir) {
            int a = cd[0] + x;
            int b = cd[1] + y;
            if (a >= 0 && b >= 0 && a < m && b < n && !visited[a][b] && matrix[a][b] > matrix[x][y]) {
                visited[a][b] = true;
                dfs(a, b, visited, m, n, matrix, order);
            }
        }
        order.add(x * n + y);
    }
}

