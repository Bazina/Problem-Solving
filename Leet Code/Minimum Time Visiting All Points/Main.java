class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int minTime = 0;
        for (int i = 0; i < points.length - 1; i++)
            minTime += Math.max(Math.abs(points[i][0] - points[i + 1][0]), Math.abs(points[i][1] - points[i + 1][1]));

        return minTime;
    }
}

public class Main {

    public static void main(String[] args) {
        int[][] points = {
                {1, 1},
                {3, 4},
                {-1, 0}
        };
        System.out.println(new Solution().minTimeToVisitAllPoints(points));
    }
}