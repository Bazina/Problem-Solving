import java.util.Arrays;

class Solution {
    int mod = 1_000_000_007;
    int[][][] memo;

    public int numOfArrays(int n, int m, int k) {
        memo = new int[n][m + 1][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }

        return recur(n, m, k, 0, 0, 0);
    }

    private int recur(int n, int m, int k, int currentLength, int currentCost, int maxValue) {
        if (currentLength == n && currentCost == k)
            return 1;
        else if (currentCost > k || currentLength == n)
            return 0;

        if (memo[currentLength][maxValue][currentCost] != -1)
            return memo[currentLength][maxValue][currentCost];

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (currentLength < n) {
                int newMaxValue, newCurrentCost = currentCost;
                if (maxValue < i) {
                    newMaxValue = i;
                    newCurrentCost++;
                    ans = (ans + recur(n, m, k, currentLength + 1, newCurrentCost, newMaxValue)) % mod;
                } else {
                    ans = (ans + recur(n, m, k, currentLength + 1, currentCost, maxValue)) % mod;
                }
            }
        }

        return memo[currentLength][maxValue][currentCost] = ans;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 50, m = 100, k = 25;
        System.out.println(new Solution().numOfArrays(n, m, k));
    }
}