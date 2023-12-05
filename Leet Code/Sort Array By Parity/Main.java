import java.util.Arrays;

class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int[] sortedNums = new int[nums.length];
        int l = 0, r = nums.length - 1;

        for (int num : nums) {
            if ((num & 1) == 0)
                sortedNums[l++] = num;
            else
                sortedNums[r--] = num;
        }

        return sortedNums;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {3, 1, 2, 4};
        System.out.println(Arrays.toString(new Solution().sortArrayByParity(nums)));
    }
}