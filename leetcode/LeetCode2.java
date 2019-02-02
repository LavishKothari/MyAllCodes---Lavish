public class LeetCode2 {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result, last; // maintaining first and last
        result = last = null;
        int carry = 0;
        while (l1 != null && l2 != null) {
            int newVal = (l1.val + l2.val + carry) % 10;
            carry = (l1.val + l2.val + carry) / 10;
            if (result == null)
                result = last = new ListNode(newVal);
            else {
                last.next = new ListNode(newVal);
                last = last.next;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            int newVal = (l1.val + carry) % 10;
            carry = (l1.val + carry) / 10;
            if (result == null)
                result = last = new ListNode(newVal);
            else {
                last.next = new ListNode(newVal);
                last = last.next;
            }

            l1 = l1.next;
        }
        while (l2 != null) {
            int newVal = (l2.val + carry) % 10;
            carry = (l2.val + carry) / 10;
            if (result == null)
                result = last = new ListNode(newVal);
            else {
                last.next = new ListNode(newVal);
                last = last.next;
            }

            l2 = l2.next;
        }
        if (carry != 0) {
            last.next = new ListNode(carry);
        }
        return result;
    }

}

