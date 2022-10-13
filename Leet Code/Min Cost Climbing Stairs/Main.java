class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length + 1];
        dp[0] = 0;
        dp[1] = cost[0];

        for (int i = 2; i <= cost.length; i++)
            dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 1]);
        int ans1 = dp[cost.length];

        dp[1] = 0;
        for (int i = 2; i <= cost.length; i++)
            dp[i] = Math.min(dp[i - 1] + cost[i - 2], dp[i - 2] + cost[i - 2]);
        int ans2 = dp[cost.length];

        return Math.min(ans1, ans2);
    }

    private int recur(int curr, int n, int[] dp, int[] cost, int idx) {
        if (curr == n)
            return 0;
        if (dp[curr] != -1)
            return dp[curr];

        int ans1 = Integer.MAX_VALUE, ans2 = Integer.MAX_VALUE;
        if (n - curr >= 1)
            ans1 = cost[idx] + recur(curr + 1, n, dp, cost, idx + 1);
        if (n - curr >= 2)
            ans2 = cost[idx] + recur(curr + 2, n, dp, cost, idx + 2);

        dp[curr] = Math.min(ans1, ans2);
        return dp[curr];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        Solution solution = new Solution();
        System.out.println(solution.minCostClimbingStairs(cost));
    }
}