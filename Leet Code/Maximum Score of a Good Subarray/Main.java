class Solution {
    public int maximumScore(int[] nums, int k) {
        int l = k, r = k, n = nums.length;
        int maxScore = nums[k], minValue = nums[k], leftElement, rightElement;

        while (l - 1 >= 0 || r + 1 < n) {
            leftElement = (l - 1 >= 0) ? nums[l - 1] : 0;
            rightElement = (r + 1 < n) ? nums[r + 1] : 0;
            if (leftElement > rightElement) {
                minValue = Math.min(nums[--l], minValue);
            } else {
                minValue = Math.min(nums[++r], minValue);
            }
            maxScore = Math.max(maxScore, minValue * (r - l + 1));
        }

        return maxScore;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 4, 3, 7, 4, 5};
        int k = 3;
        System.out.println(new Solution().maximumScore(nums, k));
    }
}