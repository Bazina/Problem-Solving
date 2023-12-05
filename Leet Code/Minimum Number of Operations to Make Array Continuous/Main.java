import java.util.Arrays;

class Solution {
    public int minOperations(int[] nums) {
        Arrays.sort(nums);

        int uniqueIdx = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1])
                nums[uniqueIdx++] = nums[i];
        }

        int n = nums.length, newN = uniqueIdx, r = 0, maxWindow = 0, currentWindow;
        for (int l = 0; l < newN; l++) {
            int start = nums[l], end = start + n - 1;
            while (r < newN && nums[r] <= end) {
                r++;
            }

            currentWindow = r - l;
            maxWindow = Math.max(currentWindow, maxWindow);
        }

        return n - maxWindow;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {41, 33, 29, 33, 35, 26, 47, 24, 18, 28};
        System.out.println(new Solution().minOperations(nums));
    }
}