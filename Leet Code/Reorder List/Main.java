import java.util.Objects;

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
    public void reorderList(ListNode head) {
        ListNode slowPointer = head, current = head;
        ListNode fastPointer = head.next;

        while (fastPointer != null && fastPointer.next != null) {
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next.next;
        }

        ListNode tail = slowPointer.next;
        ListNode previous = slowPointer.next = null;
        while (tail != null) {
            ListNode temp = tail.next;
            tail.next = previous;
            previous = tail;
            tail = temp;
        }

        tail = previous;
        while (tail != null) {
            ListNode temp1 = current.next;
            ListNode temp2 = tail.next;
            current.next = tail;
            tail.next = temp1;
            current = temp1;
            tail = temp2;
        }
    }
}

public class Main {

    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        Solution min = new Solution();
        min.reorderList(head);

        while (head != null) {
            System.out.println(head.val);
            head = head.next;
        }
    }
}