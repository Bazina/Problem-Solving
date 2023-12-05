import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> isArithmeticSubArrays = new ArrayList<>();
        int n = l.length;

        for (int i = 0; i < n; i++) {
            int[] copy = new int[r[i] - l[i] + 1];
            for (int j = 0; j < copy.length; j++) {
                copy[j] = nums[l[i] + j];
            }
            isArithmeticSubArrays.add(isArithmeticSubArray(copy));
        }

        return isArithmeticSubArrays;
    }

    private boolean isArithmeticSubArray(int[] nums) {
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;

        for (int element : nums) {
            if (min1 > element) {
                min2 = min1;
                min1 = element;
            } else
                min2 = Math.min(min2, element);
        }

        int diff = min2 - min1;
        int sum = diff * nums.length * (nums.length - 1) / 2;

        for (int i = 0; i < nums.length; i++) {
            int elementsDiff = nums[i] - min1;
            if ((diff == 0 && elementsDiff != 0) || (diff != 0 && elementsDiff % diff != 0))
                return false;
            sum -= elementsDiff;
        }

        return sum == 0;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] nums = {-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10}, l = {0, 1, 6, 4, 8, 7}, r = {4, 4, 9, 7, 9, 10};

        System.out.println(new Solution().checkArithmeticSubarrays(nums, l, r));
    }
}