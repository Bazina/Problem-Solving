class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] firstIndex = new int[26];
        char[] sChars = s.toCharArray();
        int ans = -1;

        for (int i = 0; i < s.length(); i++) {
            int idx = sChars[i] - 'a';
            if (firstIndex[idx] != 0) {
                ans = Math.max(ans, i - firstIndex[idx]);
            } else {
                firstIndex[idx] = i + 1;
            }
        }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "abca";
        System.out.println(new Solution().maxLengthBetweenEqualCharacters(s));
    }
}