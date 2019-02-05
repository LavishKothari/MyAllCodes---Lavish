import java.util.*;

public class LeetCode127 {
    public static void main(String[] args) {
        System.out.println(new LeetCode127().ladderLength("hit", "cog",
                Arrays.asList(new String[]{"hot", "dot", "dog", "lot", "log", "cog"})));
        System.out.println(new LeetCode127().ladderLength("hit", "cog",
                Arrays.asList(new String[]{"hot", "dot", "dog", "lot", "log"})));
        System.out.println(new LeetCode127().ladderLength("a", "c",
                Arrays.asList(new String[]{"a", "b", "c"})));


    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, Set<String>> graph = buildGraph(wordList);
        return bfs(graph, beginWord, endWord);
    }

    private int bfs(Map<String, Set<String>> graph, String a, String b) {
        Deque<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        Map<String, Integer> dist = new HashMap<>();
        for (Map.Entry<String, Set<String>> entry : graph.entrySet()) {
            if (isEdge(entry.getKey(), a)) {
                // make sure that you don't miss this.
                if(entry.getKey().equals(b))
                    return 2;
                queue.offer(entry.getKey());
                visited.add(entry.getKey());
                dist.put(entry.getKey(), 2);
            }
        }
        while (queue.size() != 0) {
            String u = queue.poll();
            for (String v : graph.get(u)) {
                if (!visited.contains(v)) {
                    if (v.equals(b)) return dist.get(u) + 1;
                    visited.add(v);
                    dist.put(v, dist.get(u) + 1);
                    queue.offer(v);
                }
            }
        }
        return 0;
    }

    private Map<String, Set<String>> buildGraph(List<String> wordList) {
        Map<String, Set<String>> graph = new HashMap<>();
        for (String a : wordList) {
            for (String b : wordList) {
                if (isEdge(a, b)) {
                    graph.putIfAbsent(a, new HashSet<>());
                    graph.putIfAbsent(b, new HashSet<>());
                    graph.get(a).add(b);
                    graph.get(b).add(a);
                }
            }
        }
        return graph;
    }

    private boolean isEdge(String a, String b) {
        int mismatch = 0;
        int i;
        for (i = 0; i < a.length() && i < b.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                mismatch++;
                if (mismatch > 1)
                    return false;
            }
        }
        return mismatch + Math.abs(a.length() - b.length()) == 1;
    }

}
