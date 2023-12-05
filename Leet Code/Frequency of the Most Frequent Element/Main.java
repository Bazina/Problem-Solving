import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;

        int left = 0, target;
        int currentSum = 0;

        for (int right = 0; right < n; right++) {
            target = nums[right];
            currentSum += target;

            if (target * (right - left + 1) - currentSum > k) {
                currentSum -= nums[left++];
            }
        }

        return n - left;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] nums = {1, 4, 4, 8, 8, 8, 13};
        int k = 5;

        System.out.println(new Solution().maxFrequency(nums, k));
    }
}