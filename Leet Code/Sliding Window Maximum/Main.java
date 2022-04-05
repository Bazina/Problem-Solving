import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int i = 0;
        int[] result = new int[nums.length - k + 1];
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> tempPriorityQueue = new PriorityQueue<>(Collections.reverseOrder());

        for (int l = 0; l < nums.length; l++) {
            if (l - k >= 0)
                if (priorityQueue.peek() == nums[l - k])
                    priorityQueue.remove();
                else
                    tempPriorityQueue.add(nums[l - k]);

            priorityQueue.add(nums[l]);

            while (!tempPriorityQueue.isEmpty() && tempPriorityQueue.peek().equals(priorityQueue.peek())) {
                tempPriorityQueue.poll();
                priorityQueue.poll();
            }

            if (priorityQueue.size() == k || l - k >= 0)
                result[i++] = priorityQueue.peek();
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] array = {7, -7};

        System.out.println(Arrays.toString(solution.maxSlidingWindow(array, 1)));
    }
}
