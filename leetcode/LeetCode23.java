import java.util.PriorityQueue;

public class LeetCode23 {
    public ListNode mergeKLists(ListNode[] lists) {
        // min-heap
        PriorityQueue<ListNode> pq = new PriorityQueue<>((node1, node2) -> node1.val - node2.val);
        for (int i = 0; i < lists.length; i++)
            if (lists[i] != null)
                pq.offer(lists[i]);
        ListNode resultHead = null;
        ListNode resultLast = null;
        while (pq.size() != 0) {
            ListNode current = pq.poll();
            if (resultHead == null)
                resultHead = resultLast = current;
            else {
                resultLast.next = current;
                resultLast = current;
            }
            current = current.next;
            if (current != null)
                pq.offer(current);
        }
        return resultHead;
    }

    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

}
