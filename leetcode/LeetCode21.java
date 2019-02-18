public class LeetCode21 {
    public static void main(String[] args) {
        ListNode h1 = new ListNode(1);
        h1.next = new ListNode(2);
        h1.next.next = new ListNode(4);

        ListNode h2 = new ListNode(1);
        h2.next = new ListNode(3);
        h2.next.next = new ListNode(4);

        System.out.println(new LeetCode21().mergeTwoLists(h1, h2));
        System.out.println(new LeetCode21().mergeTwoLists(null, h2));
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = null, last = null;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                if (head == null) head = l1;
                else last.next = l1;
                l1 = l1.next;
            } else {
                if (head == null) head = l2;
                else last.next = l2;
                l2 = l2.next;
            }
            if (last == null) last = head;
            else last = last.next;
        }

        if (l1 != null) {
            if (last == null) head = l1;
            else last.next = l1;
        }
        if (l2 != null) {
            if (last == null) head = l2;
            else last.next = l2;
        }

        return head;
    }

    private static class ListNode {
        int val;
        ListNode next;

        public ListNode(int x) {
            val = x;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            ListNode cn = this;
            while (cn != null) {
                sb.append(cn.val + " ");
                cn = cn.next;
            }
            return sb.toString();
        }
    }
}
