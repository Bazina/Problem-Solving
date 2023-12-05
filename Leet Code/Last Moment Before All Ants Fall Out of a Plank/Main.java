class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int maxTime = 0;

        for (int k : left)
            maxTime = Math.max(maxTime, k);

        for (int j : right)
            maxTime = Math.max(maxTime, n - j);

        return maxTime;
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 20;
        int[] left = {4, 7, 15}, right = {9, 3, 13, 10};
        System.out.println(new Solution().getLastMoment(n, left, right));
    }
}