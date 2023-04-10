class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1, ans = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r] && ans >= nums[l])
                return nums[l];

            int m = (l + r) / 2;
            ans = Math.min(nums[m], ans);

            if (nums[m] >= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {4, 5, 1, 2, 3};
        System.out.println(new Solution().findMin(nums));
    }
}