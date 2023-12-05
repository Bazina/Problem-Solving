import java.util.HashMap;

class Solution {
    public int countNicePairs(int[] nums) {
        HashMap<Integer, Integer> frequency = new HashMap<>();
        int pairsCount = 0, mod = (int) 1e9 + 7;

        for (int i = 0; i < nums.length; i++) {
            int num = nums[i], reversed = 0, copyNum = nums[i];

            while(copyNum != 0) {
                int digit = copyNum % 10;
                reversed = reversed * 10 + digit;

                copyNum /= 10;
            }

            int diff = num - reversed;
            int diffFreq = frequency.getOrDefault(diff, 0);
            frequency.put(num - reversed, diffFreq + 1);
            pairsCount = (pairsCount + diffFreq) % mod;
        }

        return pairsCount;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] nums = {13, 10, 35, 24, 76};
        System.out.println(new Solution().countNicePairs(nums));
    }
}