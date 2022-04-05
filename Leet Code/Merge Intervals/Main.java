import java.util.Arrays;
import java.util.LinkedList;

class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0)
            return intervals;

        int start = 0;
        int end = 0;
        for (int[] interval : intervals) {
            start = Math.min(start, interval[0]);
            end = Math.max(end, interval[1]);
        }

        LinkedList<int[]> newIntervals = new LinkedList<>();
        int[] startPoints = new int[end + 1], endPoints = new int[end + 1];

        for (int[] interval : intervals) {
            startPoints[interval[0]]++;
            endPoints[interval[1]]--;
        }

        int currentIntervalStart = 0, currentInterval = 0;

        for (int i = start; i < startPoints.length; i++) {
            int overlap = startPoints[i] + endPoints[i];

            if (startPoints[i] > 0 && endPoints[i] < 0)
                if (currentInterval == 0 && overlap == 0)
                    newIntervals.add(new int[]{i, i});

            if (overlap > 0) {
                if (currentInterval == 0)
                    currentIntervalStart = i;
                currentInterval += overlap;
            } else if (overlap < 0) {
                currentInterval += overlap;
                if (currentInterval == 0)
                    newIntervals.add(new int[]{currentIntervalStart, i});
            }
        }

        return newIntervals.toArray(new int[newIntervals.size()][]);
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] intervals = {{1, 4}, {0, 2}, {3, 5}};
        Solution solution = new Solution();
        System.out.println(Arrays.deepToString(solution.merge(intervals)));
    }
}

/* Another Solution using Sorting (slower)
class Solution {
    public int[][] merge(int[][] intervals) {
        ArrayList<int[]> newIntervals = new ArrayList<>();

        if (intervals.length == 1) {
            newIntervals.add(intervals[0]);
            return newIntervals.toArray(new int[newIntervals.size()][]);
        }

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0])
                return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        for (int i = 0; i < intervals.length - 1; i++) {
            int start = intervals[i][0], end = intervals[i][1];

            for (; i < intervals.length - 1 && intervals[i + 1][0] <= end; i++)
                end = Math.max(end, intervals[i + 1][1]);

            newIntervals.add(new int[]{start, end});
        }

        if (newIntervals.get(newIntervals.size() - 1)[1] < intervals[intervals.length - 1][0])
            newIntervals.add(intervals[intervals.length - 1]);

        return newIntervals.toArray(new int[0][]);
    }
}
 */