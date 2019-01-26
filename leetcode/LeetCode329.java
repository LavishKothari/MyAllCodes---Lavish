/*
    Complicated BFS
    no point in applying BFS again on any node
*/

import java.util.*;

class CoOrdinate {
    private final int x, y;

    CoOrdinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || !(o instanceof CoOrdinate))
            return false;
        CoOrdinate obj = (CoOrdinate) o;
        return obj.x == this.x && obj.y == this.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public String toString() {
        return "[" + x + " " + y + "]";
    }
}

public class LeetCode329 {

    public static void main(String[] args) {
        System.out.println(new LeetCode329().longestIncreasingPath(new int[][]{}));
        System.out.println(new LeetCode329().longestIncreasingPath(new int[][]{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}));
        System.out.println(new LeetCode329().longestIncreasingPath(new int[][]{{1, 7, 8, 1}, {1, 6, 9, 1}, {1, 5, 10, 11}, {1, 1, 13, 12}}));

    }

    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        int n = 0;
        if (m != 0)
            n = matrix[0].length;
        Map<CoOrdinate, Integer> pathLengthMap = new HashMap<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                CoOrdinate current = new CoOrdinate(i, j);
                if (!pathLengthMap.containsKey(current)) {
                    pathLengthMap.putAll(bfs(current, matrix));
                }
            }
        }
        int max = 0;
        for (Map.Entry<CoOrdinate, Integer> entry : pathLengthMap.entrySet()) {
            if (entry.getValue() > max)
                max = entry.getValue();
        }
        return max;
    }

    private Map<CoOrdinate, Integer> bfs(CoOrdinate start, int[][] matrix) {
        int m = matrix.length;
        int n = 0;
        if (m != 0)
            n = matrix[0].length;
        boolean[][] visited = new boolean[m][n]; // all elements are false
        visited[start.getX()][start.getY()] = true;
        Queue<CoOrdinate> q = new LinkedList<>();
        q.offer(start);
        Map<CoOrdinate, CoOrdinate> parent = new HashMap<>();
        parent.put(start, null);
        Map<CoOrdinate, Integer> distance = new HashMap<>();
        distance.put(start, 0);

        while (q.size() != 0) {
            CoOrdinate current = q.poll();
            int ux = current.getX();
            int uy = current.getY();
            bfsHelper(ux - 1, uy, ux, uy, matrix, visited, q, parent, distance);
            bfsHelper(ux, uy - 1, ux, uy, matrix, visited, q, parent, distance);
            bfsHelper(ux + 1, uy, ux, uy, matrix, visited, q, parent, distance);
            bfsHelper(ux, uy + 1, ux, uy, matrix, visited, q, parent, distance);
        }

        int maxDist = 0;
        CoOrdinate farthest = start;
        for (Map.Entry<CoOrdinate, Integer> entry : distance.entrySet()) {
            if (maxDist < entry.getValue()) {
                maxDist = entry.getValue();
                farthest = entry.getKey();
            }
        }

        Map<CoOrdinate, Integer> pathLengthMap = new HashMap<>();
        CoOrdinate currentNode = farthest;
        int counter = 1;
        while (currentNode != null) {
            pathLengthMap.put(currentNode, counter++);
            currentNode = parent.get(currentNode);
        }
        return pathLengthMap;
    }

    private void bfsHelper(int vx, int vy, int ux, int uy, int[][] matrix, boolean[][] visited, Queue<CoOrdinate> q, Map<CoOrdinate, CoOrdinate> parent, Map<CoOrdinate, Integer> distance) {
        int m = matrix.length;
        int n = 0;
        if (m != 0) {
            n = matrix[0].length;
        }
        if (!isValidIndex(vx, vy, m, n)) {
            return;
        }

        CoOrdinate v = new CoOrdinate(vx, vy);
        CoOrdinate current = new CoOrdinate(ux, uy);

        boolean b = visited[vx][vy] && distance.get(v) < distance.get(current) + 1;

        if (matrix[vx][vy] > matrix[ux][uy] && (b || !visited[vx][vy])) {
            q.offer(v);
            visited[vx][vy] = true;
            parent.put(v, current);
            distance.put(v, distance.get(current) + 1);
        }
    }

    private boolean isValidIndex(int a, int b, int m, int n) {
        return a >= 0 && b >= 0 && a < m && b < n;
    }
}
