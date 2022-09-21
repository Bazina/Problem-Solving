import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numsMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int lookFor = target - nums[i];
            Integer lookForIdx = numsMap.get(lookFor);

            if (lookForIdx != null)
                return new int[]{i, lookForIdx};
            numsMap.put(nums[i], i);
        }
        return new int[]{0, 0};
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.twoSum(nums, target)));
    }
}

/* Another Solution
class Solution {
    public int[] twoSum(int[] nums, int target) {
        List<Pair<Integer, Integer>> numbers = new ArrayList<>();
        for (int i = 0; i < nums.length; i++)
            numbers.add(new Pair<>(nums[i], i));

        numbers.sort(Comparator.comparing(Pair::getKey));

        int i = 0, j = nums.length - 1;

        while (i < j) {
            if (numbers.get(i).getKey() + numbers.get(j).getKey() > target)
                j--;
            else if (numbers.get(i).getKey() + numbers.get(j).getKey() < target)
                i++;
            else
                return new int[]{numbers.get(i).getValue(), numbers.get(j).getValue()};
        }
        return new int[]{numbers.get(i).getValue(), numbers.get(j).getValue()};
    }
}
 */