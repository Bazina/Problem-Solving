class Solution {
    public String sortVowels(String s) {
        char[] vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        char[] vowelsFrequency = new char[128];
        char[] sChars = s.toCharArray();

        for (char sChar : sChars)
            if (isVowel(sChar))
                vowelsFrequency[sChar - 'A']++;

        int j = 0;
        for (int i = 0; i < sChars.length; i++) {
            if (isVowel(sChars[i])) {
                while (vowelsFrequency[vowels[j] - 'A'] == 0) {
                    j++;
                    if (j == vowels.length)
                        return new String(sChars);
                }
                sChars[i] = vowels[j];
                vowelsFrequency[sChars[i] - 'A']--;
            }
        }

        return new String(sChars);
    }

    boolean isVowel(Character c) {
        return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i'
                || c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I';
    }
}

public class Main {

    public static void main(String[] args) {
        String s = "lEetcOde";
        System.out.println(new Solution().sortVowels(s));
    }
}

/* Count Sort using hashmap
import java.util.HashMap;

class Solution {
    public String sortVowels(String s) {
        char[] vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        HashMap<Character, Integer> vowelsFrequency = new HashMap<>();
        char[] sChars = s.toCharArray();

        for (char sChar : sChars)
            if (isVowel(sChar))
                vowelsFrequency.put(sChar, vowelsFrequency.getOrDefault(sChar, 0) + 1);

        int j = 0;
        for (int i = 0; i < sChars.length; i++) {
            if (isVowel(sChars[i])) {
                while (!vowelsFrequency.containsKey(vowels[j]) || vowelsFrequency.get(vowels[j]) == 0) {
                    j++;
                    if (j == vowels.length)
                        return new String(sChars);
                }
                sChars[i] = vowels[j];
                vowelsFrequency.put(vowels[j], vowelsFrequency.get(vowels[j]) - 1);
            }
        }

        return new String(sChars);
    }

    boolean isVowel(Character c) {
        return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i'
                || c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I';
    }
}
 */