import java.util.Arrays;

class Solution {
    private int binarySearchLastIndex(int[] nums, int target) {
        int l = -1, r = nums.length;

        while (l + 1 < r) {
            int mid = (l + r) / 2;

            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }

    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[]{binarySearchLastIndex(nums, target - 1) + 1, binarySearchLastIndex(nums, target)};

        if (ans[0] > ans[1])
            ans = new int[]{-1, -1};

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        int target = 8;
        int[] nums = {5, 7, 7, 8, 8, 10};
        System.out.println(Arrays.toString(new Solution().searchRange(nums, target)));
    }
}