class Solution {
    public int reductionOperations(int[] nums) {
        int[] frequency = new int[50001];
        int maxNum = 0, minNum = Integer.MAX_VALUE;

        for (int num : nums) {
            frequency[num]++;
            minNum = Math.min(num, minNum);
            maxNum = Math.max(num, maxNum);
        }

        int i = minNum, j = maxNum, numberOfOps = 0, previous = 0;

        while (i != j) {
            while (frequency[j] <= 0 && i < j)
                j--;

            if (i == j)
                break;

            numberOfOps += frequency[j] + previous;
            previous += frequency[j--];
        }

        return numberOfOps;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] nums = {7, 9, 10, 8, 6, 4, 1, 5, 2, 3};
        System.out.println(new Solution().reductionOperations(nums));
    }
}