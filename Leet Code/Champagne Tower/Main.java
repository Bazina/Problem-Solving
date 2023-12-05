class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[] currentLevel = new double[]{poured};
        double[] newLevel;

        for (int i = 0; i < query_row; i++) {
            newLevel = new double[i + 2];

            for (int j = 0; j <= i; j++) {
                double distributedOverflow = (currentLevel[j] - 1.0) / 2.0;

                if (distributedOverflow > 0) {
                    newLevel[j] += distributedOverflow;
                    newLevel[j + 1] += distributedOverflow;
                }
            }
            currentLevel = newLevel;
        }

        return Math.min(1, currentLevel[query_glass]);
    }
}

public class Main {
    public static void main(String[] args) {
        int poured = 100000009;
        int queryRow = 33;
        int queryGlass = 17;
        System.out.println(new Solution().champagneTower(poured, queryRow, queryGlass));
    }
}