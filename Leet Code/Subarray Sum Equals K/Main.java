import java.util.HashMap;

class Solution {
    public int subarraySum(int[] nums, int k) {
        int prefixSum = 0, sum, cnt = 0;
        HashMap<Integer, Integer> freqPrefixMap = new HashMap<>();
        freqPrefixMap.put(0, 1);

        for (int num : nums) {
            prefixSum += num;
            sum = prefixSum - k;

            cnt += freqPrefixMap.getOrDefault(sum, 0);

            freqPrefixMap.put(prefixSum, freqPrefixMap.getOrDefault(prefixSum, 0) + 1);
        }

        return cnt;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] array = {1, 1, 1};

        System.out.println(solution.subarraySum(array, 2));
    }
}
