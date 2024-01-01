class Solution {
    public boolean makeEqual(String[] words) {
        int[] freq = new int[26];
        int n = words.length;

        for (String s : words) {
            char[] word = s.toCharArray();
            for (int j = 0; j < s.length(); j++) {
                freq[word[j] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++)
            if (freq[i] % n != 0)
                return false;


        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        String[] words = {
                "abc", "aabc", "bc"
        };
        System.out.println(new Solution().makeEqual(words));
    }
}