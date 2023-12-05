class Solution {
    int[] characterFrequency = new int[26];

    public int countCharacters(String[] words, String chars) {
        int answer = 0;

        for (int i = 0; i < chars.length(); i++)
            characterFrequency[chars.charAt(i) - 'a']++;

        for (String word : words)
            if (canForm(word))
                answer += word.length();

        return answer;
    }

    private boolean canForm(String word) {
        int[] wordCharFrequency = new int[26];

        for (int i = 0; i < word.length(); i++) {
            int idx = word.charAt(i) - 'a';
            wordCharFrequency[idx]++;
            if (characterFrequency[idx] < wordCharFrequency[idx])
                return false;
        }

        return true;
    }
}

public class Main {

    public static void main(String[] args) {
        String[] words = {"cat", "bt", "hat", "tree"};
        String chars = "atach";
        System.out.println(new Solution().countCharacters(words, chars));
    }
}