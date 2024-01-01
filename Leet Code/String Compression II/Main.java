import java.util.Arrays;

class Solution {
    int n;
    int[][] dp;
    char[] sChars;

    public int getLengthOfOptimalCompression(String s, int k) {
        n = s.length();
        sChars = s.toCharArray();
        dp = new int[n + 1][k + 1];
        for (int[] row : dp)
            Arrays.fill(row, -1);

        return recur(0, k);
    }

    public int recur(int i, int k) {
        if (k < 0)
            return n;
        if (i + k >= n)
            return 0;

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        int ans = recur(i + 1, k - 1);
        int runLengthEncodingLength = 0, same = 0, diff = 0;

        for (int j = i; j < n && diff <= k; j++) {
            if (sChars[i] == sChars[j]) {
                same++;
                runLengthEncodingLength += (same <= 2 || same == 10 || same == 100) ? 1 : 0;
            } else {
                diff++;
            }

            ans = Math.min(ans, runLengthEncodingLength + recur(j + 1, k - diff));
        }

        dp[i][k] = ans;
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "bababbaba";
        int k = 1;
        System.out.println(new Solution().getLengthOfOptimalCompression(s, k));
    }
}