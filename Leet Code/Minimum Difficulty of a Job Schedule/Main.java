import java.util.HashMap;

class Solution {
    int n, d;
    int[] jobDifficulty;
    HashMap<String, Integer> memo = new HashMap<>();
    int[][] dp;

    public int minDifficulty(int[] jobDifficulty, int d) {
        if (jobDifficulty.length < d)
            return -1;

        n = jobDifficulty.length;
        this.d = d;
        this.jobDifficulty = jobDifficulty;
        dp = new int[d + 1][n + 1];

        //int ans = recur(0, d, -1);
        //return (ans == Integer.MAX_VALUE) ? -1 : ans;
        return iter();
    }

    public int recur(int i, int d, int currentMax) {
        if (d == 0 && i == n)
            return 0;

        if (d <= 0 || i >= n)
            return Integer.MAX_VALUE;

        String key = i + ' ' + Integer.toString(d) + ' ' + currentMax;

        if (memo.containsKey(key))
            return memo.get(key);

        currentMax = Math.max(jobDifficulty[i], currentMax);
        int newDay = recur(i + 1, d - 1, -1);

        if (newDay != Integer.MAX_VALUE)
            newDay += currentMax;

        int ans = Math.min(newDay, recur(i + 1, d, currentMax));
        memo.put(key, ans);
        return ans;
    }

    public int iter() {
        for (int i = 1; i <= n; i++) {
            dp[1][i] = Math.max(dp[1][i - 1], jobDifficulty[i - 1]);
        }

        for (int i = 2; i <= d; i++) {
            for (int j = i; j <= n; j++) {
                int currentMax = jobDifficulty[j - 1];
                dp[i][j] = Integer.MAX_VALUE;

                for (int k = j; k >= i; k--) {
                    currentMax = Math.max(jobDifficulty[k - 1], currentMax);
                    dp[i][j] = Math.min(dp[i][j], currentMax + dp[i - 1][k - 1]);
                }
            }
        }

        return dp[d][n];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] jobDifficulty = {6, 5, 4, 3, 2, 1};
        int d = 2;
        System.out.println(new Solution().minDifficulty(jobDifficulty, d));
    }
}