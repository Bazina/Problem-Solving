class Solution {
    public char findTheDifference(String s, String t) {
        char[] tChars = new char[t.length()], sChars = new char[s.length()];
        t.getChars(0, t.length(), tChars, 0);
        s.getChars(0, s.length(), sChars, 0);

        for (int i = 0; i < s.length(); i++) {
            tChars[i + 1] += tChars[i] - sChars[i];
        }

        return tChars[tChars.length - 1];
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "abcd";
        String t = "acbed";
        System.out.println(new Solution().findTheDifference(s, t));
    }
}

/* Two for loop 2ms
class Solution {
    public char findTheDifference(String s, String t) {
        int[] charFrequency = new int[26];

        for (int i = 0; i < s.length(); i++) {
            charFrequency[s.charAt(i) - 'a']++;
            charFrequency[t.charAt(i) - 'a']--;
        }

        charFrequency[t.charAt(t.length() - 1) - 'a']--;

        for (int i = 0; i < t.length(); i++) {
            if (charFrequency[t.charAt(i) - 'a'] < 0)
                return t.charAt(i);
        }

        return 'a';
    }
}
 */