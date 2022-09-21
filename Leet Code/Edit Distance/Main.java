import java.util.Arrays;

class Solution {
    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        for (int[] ints : dp) Arrays.fill(ints, -1);

        return recur(word1.length(), word2.length(), dp, word1, word2);
    }

    int recur(int i, int j, int[][] dp, String s1, String s2) {
        if (i == 0 && j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans1 = Integer.MAX_VALUE, ans2 = Integer.MAX_VALUE, ans3 = Integer.MAX_VALUE;
        if (i != 0 && j != 0 && s1.charAt(i - 1) == s2.charAt(j - 1))
            return dp[i][j] = recur(i - 1, j - 1, dp, s1, s2);
        if (i != 0 && j != 0)
            ans1 = 1 + recur(i - 1, j - 1, dp, s1, s2);
        if (i != 0)
            ans2 = 1 + recur(i - 1, j, dp, s1, s2);
        if (j != 0)
            ans3 = 1 + recur(i, j - 1, dp, s1, s2);

        return dp[i][j] = Math.min(ans1, Math.min(ans2, ans3));
    }
}

public class Main {
    public static void main(String[] args) {
        String s1 = "horse", s2 = "ros";
        Solution solution = new Solution();
        System.out.println(solution.minDistance(s1, s2));
    }
}