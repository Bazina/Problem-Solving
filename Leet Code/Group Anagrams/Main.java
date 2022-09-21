import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> group = new HashMap<>();
        for (String str : strs) {
            char[] x = str.toCharArray();
            Arrays.sort(x);
            String y = new String(x);

            List<String> dummy = group.getOrDefault(y, new ArrayList<>());
            dummy.add(str);
            group.put(y, dummy);
        }

        return new ArrayList<>(group.values());
    }
}

public class Main {
    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        Solution solution = new Solution();
        System.out.println(solution.groupAnagrams(strs));
    }
}

/* Another Solution but O(m * n log n)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> group = new HashMap<>();
        for (String str : strs) {
            char[] freq = new char[26];
            for (char c : str.toCharArray())
                freq[c - 'a']++;

            String key = new String(freq);

            group.computeIfAbsent(key, k -> new ArrayList<>());
            group.get(key).add(str);
        }

        return new ArrayList<>(group.values());
    }
}
 */