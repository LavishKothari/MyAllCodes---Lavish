package codechef.april19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class SUBREM {

    public static void main(String[] args) throws Exception {
        int t = InputUtilities.readInt();
        while (t-- > 0) {
            int[] nx = InputUtilities.readArrayOfIntegers();
            int n = nx[0];
            int x = nx[1];
            long[] nodeValues = InputUtilities.readArrayOfLong();
            Tree tree = new Tree(n, nodeValues);
            for (int i = 0; i < n - 1; i++) {
                int[] ab = InputUtilities.readArrayOfIntegers();
                tree.addEdge(ab[0] - 1, ab[1] - 1);
            }
            System.out.println(tree.answer(x));
        }
    }

    private static class TreeNode {
        private final int number;
        private final long value;
        private final Set<Integer> adj;
        private long profit = 0;

        public TreeNode(int n, long value) {
            this.number = n;
            this.value = value;
            this.adj = new HashSet<>();
        }
    }

    private static class Tree {
        private final List<TreeNode> nodes;

        public Tree(int n, long[] nodeValues) {
            nodes = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                nodes.add(new TreeNode(i, nodeValues[i]));
            }
        }

        public void addEdge(int a, int b) {
            nodes.get(a).adj.add(b);
            nodes.get(b).adj.add(a);
        }

        // returns the profit
        public long dfsSuper(TreeNode start, BitSet visited, long cost) {
            visited.set(start.number, true);
            long profit = start.value;
            for (int i : start.adj) {
                if (!visited.get(i)) {
                    profit += dfsSuper(nodes.get(i), visited, cost);
                }
            }
            long retVal = -cost > profit ? -cost : profit;
            start.profit = retVal;
            return retVal;
        }

        public long answer(long cost) {
            return dfsSuper(nodes.get(0), new BitSet(), cost);
        }

    }

    private static class InputUtilities {
        private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        private InputUtilities() {
        }

        public static int[] readArrayOfIntegers() throws IOException {
            String[] strArray = br.readLine().split(" ");
            int[] retVal = new int[strArray.length];
            for (int i = 0; i < retVal.length; i++)
                retVal[i] = Integer.parseInt(strArray[i]);
            return retVal;
        }

        public static long[] readArrayOfLong() throws IOException {
            String[] strArray = br.readLine().split(" ");
            long[] retVal = new long[strArray.length];
            for (int i = 0; i < retVal.length; i++)
                retVal[i] = Long.parseLong(strArray[i]);
            return retVal;
        }

        public static int readInt() throws IOException {
            return Integer.parseInt(br.readLine());
        }

    }

}
