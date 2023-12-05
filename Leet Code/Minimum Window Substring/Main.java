import java.util.HashMap;

class Solution {
    public String minWindow(String s, String t) {
        HashMap<Character, Integer> neededCharacterFrequencyMap = new HashMap<>(), characterFrequencyMap = new HashMap<>();

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            neededCharacterFrequencyMap.put(c, neededCharacterFrequencyMap.getOrDefault(c, 0) + 1);
        }
        int have = 0, need = neededCharacterFrequencyMap.size();

        int r = 0, minL = 0, minR = 0, minLength = Integer.MAX_VALUE;
        for (int l = 0; l < s.length(); l++) {
            while (r < s.length() && need != have) {
                char c = s.charAt(r);

                if (neededCharacterFrequencyMap.containsKey(c)) {
                    int oldCharFrequency = characterFrequencyMap.getOrDefault(c, 0);
                    characterFrequencyMap.put(c, oldCharFrequency + 1);
                    if (oldCharFrequency + 1 == neededCharacterFrequencyMap.get(c))
                        have++;
                }

                r++;
            }

            if (have == need) {
                char leftChar = s.charAt(l);
                if (minLength > r - l) {
                    minL = l;
                    minR = r;
                    minLength = r - l;
                }
                if (characterFrequencyMap.containsKey(leftChar)) {
                    int charFrequency = characterFrequencyMap.get(leftChar);
                    characterFrequencyMap.put(leftChar, charFrequency - 1);
                    if (charFrequency - 1 < neededCharacterFrequencyMap.get(leftChar))
                        have--;
                }
            }
        }

        return s.substring(minL, minR);
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "aa", t = "aa";
        System.out.println(new Solution().minWindow(s, t));
    }
}