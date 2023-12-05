import java.util.Arrays;

class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length, diff = 0;
        int[] answer = new int[n];

        for (int num : nums)
            diff += num - nums[0];
        answer[0] = diff;

        for (int i = 1; i < n; i++) {
            int currentDiff = nums[i] - nums[i - 1];
            answer[i] = diff + currentDiff * (2 * i - n);
            diff = answer[i];
        }

        return answer;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] nums = {1, 4, 6, 8, 10};

        System.out.println(Arrays.toString(new Solution().getSumAbsoluteDifferences(nums)));
    }
}