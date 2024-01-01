import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(a -> a[0]));

        int ans = 0;
        for (int i = 1; i < points.length; i++)
            ans = Math.max(ans, points[i][0] - points[i - 1][0]);

        return ans;
    }
}


public class Main {
    public static void main(String[] args) {
        int[][] points = {
                {8, 7},
                {9, 9},
                {7, 4},
                {9, 7}
        };
        System.out.println(new Solution().maxWidthOfVerticalArea(points));
    }
}