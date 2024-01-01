class Solution {
    public int maxScore(String s) {
        int ones = 0;
        int zeros = 0;
        int best = Integer.MIN_VALUE;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '1') {
                ones++;
            } else {
                zeros++;
            }

            best = Math.max(best, zeros - ones);
        }

        if (s.charAt(s.length() - 1) == '1') {
            ones++;
        }

        return best + ones;
    }
}


public class Main {
    public static void main(String[] args) {
        String s = "011101";
        System.out.println(new Solution().maxScore(s));
    }
}