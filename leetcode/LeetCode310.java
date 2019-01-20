import java.util.*;

public class LeetCode310 {

    public static void main(String[] args) {
        int[][] arr = new int[][]{{0, 1}, {1, 2}, {2, 4}, {4, 6}, {1, 3}, {3, 5}};
        System.out.println(new LeetCode310().findMinHeightTrees(7, arr));
    }

    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (edges.length == 0 || n == 1) {
            return Arrays.asList(new Integer[]{0});
        }

        List<Set<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++)
            graph.add(new HashSet<Integer>());
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        Holder<Integer> h1 = new Holder<>();
        List<Integer> order1 = BFS(graph, 0, h1);
        List<Integer> order2 = BFS(graph, order1.get(order1.size() - 1), h1);
        int diameter = order2.size();
        if ((diameter & 1) == 1) {
            return Arrays.asList(new Integer[]{order2.get(diameter / 2)});
        }
        int shortestHeight = diameter / 2;
        int u = order2.get(diameter / 2);
        List<Integer> result = new ArrayList<>();
        result.add(u);
        Holder<Integer> h = new Holder<Integer>();
        for (Integer v : graph.get(u)) {
            BFS(graph, v, h);
            if (h.get() - 1 == shortestHeight) {
                result.add(v);
            }
        }
        return result;
    }

    /**
     * This method returns the nodes in the longest path starting from “start”
     */
    private List<Integer> BFS(List<Set<Integer>> graph, int start, Holder<Integer> holder) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        Map<Integer, Integer> parent = new HashMap<>();
        Map<Integer, Integer> dist = new HashMap<>();
        parent.put(start, -1); // no one is parent of 0
        dist.put(start, 0);
        int nodesInCurrentLevel = 1;
        int nodesInNextLevel = 0, levelNumber = 1;
        Set<Integer> visited = new HashSet<>();
        int maxDistance = 0;
        while (q.size() != 0) {
            int u = q.poll();
            visited.add(u);
            nodesInCurrentLevel--;
            for (Integer v : graph.get(u)) {
                if (!visited.contains(v)) {
                    parent.put(v, u);
                    q.add(v);
                    dist.put(v, levelNumber);
                    nodesInNextLevel++;
                }
            }
            if (nodesInCurrentLevel == 0) {
                nodesInCurrentLevel = nodesInNextLevel;
                nodesInNextLevel = 0;
                levelNumber++;
                if (levelNumber > maxDistance) {
                    maxDistance = levelNumber;
                }

            }
        }

        List<Integer> visitOrder = new LinkedList<>();
        int cn = getFarthestNode(dist);
        while (cn != -1) {
            visitOrder.add(cn);
            cn = parent.get(cn);
        }
        Collections.reverse(visitOrder);
        holder.set(visitOrder.size());
        return visitOrder;
    }

    private int getFarthestNode(Map<Integer, Integer> dist) {
        int maxDist = 0;
        int maxNode = -1;

        for (Map.Entry<Integer, Integer> entry : dist.entrySet()) {
            int value = entry.getValue();
            int key = entry.getKey();
            if (value > maxDist) {
                maxDist = value;
                maxNode = key;
            }
        }
        return maxNode;
    }

}

/**
 * A simple class in java to just hold the reference, so that I can change
 * the value of the contained object when I pass it to some method.
 */
class Holder<T> {
    T value;

    public Holder() {
    }

    public Holder(T value) {
        this.value = value;
    }

    public void set(T value) {
        this.value = value;
    }

    public T get() {
        return value;
    }

    @Override
    public String toString() {
        return value.toString();
    }
}



