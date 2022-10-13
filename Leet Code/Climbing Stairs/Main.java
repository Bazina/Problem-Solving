class Solution {
    public int climbStairs(int n) {
        if (n <= 2)
            return n;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    private int recur(int curr, int n, int[] dp) {
        if (curr == n)
            return 1;
        if (dp[curr] != -1)
            return dp[curr];

        int ans = 0;
        if (n - curr >= 1)
            ans += recur(curr + 1, n, dp);
        if (n - curr >= 2)
            ans += recur(curr + 2, n, dp);

        dp[curr] = ans;
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 1;
        Solution solution = new Solution();
        System.out.println(solution.climbStairs(n));
    }
}