import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(o -> o[1]));
        int cnt = 1, j = 0;

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[j][1] <= intervals[i][0]) {
                cnt++;
                j = i;
            }
        }

        return intervals.length - cnt;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] intervals = {{1, 2}, {1, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 6}, {6, 8}, {7, 8}};
        System.out.println(new Solution().eraseOverlapIntervals(intervals));
    }
}