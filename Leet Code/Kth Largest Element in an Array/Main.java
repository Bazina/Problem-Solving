import java.util.Arrays;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);

        System.out.println(nums[nums.length - k]);
        return nums[nums.length - k];
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] array = {3, 2, 3, 1, 2, 4, 5, 5, 6};

        solution.findKthLargest(array, 4);
    }
}
