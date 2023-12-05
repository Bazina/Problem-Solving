class Solution {
    int n;
    int[] cost, time;
    int[][] dp;

    public int paintWalls(int[] cost, int[] time) {
        this.cost = cost;
        this.time = time;
        n = this.cost.length;
        this.dp = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            dp[0][i] = (int) 1e9;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int paint = cost[i - 1] + dp[i - 1][Math.max(0, j - 1 - time[i - 1])];
                int dontPaint = dp[i - 1][j];

                dp[i][j] = Math.min(paint, dontPaint);
            }
        }

        return dp[n][n];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] cost = {8, 7, 5, 15}, time = {1, 1, 2, 1};
        System.out.println(new Solution().paintWalls(cost, time));
    }
}

/* recur
import java.util.Arrays;

class Solution {
    int n;
    int[] cost, time;
    int[][] dp;

    public int paintWalls(int[] cost, int[] time) {
        this.cost = cost;
        this.time = time;
        n = this.cost.length;
        this.dp = new int[n][n + 1];

        for (int[] ints : dp) Arrays.fill(ints, 0);

        return recur(0, n);
    }

    private int recur(int i, int remainingWalls) {
        if (remainingWalls <= 0)
            return 0;
        if (i == n)
            return (int) 1e9;

        if (dp[i][remainingWalls] != 0)
            return dp[i][remainingWalls];

        int paint = cost[i] + recur(i + 1, remainingWalls - 1 - time[i]);
        int dontPaint = recur(i + 1, remainingWalls);

        return dp[i][remainingWalls] = Math.min(paint, dontPaint);
    }
}
 */