import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        return recur(nums, ans, new ArrayList<>(), 0);
    }

    private List<List<Integer>> recur(int[] nums, List<List<Integer>> subsets, List<Integer> subset, int i) {
        if (i == nums.length) {
            List<Integer> dummy = new ArrayList<>(subset);
            subsets.add(dummy);
            return subsets;
        }

        subset.add(nums[i]);
        recur(nums, subsets, subset, i + 1);

        subset.remove(subset.size() - 1);
        recur(nums, subsets, subset,i + 1);

        return subsets;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        Solution solution = new Solution();
        System.out.println(solution.subsets(nums));
    }
}