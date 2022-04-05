import java.util.Arrays;

class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int oddCount = 1, evenCount = 0;
        int[] res = new int[nums.length];
        for (int item : nums) {
            if ((item & 1) == 1) {
                res[oddCount] = item;
                oddCount += 2;
            } else {
                res[evenCount] = item;
                evenCount += 2;
            }
        }
        return res;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] instructions = {4, 2, 5, 7};
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.sortArrayByParityII(instructions)));
    }
}
