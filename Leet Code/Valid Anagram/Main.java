import java.util.Arrays;

class Solution {
    public boolean isAnagram(String s, String t) {
        int[] freq = new int[26];
        Arrays.fill(freq, 0);
        for (int i = 0; i < s.length(); i++)
          freq[s.charAt(i) - 'a']++;

        for (int i = 0; i < t.length(); i++)
            freq[t.charAt(i) - 'a']--;

        for (int i = 0; i < 26; i++)
            if (freq[i] != 0)
                return false;

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "rat", t = "car";
        Solution solution = new Solution();
        System.out.println(solution.isAnagram(s, t));
    }
}