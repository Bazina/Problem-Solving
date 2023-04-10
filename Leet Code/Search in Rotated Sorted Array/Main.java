import java.util.Arrays;

class Solution {
    public int search(int[] nums, int target) {
        int leftSearch, rightSearch;
        int i = findMin(nums);
        leftSearch = Arrays.binarySearch(nums, 0, i + 1, target);
        rightSearch = Arrays.binarySearch(nums, i, nums.length, target);
        return Math.max(rightSearch, Math.max(leftSearch, -1));
    }

    private int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int ans = nums[0], idx = 0;

        while (l <= r) {
            if (nums[l] < nums[r] && ans >= nums[l])
                return l;

            int m = (l + r) / 2;
            if (nums[m] < ans) {
                idx = m;
                ans = nums[m];
            }

            if (nums[m] >= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }

        return idx;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 7;
        Solution min = new Solution();
        System.out.println(min.search(nums, target));
    }
}