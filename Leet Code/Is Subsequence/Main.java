class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0)
            return true;

        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j))
                i++;

            j++;
        }

        return i == s.length();
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "abc";
        String t = "ahbgdc";
        System.out.println(new Solution().isSubsequence(s, t));
    }
}