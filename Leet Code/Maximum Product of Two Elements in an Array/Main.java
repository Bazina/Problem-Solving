class Solution {
    public int maxProduct(int[] nums) {
        int biggest = 0;
        int secondBiggest = 0;

        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = Math.max(secondBiggest, num);
            }
        }

        return (biggest - 1) * (secondBiggest - 1);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {3, 4, 5, 2};
        System.out.println(new Solution().maxProduct(nums));
    }
}