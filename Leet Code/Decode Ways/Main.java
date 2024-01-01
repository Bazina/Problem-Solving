class Solution {
    int n;
    int[] dp;
    char[] sChars;

    public int numDecodings(String s) {
        n = s.length();
        sChars = s.toCharArray();
        dp = new int[n + 1];

        return iter();
    }

    public int recur(int remaining) {
        if (remaining < 0)
            return 1;

        if (dp[remaining] != -1)
            return dp[remaining];

        int ans = 0;
        int second = sChars[remaining] - '0';

        if (second != 0)
            ans += recur(remaining - 1);
        if (remaining > 0) {
            int first = sChars[remaining - 1] - '0';
            if ((first == 2 && second <= 6) || first == 1)
                ans += recur(remaining - 2);
        }
        return dp[remaining] = ans;
    }

    public int iter() {
        if (sChars[0] == '0')
            return 0;

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int first = sChars[i - 2] - '0';
            int second = sChars[i - 1] - '0';

            if (second != 0)
                dp[i] += dp[i - 1];

            if ((first == 2 && second <= 6) || first == 1)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
}


public class Main {
    public static void main(String[] args) {
        String s = "2611055971756562";
        System.out.println(new Solution().numDecodings(s));
    }
}