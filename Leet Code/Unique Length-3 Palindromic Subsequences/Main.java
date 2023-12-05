import java.util.Arrays;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int answer = 0;
        boolean[] numberOfUnique;
        int[] lastOccurrence = new int[26], firstOccurrence = new int[26];
        char[] sChars = s.toCharArray();
        Arrays.fill(firstOccurrence, -1);

        for (int i = 0; i < sChars.length; i++) {
            int idx = sChars[i] - 'a';

            lastOccurrence[idx] = i;

            if (firstOccurrence[idx] == -1)
                firstOccurrence[idx] = i;
        }

        for (int i = 0; i < 26; i++) {
            int lastOccurrenceIdx = lastOccurrence[i];
            int firstOccurrenceIdx = firstOccurrence[i];

            if (firstOccurrenceIdx == -1) continue;

            numberOfUnique = new boolean[26];
            int count = 0;

            for (int j = firstOccurrenceIdx + 1; j < lastOccurrenceIdx; j++) {
                if (!numberOfUnique[sChars[j] - 'a']) {
                    numberOfUnique[sChars[j] - 'a'] = true;
                    count++;
                }
            }

            answer += count;
        }

        return answer;
    }
}

public class Main {

    public static void main(String[] args) {
        String s = "bbcbaba";
        System.out.println(new Solution().countPalindromicSubsequence(s));
    }
}