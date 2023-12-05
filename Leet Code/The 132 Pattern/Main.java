import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums.length < 3)
            return false;

        Deque<Integer> monotonicStack = new ArrayDeque<>();
        int currentMax = Integer.MIN_VALUE;

        for (int i = nums.length - 1; i >= 0; i--) {
            int nextElement = nums[i];

            if (currentMax > nextElement)
                return true;

            while (!monotonicStack.isEmpty() && nextElement > monotonicStack.peek())
                currentMax = monotonicStack.pop();

            monotonicStack.push(nextElement);
        }

        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {3, 5, 0, 3, 4};
        System.out.println(new Solution().find132pattern(nums));
    }
}