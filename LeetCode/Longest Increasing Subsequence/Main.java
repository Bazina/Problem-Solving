import java.util.Arrays;

public class Main {

    static public void lengthOfLIS(int[] nums) {
        int ans = 1;
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            for (int j = 0; j < i; j++) {
                if (nums[j] < curr) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int sub:
             dp) {
            ans = Math.max(ans, sub);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
	    int[] nums = {10,9,2,5,3,7,101,18};
        lengthOfLIS(nums);
    }
}
