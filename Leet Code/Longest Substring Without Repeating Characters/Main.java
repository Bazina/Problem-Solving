class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0)
            return 0;

        int len = 1, l = 0, r = 1;
        int[] freq = new int[500];
        freq[s.charAt(l) - ' ']++;

        while (r < s.length()) {
            int idx = s.charAt(r) - ' ';
            freq[idx]++;

            while (freq[idx] > 1 && l < r) {
                freq[s.charAt(l) - ' ']--;
                l++;
            }

            len = Math.max(len, r - l + 1);
            r++;
        }

        return len;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "abcabcbb";
        Solution min = new Solution();
        System.out.println(min.lengthOfLongestSubstring(s));
    }
}