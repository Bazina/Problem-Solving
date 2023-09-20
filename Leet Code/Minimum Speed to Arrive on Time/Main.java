class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        if (dist.length - 1 + 1e-7 > hour)
            return -1;

        int l = 0, r = 1;

        while (!checkGood(dist, hour, r)) r *= 2;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (checkGood(dist, hour, mid))
                r = mid;
            else
                l = mid;
        }
        return checkGood(dist, hour, r) ? r : -1;
    }

    private boolean checkGood(int[] dist, double hour, int speed) {
        double totalTime = 0;
        for (int i = 0; i < dist.length; i++) {
            double time = (double) dist[i] / speed;
            if (i == dist.length - 1)
                totalTime += time;
            else
                totalTime += Math.ceil(time);
        }

        return totalTime <= hour;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] dist = {1, 1};
        double hour = 1.0;
        System.out.println(new Solution().minSpeedOnTime(dist, hour));
    }
}