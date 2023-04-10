class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int[][] dp = new int[str1.length() + 1][str2.length() + 1];
        for (int i = 0; i <= str1.length(); i++)
            dp[i][0] = i;

        for (int i = 0; i <= str2.length(); i++)
            dp[0][i] = i;

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + Math.min(dp[i - 1][j],
                            dp[i][j - 1]);
            }
        }

        return shortestCommonSupersequenceBuild(dp, str1, str2);
    }

    public String shortestCommonSupersequenceBuild(int[][] dp, String str1, String str2) {
        int i = str1.length(), j = str2.length(), k = dp[i][j];
        char[] ans = new char[dp[i][j]];

        while (i > 0 && j > 0) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                ans[--k] = str1.charAt(i - 1);
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans[--k] = str1.charAt(i - 1);
                i--;
            } else {
                ans[--k] = str2.charAt(j - 1);
                j--;
            }
        }

        while (i > 0) {
            ans[--k] = str1.charAt(i - 1);
            i--;
        }

        while (j > 0) {
            ans[--k] = str2.charAt(j - 1);
            j--;
        }

        return new String(ans);
    }
}

public class Main {
    public static void main(String[] args) {
        String s1 = "cab", s2 = "abac";
        Solution solution = new Solution();
        System.out.println(solution.shortestCommonSupersequence(s1, s2));
    }
}