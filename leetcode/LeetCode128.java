import java.util.HashMap;
import java.util.Map;

public class LeetCode128 {
    public static void main(String[] args) {
        System.out.println(new LeetCode128().longestConsecutive(new int[]{100, 4, 200, 1, 3, 2}));
        System.out.println(new LeetCode128().longestConsecutive(new int[]{5, 4, 3, 2, 1}));
        System.out.println(new LeetCode128().longestConsecutive(new int[]{1, 3, 5, 9}));
        System.out.println(new LeetCode128().longestConsecutive(new int[]{2}));
        System.out.println(new LeetCode128().longestConsecutive(new int[]{}));
        System.out.println(new LeetCode128().longestConsecutive(new int[]{0, 0, -1})); // output should be 2
    }

    public int longestConsecutive(int[] nums) {
        if (nums.length == 0)
            return 0;
        int[] parent = new int[nums.length];
        int[] size = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        // make sure that you iterate over the map instead of the whole array
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int b = entry.getKey();
            int a = b - 1;
            int c = b + 1;
            if (map.containsKey(a))
                merge(entry.getValue(), map.get(a), parent, size);
            if (map.containsKey(c))
                merge(entry.getValue(), map.get(c), parent, size);
        }

        int max = 1;
        for (int i = 0; i < nums.length; i++) {
            int r = find(i, parent);
            max = max < size[r] ? size[r] : max;
        }
        return max;
    }

    // find the index representative element of the number present at this index
    private int find(int index, int[] parent) {
        if (parent[index] == index) return index;
        return parent[index] = find(parent[index], parent);
    }

    private void merge(int a, int b, int[] parent, int[] size) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                size[pa] += size[pb];
                parent[pb] = pa;
            } else {
                size[pb] += size[pa];
                parent[pa] = pb;
            }
        }
    }

}
