import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int threshold = nums.length / 3;
        List<Integer> answer = new ArrayList<>();

        int count1 = 0, count2 = 0;
        int candidate1 = -1, candidate2 = -1;

        for (int num : nums) {
            if (count1 == 0 && candidate2 != num) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0 && candidate1 != num) {
                candidate2 = num;
                count2 = 1;
            } else if (candidate1 == num) {
                count1++;
            } else if (candidate2 == num) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (candidate1 == num)
                count1++;
            else if (candidate2 == num)
                count2++;
        }

        if (count1 > threshold)
            answer.add(candidate1);
        if (count2 > threshold)
            answer.add(candidate2);

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2, 1, 1, 3, 1, 4, 5, 6};
        System.out.println(new Solution().majorityElement(nums));
    }
}