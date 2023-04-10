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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null || list2 == null)
            return (list1 != null) ? list1 : list2;

        ListNode ans = new ListNode();
        ListNode current = ans;

        while (list1 != null && list2 != null) {
            if (list1.val > list2.val) {
                ans.next = list2;
                ans = ans.next;
                list2 = list2.next;
            } else {
                ans.next = list1;
                ans = ans.next;
                list1 = list1.next;
            }
        }

        ans.next = (list1 != null) ? list1 : list2;

        return current.next;
    }
}

public class Main {

    public static void main(String[] args) {
        ListNode list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        Solution min = new Solution();
        System.out.println(min.mergeTwoLists(list1, list2));
    }
}