class Solution {

    public String longestPalindrome(String s) {
        String answer = "";
        int length = 0;

        for (int i = 0; i < s.length(); i++) {
            int l = i, r = i;

            while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
                int substringLength = r - l + 1;
                if (substringLength > length) {
                    length = substringLength;
                    answer = s.substring(l, r + 1);
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
                int substringLength = r - l + 1;
                if (substringLength > length) {
                    length = substringLength;
                    answer = s.substring(l, r + 1);
                }
                l--;
                r++;
            }
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "aacabdkacaa";
        System.out.println(new Solution().longestPalindrome(s));
    }
}