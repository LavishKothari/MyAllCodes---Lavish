public class LeetCode19 {
    /*
     * A simple approach it to count the total number of nodes, and then remove
     * (total-n+1)th node from the beginning
     *
     * but the following solution does this in just one pass
     */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            if (n == 0) return head;
            throw new IllegalArgumentException("the list is of shorter length");
        }

        ListNode front = head, back = head;
        for (int i = 0; i < n - 1; i++) {
            if (front == null)
                throw new IllegalArgumentException("the list is of shorter length");
            front = front.next;
        }
        ListNode prev = null;
        while (front.next != null) {
            prev = back;
            back = back.next;
            front = front.next;
        }
        if (prev == null) {
            ListNode temp = head.next;
            head.next = null;
            return temp;
        } else {
            prev.next = back.next;
            back.next = null;
            return head;
        }
    }

    private static class ListNode {
        int val;
        ListNode next;

        public ListNode(int x) {
            this.val = x;
        }
    }
}
