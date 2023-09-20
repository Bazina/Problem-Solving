class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length][nums.length];

        for (int j = 0; j < nums.length; j++)
            for (int k = 0; k < nums.length; k++)
                dp[j][k] = -1;

        return recur(dp, nums, 0, nums.length - 1) >= 0;
    }

    private int recur(int[][] dp, int[] nums, int start, int end) {
        if (start == end)
            return nums[end];

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans1 = nums[start] - recur(dp, nums, start + 1, end);
        int ans2 = nums[end] - recur(dp, nums, start, end - 1);

        return dp[start][end] = Math.max(ans1, ans2);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 5, 2};
        System.out.println(new Solution().PredictTheWinner(nums));
    }
}