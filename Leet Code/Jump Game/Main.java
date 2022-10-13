class Solution {
    public boolean canJump(int[] nums) {
        int e = nums[nums.length - 1];
        for (int i = nums.length - 1; i >= 0; i--)
            if (i + nums[i] >= e)
                e = i;

        return e == 0;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {3, 2, 2, 0, 4};
        Solution min = new Solution();
        System.out.println(min.canJump(nums));
    }
}