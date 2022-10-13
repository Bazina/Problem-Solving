import java.util.Arrays;

class Solution {
    public int maxSubArray(int[] nums) {
        int subSum = 0, bestSum = Integer.MIN_VALUE;

        for (int num : nums) {
            subSum = Math.max(num + subSum, num);

            if (bestSum < subSum)
                bestSum = subSum;
        }

        return bestSum;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {-2, -4};
        Solution solution = new Solution();
        System.out.println(solution.maxSubArray(nums));
    }
}