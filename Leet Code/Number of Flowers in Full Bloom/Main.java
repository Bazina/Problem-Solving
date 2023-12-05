import java.util.Arrays;

class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int[] start = new int[flowers.length], end = new int[flowers.length];
        int[] answer = new int[people.length];

        int i = 0;
        for (int[] flower : flowers) {
            start[i] = flower[0];
            end[i++] = flower[1];
        }

        Arrays.sort(start);
        Arrays.sort(end);

        for (int j = 0; j < people.length; j++) {
            int lastStartBloomTime = upperBoundBloom(start, people[j]);
            int lastEndBloomTime = lowerBoundBloom(end, people[j]);

            answer[j] = lastStartBloomTime - lastEndBloomTime;
        }

        return answer;
    }

    private int upperBoundBloom(int[] time, int personArrival) {
        int l = 0, r = time.length;

        while (l < r) {
            int mid = (l + r) / 2;

            if (time[mid] <= personArrival)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    private int lowerBoundBloom(int[] time, int personArrival) {
        int l = 0, r = time.length;

        while (l < r) {
            int mid = (l + r) / 2;

            if (time[mid] < personArrival)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] flowers = new int[][]{
                {1, 6},
                {3, 7},
                {9, 12},
                {4, 13},
        };
        int[] people = new int[]{2, 3, 7, 11};
        System.out.println(Arrays.toString(new Solution().fullBloomFlowers(flowers, people)));
    }
}

/* sweep line
import java.util.Arrays;
import java.util.TreeMap;

class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        TreeMap<Integer, Integer> mapPrefix = new TreeMap<>();
        int[] answer = new int[people.length];

        for (int[] flower : flowers) {
            int start = flower[0], end = flower[1];
            mapPrefix.put(start, mapPrefix.getOrDefault(start, 0) + 1);
            mapPrefix.put(end + 1, mapPrefix.getOrDefault(end + 1, 0) - 1);
        }

        int i = 0;
        int[] prefix = new int[mapPrefix.size()], time = new int[mapPrefix.size()];
        for (var entry : mapPrefix.entrySet()) {
            time[i] = entry.getKey();
            prefix[i] = entry.getValue();
            if (i > 0)
                prefix[i] += prefix[i - 1];
            i++;
        }

        for (int j = 0; j < people.length; j++) {
            int idx = upperBoundBloom(time, people[j]) - 1;
            if (idx < 0)
                continue;
            answer[j] = prefix[idx];
        }

        return answer;
    }

    private int upperBoundBloom(int[] time, int personArrival) {
        int l = 0, r = time.length;

        while (l < r) {
            int mid = (l + r) / 2;

            if (time[mid] <= personArrival)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
}
 */