import java.util.*;

class Solution {
    HashSet<String> wordSet = new HashSet<>();
    HashMap<String, Integer> longestStringChainLength = new HashMap<>();

    public int longestStrChain(String[] words) {
        wordSet.addAll(Arrays.asList(words));

        int maxChainLength = -1;

        for (String word : words) {
            maxChainLength = Math.max(maxChainLength, recur(word));
        }

        return maxChainLength;
    }

    public int recur(String word) {
        if (!wordSet.contains(word))
            return 0;

        if (longestStringChainLength.containsKey(word))
            return longestStringChainLength.get(word);

        int maxChainLength = 1;
        for (int i = 0; i < word.length(); i++) {
            String reducedWord = word.substring(0, i) + word.substring(i + 1);
            maxChainLength = Math.max(recur(reducedWord) + 1, maxChainLength);
        }

        longestStringChainLength.put(word, maxChainLength);
        return maxChainLength;
    }
}

public class Main {
    public static void main(String[] args) {
        String[] words = {"a", "b", "ba", "bca", "bda", "bdca"};
        System.out.println(new Solution().longestStrChain(words));
    }
}

/* Iterative approach O(N *(log(N) + M))
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));

        Map<String, Integer> longestStringChainLength = new HashMap<>();
        int maxChainLength = Integer.MIN_VALUE;

        for (int i = 0; i < words.length; i++) {
            longestStringChainLength.put(words[i], 1);

            for (int j = 0; j < words[i].length(); j++) {
                String reducedWord = words[i].substring(0, j) + words[i].substring(j + 1);

                if (longestStringChainLength.containsKey(reducedWord))
                    longestStringChainLength.put(words[i], Math.max(longestStringChainLength.get(reducedWord) + 1, longestStringChainLength.get(words[i])));
            }

            maxChainLength = Math.max(maxChainLength, longestStringChainLength.get(words[i]));
        }

        return maxChainLength;
    }
}
 */