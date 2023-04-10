import java.util.ArrayList;
import java.util.List;

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

    private List<Integer> sum(int value1, int value2, int carry) {
        List<Integer> answer = new ArrayList<>();

        int sum = value1 + value2 + carry;
        if (sum > 9) {
            answer.add(sum % 10);
            answer.add(1);
        } else {
            answer.add(sum);
            answer.add(0);
        }

        return answer;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode answer = new ListNode();
        ListNode node = answer;
        ListNode previousNode = null;
        List<Integer> sumAndCarry;
        int carry = 0;

        while (l1 != null && l2 != null) {
            sumAndCarry = sum(l1.val, l2.val, carry);
            node.val = sumAndCarry.get(0);
            carry = sumAndCarry.get(1);

            previousNode = node;
            node.next = new ListNode();
            node = node.next;

            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1 != null) {
            sumAndCarry = sum(l1.val, 0, carry);
            node.val = sumAndCarry.get(0);
            carry = sumAndCarry.get(1);

            previousNode = node;
            node.next = new ListNode();
            node = node.next;
            l1 = l1.next;
        }

        while (l2 != null) {
            sumAndCarry = sum(l2.val, 0, carry);
            node.val = sumAndCarry.get(0);
            carry = sumAndCarry.get(1);

            previousNode = node;
            node.next = new ListNode();
            node = node.next;
            l2 = l2.next;
        }

        if (carry == 1)
            node.val++;
        else if (previousNode != null)
            previousNode.next = null;

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
        ListNode l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
        System.out.println(new Solution().addTwoNumbers(l1, l2));
    }
}