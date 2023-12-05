import java.util.Arrays;

class Solution {
    int[] nums1, nums2;
    int[][] dp;

    public int maxDotProduct(int[] nums1, int[] nums2) {
        int firstMax = Integer.MIN_VALUE;
        int secondMax = Integer.MIN_VALUE;
        int firstMin = Integer.MAX_VALUE;
        int secondMin = Integer.MAX_VALUE;

        for (int num: nums1) {
            firstMax = Math.max(firstMax, num);
            firstMin = Math.min(firstMin, num);
        }

        for (int num: nums2) {
            secondMax = Math.max(secondMax, num);
            secondMin = Math.min(secondMin, num);
        }

        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }

        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        }

        this.nums1 = nums1;
        this.nums2 = nums2;
        this.dp = new int[nums1.length][nums2.length];
        for (int[] row : dp)
            Arrays.fill(row, Integer.MIN_VALUE);

        return recur(nums1.length - 1, nums2.length - 1);
    }

    public int recur(int i, int j) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != Integer.MIN_VALUE)
            return dp[i][j];

        int newElement = nums1[i] * nums2[j], ans;
        ans = newElement + recur(i - 1, j - 1);

        dp[i][j] = Math.max(Math.max(recur(i - 1, j), recur(i, j - 1)), ans);

        return dp[i][j];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums1 = new int[]{-1,-1};
        int[] nums2 = new int[]{1,1};
        System.out.println(new Solution().maxDotProduct(nums1, nums2));
    }
}