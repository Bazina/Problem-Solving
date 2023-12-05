class Solution {
    public boolean isMonotonic(int[] nums) {
        if (nums.length == 1)
            return true;

        boolean isAscending = nums[0] < nums[nums.length - 1];

        for (int i = 0; i < nums.length - 1; i++) {
            if (!isAscending && nums[i] < nums[i + 1])
                return false;
            else if (isAscending && nums[i] > nums[i + 1])
                return false;
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 2, 2, 3};
        System.out.println(new Solution().isMonotonic(nums));
    }
}