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
    public ListNode insertionSortList(ListNode head) {
        ListNode current = head, currentHead = head, node = head;

        while (current != null && current.next != null) {
            if (current.val > current.next.val) {
                ListNode nextToCurrent = current.next;
                ListNode previous = null;
                current.next = nextToCurrent.next;
                node = currentHead;

                while (node.val < nextToCurrent.val) {
                    previous = node;
                    node = node.next;
                }
                nextToCurrent.next = node;

                if (previous != null)
                    previous.next = nextToCurrent;
                else
                    currentHead = nextToCurrent;
            } else
                current = current.next;
        }

        return currentHead;
    }
}

public class Main {
    public static void main(String[] args) {
        ListNode head = new ListNode(4);
        head.next = new ListNode(2);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(3);

        Solution solution = new Solution();
        ListNode ans = solution.insertionSortList(head);
        while (ans != null) {
            System.out.println(ans.val);
            ans = ans.next;
        }
    }
}
