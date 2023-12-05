class Solution {
    public int numIdenticalPairs(int[] nums) {
        int[] numFrequency = new int[101];
        int goodPairs = 0;

        for (int currentNum : nums) {
            numFrequency[currentNum]++;

            if (numFrequency[currentNum] > 1)
                goodPairs += numFrequency[currentNum] - 1;
        }

        return goodPairs;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 1, 1, 3};
        System.out.println(new Solution().numIdenticalPairs(nums));
    }
}