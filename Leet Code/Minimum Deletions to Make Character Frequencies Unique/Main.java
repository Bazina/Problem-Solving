import java.util.HashSet;

class Solution {
    public int minDeletions(String s) {
        int minDeletions = 0;
        int[] freq = new int[26];
        HashSet<Integer> existingFreq = new HashSet<>();

        for (int i = 0; i < s.length(); i++)
            freq[s.charAt(i) - 'a']++;

        for (int i = 0; i < freq.length; i++) {
            while (freq[i] > 0 && existingFreq.contains(freq[i])) {
                freq[i]--;
                minDeletions++;
            }

            existingFreq.add(freq[i]);
        }

        return minDeletions;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "aaaaccbiiiiiiiiikkkkkkkkklllllllll";
        System.out.println(new Solution().minDeletions(s));
    }
}