public class LeetCode148 {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode head1 = head;
        ListNode head2 = head;
        while (head2 != null && head2.next != null && head2.next.next != null) {
            head1 = head1.next;
            head2 = head2.next.next;
        }
        ListNode nextPtr = head1.next;
        head1.next = null;
        head1 = sortList(head);
        head2 = sortList(nextPtr);
        return merge(head1, head2);
    }

    private ListNode merge(ListNode h1, ListNode h2) {
        ListNode result = null, last = null;
        while (h1 != null && h2 != null) {
            if (h1.val < h2.val) {
                if (result == null) {
                    result = last = h1;
                } else {
                    last.next = h1;
                    last = last.next;
                }
                h1 = h1.next;
            } else {
                if (result == null) {
                    result = last = h2;
                } else {
                    last.next = h2;
                    last = last.next;
                }
                h2 = h2.next;
            }
        }
        while (h1 != null) {
            if (result == null) {
                result = last = h1;
            } else {
                last.next = h1;
                last = last.next;
            }
            h1 = h1.next;
        }
        while (h2 != null) {
            if (result == null) {
                result = last = h2;
            } else {
                last.next = h2;
                last = last.next;
            }
            h2 = h2.next;
        }
        return result;

    }

    private static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

}
