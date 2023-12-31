class Solution {
    public int minCost(String colors, int[] neededTime) {
        char[] colorsChars = colors.toCharArray();
        int max = neededTime[0], needed = 0;

        for (int i = 1; i < colorsChars.length; i++) {
            if (colorsChars[i] == colorsChars[i - 1]) {
                needed += Math.min(neededTime[i], max);
                max = Math.max(neededTime[i], max);
            } else {
                max = neededTime[i];
            }
        }

        return needed;
    }
}

public class Main {
    public static void main(String[] args) {
        String colors = "abcdee";
        int[] neededTime = {1, 2, 3, 4, 5, 1};
        System.out.println(new Solution().minCost(colors, neededTime));
    }
}
