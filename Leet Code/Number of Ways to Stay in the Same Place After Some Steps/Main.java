class Solution {
    int steps, arrLen, mod = 1_000_000_007;
    int[][] dp;

    public int numWays(int steps, int arrLen) {
        this.arrLen = Math.min(arrLen, steps);
        this.steps = steps;
        this.dp = new int[this.arrLen][this.steps + 1];

        dp[0][0] = 1;

        for (int j = 1; j <= this.steps; j++) {
            for (int i = 0; i < this.arrLen; i++) {
                int leftPosition = i - 1, rightPosition = i + 1;

                dp[i][j] = dp[i][j - 1];
                if (leftPosition >= 0)
                    dp[i][j] = (dp[i][j] + dp[leftPosition][j - 1]) % mod;
                if (rightPosition < this.arrLen)
                    dp[i][j] = (dp[i][j] + dp[rightPosition][j - 1]) % mod;
            }
        }

        return dp[0][this.steps];
    }
}

public class Main {
    public static void main(String[] args) {
        int steps = 3, arrLen = 2;
        System.out.println(new Solution().numWays(steps, arrLen));
    }
}

/* recur
import java.util.Arrays;

class Solution {
    int steps, arrLen, mod = 1_000_000_007;
    int[][] dp;

    public int numWays(int steps, int arrLen) {
        this.arrLen = Math.min(arrLen, steps);
        this.steps = steps;
        this.dp = new int[this.arrLen][this.steps];

        for (int[] ints : dp) Arrays.fill(ints, -1);

        return recur(0, 0);
    }

    private int recur(int position, int step) {
        if (position == 0 && step == steps)
            return 1;
        if (step == steps)
            return 0;

        if (dp[position][step] != -1)
            return dp[position][step];

        int leftPosition = position - 1, rightPosition = position + 1, ans = 0;

        if (leftPosition >= 0)
            ans = (ans + recur(leftPosition, step + 1)) % mod;
        if (rightPosition < arrLen)
            ans = (ans + recur(rightPosition, step + 1)) % mod;

        ans = (ans + recur(position, step + 1)) % mod;

        return dp[position][step] = ans;
    }
}
 */