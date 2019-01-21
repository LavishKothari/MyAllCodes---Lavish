import java.util.*;

public class LeetCode200 {
    public static void main(String[] args) {
        char[][] grid = new char[][]{{'1', '1', '0', '0', '0'},
                                     {'1', '1', '0', '0', '0'},
                                     {'0', '0', '1', '0', '0'},
                                     {'0', '0', '0', '1', '1'}};
        System.out.println(new LeetCode200().numIslands(grid));
    }

    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = 0;
        if (m > 0)
            n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int answer = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') { // make sure that you have this condition correct, don't forget this
                    bfs(i, j, grid, visited, m, n);
                    answer++;
                }
            }
        }
        return answer;
    }

    private void bfs(int x, int y, char[][] grid, boolean[][] visited, int m, int n) {
        if (visited[x][y] == true)
            return;
        Queue<Integer> q = new LinkedList<>();
        q.offer(x * n + y);
        while (q.size() != 0) {
            int u = q.poll();
            int a = u / n;
            int b = u % n;

            if (a - 1 >= 0 && !visited[a - 1][b] && grid[a - 1][b] == '1') {
                visited[a - 1][b] = true;
                q.offer((a - 1) * n + b);
            }
            if (a + 1 < m && !visited[a + 1][b] && grid[a + 1][b] == '1') {
                visited[a + 1][b] = true;
                q.offer((a + 1) * n + b);
            }
            if (b - 1 >= 0 && !visited[a][b - 1] && grid[a][b - 1] == '1') {
                visited[a][b - 1] = true;
                q.offer(a * n + b - 1);
            }
            if (b + 1 < n && !visited[a][b + 1] && grid[a][b + 1] == '1') {
                visited[a][b + 1] = true;
                q.offer(a * n + b + 1);
            }
        }
    }

}
