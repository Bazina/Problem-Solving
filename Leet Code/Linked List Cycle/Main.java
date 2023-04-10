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
    public boolean hasCycle(ListNode head) {
        ListNode fast = head, slow = head;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        ListNode cycle = new ListNode(2);
        ListNode head = new ListNode(1, cycle);
        cycle.next = new ListNode(0, new ListNode(4, cycle));
        System.out.println(new Solution().hasCycle(head));
    }
}