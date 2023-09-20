import java.util.Arrays;

class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] nums2 = new int[2 * nums.length];
        for (int i = 0; i < nums.length; i++) {
            nums2[i] = nums2[i + nums.length] = nums[i];
        }

        return nums2;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 3, 1, 2, 0, 5};

        System.out.println(Arrays.toString(new Solution().getConcatenation(nums)));
    }
}
