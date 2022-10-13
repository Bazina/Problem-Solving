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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0)
            return null;

        return mergeLists(lists, 0, lists.length - 1);
    }

    public ListNode mergeLists(ListNode[] lists, int l, int r) {
        if (l <= r) {
            int mid = (l + r) / 2;

            ListNode leftList = mergeLists(lists, l, mid);
            ListNode rightList = mergeLists(lists, mid + 1, r);

            return merge(leftList, rightList);
        } else
            return lists[l];
    }

    public ListNode merge(ListNode leftList, ListNode rightList) {
        if (leftList == null || rightList == null)
            return (leftList != null) ? leftList : rightList;

        ListNode ans = new ListNode(0);
        ListNode temp = ans;

        while (rightList != null && leftList != null) {
            if (rightList.val > leftList.val) {
                temp.next = leftList;
                leftList = leftList.next;
            } else {
                temp.next = rightList;
                rightList = rightList.next;
            }
            temp = temp.next;
        }

        temp.next = (leftList != null) ? leftList : rightList;

        return ans.next;
    }
}

public class Main {

    public static void main(String[] args) {
        ListNode[] lists = {
                new ListNode(1, new ListNode(4, new ListNode(5))),
                new ListNode(1, new ListNode(3, new ListNode(4))),
                new ListNode(2, new ListNode(6))
        };
        Solution min = new Solution();
        System.out.println(min.mergeKLists(lists));
    }
}

/* Another Solution
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode ans, temp;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (ListNode list : lists) {
            ListNode cur = list;
            while (cur != null) {
                pq.add(cur.val);
                cur = cur.next;
            }
        }

        if (pq.isEmpty())
            return null;
        else {
            ans = new ListNode();
            temp = ans;
        }

        while (!pq.isEmpty()) {
            temp.val = pq.poll();
            if (!pq.isEmpty()) {
                temp.next = new ListNode();
                temp = temp.next;
            }
        }

        return ans;
    }
}
 */