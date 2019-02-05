import java.util.PriorityQueue;

public class LeetCode215 {
    public static void main(String[] args) {
        System.out.println(new LeetCode215().findKthLargest(new int[]{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4));
        System.out.println(new LeetCode215().findKthLargest(new int[]{3, 2, 1, 5, 6, 4}, 2));
        System.out.println(new LeetCode215().findKthLargest(new int[]{3, 3, 3, 3, 3, 3, 3, 3}, 2));


    }

    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(nums.length, (a, b) -> b - a);
        for (int i = 0; i < nums.length; i++) {
            pq.offer(nums[i]);
        }
        int current = pq.poll();
        int counter = 1;
        if (k == 1)
            return current;
        while (pq.size() != 0) {
            int next = pq.poll();
            counter++;
            if (counter == k)
                return next;
        }
        // should never happen (kth max don’t exist in the given array)
        return -1;
    }

}
