import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        int sum = Integer.MIN_VALUE;
        int[] dp = new int[nums.length];
        Deque<Integer> monotonicQueue = new ArrayDeque<>();

        for (int i = 0; i < nums.length; i++) {
            while (!monotonicQueue.isEmpty() && i - monotonicQueue.peek() > k)
                monotonicQueue.poll();

            dp[i] = (monotonicQueue.isEmpty() ? 0 : dp[monotonicQueue.peek()]) + nums[i];
            sum = Math.max(dp[i], sum);

            while (!monotonicQueue.isEmpty() && dp[monotonicQueue.peekLast()] < dp[i])
                monotonicQueue.pollLast();

            if (dp[i] > 0)
                monotonicQueue.add(i);
        }

        return sum;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {10, 2, -10, 5, 20};
        int k = 3;
        System.out.println(new Solution().constrainedSubsetSum(nums, k));
    }
}