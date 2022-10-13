class Solution {

    public int divideConquer(int l, int r, String colors, int[] neededTime) {
        if (l - r == 0)
            return 0;

        int mid = (l + r) / 2;


    }

    public int minCost(String colors, int[] neededTime) {
        return divideConquer(0, colors.length() - 1, colors, neededTime);
    }
}

public class Main {
    public static void main(String[] args) {
        String colors = "aabaa";
        int[] neededTime = {1, 2, 3, 4, 1};
        Solution solution = new Solution();
        System.out.println(solution.minCost(colors, neededTime));
    }
}