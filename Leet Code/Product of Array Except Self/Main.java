import java.util.Arrays;

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int[] prefix = new int[nums.length + 1];
        int[] postfix = new int[nums.length + 1];
        postfix[nums.length] = prefix[0] = 1;

        for (int i = 1; i <= nums.length; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];
        for (int i = nums.length - 1; i >= 0; i--)
            postfix[i] = postfix[i + 1] * nums[i];

        for (int i = 0; i < nums.length; i++)
            ans[i] = postfix[i + 1] * prefix[i];

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4};
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.productExceptSelf(nums)));
    }
}