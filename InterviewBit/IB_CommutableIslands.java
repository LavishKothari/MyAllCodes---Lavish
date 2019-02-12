import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class IB_CommutableIslands {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        list.add(new ArrayList<>(Arrays.asList(1, 2, 15)));
        list.add(new ArrayList<>(Arrays.asList(3, 2, 14)));
        list.add(new ArrayList<>(Arrays.asList(4, 3, 7)));
        list.add(new ArrayList<>(Arrays.asList(2, 5, 10)));
        list.add(new ArrayList<>(Arrays.asList(5, 4, 6)));
        list.add(new ArrayList<>(Arrays.asList(5, 1, 7)));

        System.out.println(new IB_CommutableIslands().solve(5, list));
    }

    public int solve(int A, ArrayList<ArrayList<Integer>> list) {
        List<Edge> edges = new ArrayList<>(list.size());
        for (int i = 0; i < list.size(); i++) {
            assert list.get(i).size() == 3;
            edges.add(new Edge(list.get(i).get(0) - 1,
                    list.get(i).get(1) - 1,
                    list.get(i).get(2)));
        }
        Collections.sort(edges, (x, y) -> Integer.compare(x.w, y.w));

        int[] parent = new int[A];
        int[] size = new int[A];
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        int answer = 0;
        for (int i = 0; i < edges.size(); i++) {
            Edge ce = edges.get(i);
            if (find(parent, ce.a) == find(parent, ce.b)) {
                continue;
            }
            answer += ce.w;
            merge(parent, size, ce.a, ce.b);
        }
        return answer;
    }

    // gives the representative element of 'a'
    private int find(int[] parent, int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent, parent[a]); // path compression
    }

    private void merge(int[] parent, int[] size, int a, int b) {
        int ra = find(parent, a);
        int rb = find(parent, b);
        if (ra != rb) {
            if (size[ra] > size[rb]) {
                parent[rb] = ra;
                size[ra] += size[rb];
            } else {
                parent[ra] = rb;
                size[rb] += size[ra];
            }
        }
    }

    private static class Edge {
        int a, b, w;

        public Edge(int a, int b, int w) {
            this.a = a;
            this.b = b;
            this.w = w;
        }
    }

}
