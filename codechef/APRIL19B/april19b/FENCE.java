package codechef.april19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

class FENCE {
    public static void main(String[] args) throws Exception {
        int t = InputUtilities.readInt();
        while (t-- > 0) {
            List<Integer> nmk = InputUtilities.readListOfInteger();
            int n = nmk.get(0);
            int m = nmk.get(1);
            int k = nmk.get(2);

            Set<Cell> cells = new HashSet<>(k);
            for (int i = 0; i < k; i++) cells.add(Cell.getCell());

            System.out.println(findAnswer(n, m, cells));
        }
    }

    private static long findAnswer(int n, int m, Set<Cell> set) {
        Set<Cell> visited = new HashSet<>();
        MutableLong ml = new MutableLong(0);
        for (Cell cell : set) {
            if (!visited.contains(cell)) {
                visited.add(cell);
                dfs(n, m, cell, set, visited, ml);
            }
        }
        return ml.x;
    }

    private static void dfs(int n, int m, Cell cell,
                            Set<Cell> set, Set<Cell> visited, MutableLong ml) {

        int x = cell.x;
        int y = cell.y;
        for (int i = 0; i < Cell.adj.length; i++) {
            int a = x + Cell.adj[i][0];
            int b = y + Cell.adj[i][1];
            if (isValid(a, b, n, m)) {
                // call set visited true
                Cell newCell = new Cell(a, b);
                if (set.contains(newCell)) {
                    if (!visited.contains(newCell)) {
                        visited.add(newCell);
                        dfs(n, m, newCell, set, visited, ml);
                    }
                } else ml.x++;
            } else ml.x++;
        }
    }

    private static boolean isValid(int a, int b, int n, int m) {
        return a > 0 && a <= n && b > 0 && b <= m;
    }

    private static class MutableLong {
        private long x;

        MutableLong(long x) {
            this.x = x;
        }
    }

    private static class Cell {
        public static final int[][] adj = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        private final int x, y;

        Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public static Cell getCell() throws Exception {
            List<Integer> list = InputUtilities.readListOfInteger();
            return new Cell(list.get(0), list.get(1));
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public boolean equals(Object cell) {
            if (cell == null) return false;
            if (cell instanceof Cell) {
                Cell actualCell = (Cell) cell;
                return actualCell.x == this.x && actualCell.y == this.y;
            } else return false;
        }

    }

    private static class InputUtilities {
        private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        private InputUtilities() {
        }

        public static List<Integer> readListOfInteger() throws IOException {
            return Arrays.stream(br.readLine().split(" "))
                    .map(i -> Integer.parseInt(i))
                    .collect(Collectors.toList());
        }

        public static int readInt() throws IOException {
            return Integer.parseInt(br.readLine());
        }

    }
}
