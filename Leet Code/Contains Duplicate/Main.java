import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums)
            if (!set.add(num))
                return true;
        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        Solution solution = new Solution();
        System.out.println(solution.containsDuplicate(nums));
    }
}