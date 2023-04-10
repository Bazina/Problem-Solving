class Solution {
    public int jump(int[] nums) {
        int[] dist = new int[nums.length];
        int next = 1, prev = 0;

        while (next < nums.length) {
            int mx = 0, val = 0, idx = 0;
            for (int i = prev; i < next; i++) {
                if (nums[i] + i >= mx) {
                    mx = nums[i] + i;
                    val = nums[i];
                    idx = i;
                }
            }
            prev = next;
            dist[next] = 1;
            next = val + idx + 1;
        }

        for (int i = 1; i < dist.length; i++) {
            dist[i] += dist[i - 1];
        }

        return dist[nums.length - 1];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
        Solution min = new Solution();
        System.out.println(min.jump(nums));
    }
}