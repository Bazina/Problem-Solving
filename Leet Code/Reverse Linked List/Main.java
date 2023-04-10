class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = head, temp = null;
        if (head != null && head.next != null)
            head = head.next;
        else
            return head;

        while (head.next != null) {
            dummy.next = temp;
            temp = dummy;
            dummy = head;
            head = head.next;
        }

        dummy.next = temp;
        head.next = dummy;

        return head;
    }
}

public class Main {

    public static void main(String[] args) {
        ListNode head = new ListNode(1,
                new ListNode(2,
                        new ListNode(3,
                                new ListNode(4,
                                        new ListNode(5)))));
        Solution min = new Solution();
        System.out.println(min.reverseList(head));
    }
}