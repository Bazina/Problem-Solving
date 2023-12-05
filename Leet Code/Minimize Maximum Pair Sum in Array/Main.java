class Solution {
    public int minPairSum(int[] nums) {
        int[] frequency = new int[(int) 1e5 + 2];
        int max = 0, maxNum = 0, minNum = Integer.MAX_VALUE;

        for (int num : nums) {
            frequency[num]++;
            minNum = Math.min(num, minNum);
            maxNum = Math.max(num, maxNum);
        }

        int i = minNum, j = maxNum;

        while (i < j) {
            while (frequency[i] <= 0 && i < j)
                i++;
            while (frequency[j] <= 0 && i < j)
                j--;

            if (i == j && frequency[i] == 0)
                break;

            max = Math.max(max, i + j);
            frequency[i]--;
            frequency[j]--;
        }

        return max;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] nums = {5, 9, 8, 6, 8, 5, 10, 2, 2, 9, 7, 3, 6, 3, 8, 7, 1, 2, 9, 10};
        System.out.println(new Solution().minPairSum(nums));
    }
}