import java.util.*;

public class LeetCode210 {
    public static void main(String[] args) {
        //int []arr = new LeetCode210().findOrder(4, new int[][]{{1,0}, {2,0}, {3,1}, {3,2}});
        int []arr = new LeetCode210().findOrder(4, new int[][]{{1,0}, {0,1}});
        for(int i : arr)
            System.out.println(i);
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Set<Integer>> graph = new ArrayList<>(numCourses);
        for(int i=0;i<numCourses;i++) {
            graph.add(new HashSet<Integer>());
        }

        for(int i=0;i<prerequisites.length;i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            graph.get(u).add(v); // directed edge
        }
        boolean []visited = new boolean[numCourses]; // initially all are false
        int []result = new int[numCourses];
        int counter = 0;
        boolean []finished = new boolean[numCourses]; // initially none is finished
        for(int i=0;i<numCourses;i++) {
            if(!visited[i]) {
                Deque<Integer> visitOrder = new LinkedList<>();
                if(dfs(graph, visited, i, visitOrder, finished)) {
                    return new int[]{};
                }
                for(int cv : visitOrder) {
                    result[counter++] = cv;
                }
            }
        }
        return result;
    }

    // recursive
// return true if there is a cycle, false otherwise
    private boolean dfs(List<Set<Integer>>graph, boolean[] visited, int start, Deque<Integer> visitOrder, boolean[] finished) {
        visited[start] = true;
        boolean cycle = false;
        for(int v : graph.get(start)) {
            if(visited[v] && !finished[v]) {
                return true;
            }
            if(!visited[v]) {
                cycle = cycle || dfs(graph, visited, v, visitOrder, finished);
            }
        }
        visitOrder.addLast(start);
        finished[start] = true;
        return cycle;
    }

}
