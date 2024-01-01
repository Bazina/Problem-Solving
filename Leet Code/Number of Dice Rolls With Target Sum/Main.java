class Solution {
    int n, k, target, mod = (int) 1e9 + 7;
    int[][] dp;

    public int numRollsToTarget(int n, int k, int target) {
        this.n = n;
        this.k = k;
        this.target = target;
        this.dp = new int[n + 1][target + 1];

        return recur(n, 0);
    }

    public int recur(int remaining, int sum) {
        if (sum == target && remaining == 0)
            return 1;
        if (remaining > target - sum || remaining * k < target - sum)
            return 0;
        if (dp[remaining][sum] != 0)
            return dp[remaining][sum];

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (target - sum < i)
                break;
            ans = (ans + recur(remaining - 1, sum + i)) % mod;
        }

        return dp[remaining][sum] = ans;
    }

    public int iter() {
        if (n == 0 && target == 0)
            return 1;
        if (target < n || n * k < target)
            return 0;

        for (int j = 1; j <= k && j <= target; j++) {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int l = 1; l <= k && l < j; l++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % mod;
                }
            }
        }
        return dp[n][target];
    }
}


public class Main {
    public static void main(String[] args) {
        int n = 30, k = 30, target = 500;
        System.out.println(new Solution().numRollsToTarget(n, k, target));
    }
}