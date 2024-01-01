class Solution {
    public int maxProductDifference(int[] nums) {
        int biggest = 0, smallest = Integer.MAX_VALUE;
        int secondBiggest = 0, secondSmallest = Integer.MAX_VALUE;

        for (int num : nums) {
            if (num >= biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = Math.max(secondBiggest, num);
            }

            if (num <= smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = Math.min(secondSmallest, num);
            }
        }

        return (biggest * secondBiggest) - (smallest * secondSmallest);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {4, 2, 5, 9, 7, 4, 8};
        System.out.println(new Solution().maxProductDifference(nums));
    }
}