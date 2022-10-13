import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        ArrayList<ArrayList<Integer>> sortedFreq = new ArrayList<>(100005);
        for (int i = 0; i < 100005; i++)
            sortedFreq.add(new ArrayList<>());

        ArrayList<Integer> ans = new ArrayList<>();
        int mx = Integer.MIN_VALUE;

        for (int num : nums) {
            int v = freq.getOrDefault(num, 0);
            freq.put(num, v + 1);
        }

        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            sortedFreq.get(entry.getValue()).add(entry.getKey());
            mx = Math.max(entry.getValue(), mx);
        }

        for (int i = mx; i >= 0; i--) {
            for (int y : sortedFreq.get(i)) {
                if (ans.size() < k)
                    ans.add(y);
                else
                    return ans.stream().mapToInt(j -> j).toArray();
            }
        }

        return ans.stream().mapToInt(j -> j).toArray();
    }
}

public class Main {
    public static void main(String[] args) {
        int k = 1;
        int[] nums = {1};
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.topKFrequent(nums, k)));
    }
}