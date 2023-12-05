import java.util.Arrays;

class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int[] takenTimeToReachCity = new int[dist.length];
        int killed = 0;

        for (int i = 0; i < dist.length; i++)
            takenTimeToReachCity[i] = (int) Math.ceil((double) dist[i] / speed[i]);

        Arrays.sort(takenTimeToReachCity);

        for (int time = 0; time < takenTimeToReachCity.length; time++) {
            int monsterTime = takenTimeToReachCity[time];
            if (monsterTime <= time)
                break;

            killed++;
        }

        return killed;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] dist = {1, 3, 4};
        int[] speed = {1, 1, 1};
        System.out.println(new Solution().eliminateMaximum(dist, speed));
    }
}

/* O(n * log n)
import java.util.PriorityQueue;

class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int time = 0;
        int killed = 0;
        boolean charged = true;

        for (int i = 0; i < dist.length; i++) {
            int takenTimeToReachCity = (int) Math.ceil((double) dist[i] / speed[i]);
            pq.add(takenTimeToReachCity);
        }

        while (!pq.isEmpty()) {
            double monsterTime = pq.poll();
            if (charged) {
                killed++;
                time++;
                charged = false;
            } else if (time < monsterTime) {
                killed++;
                time++;
            } else {
                return killed;
            }
        }

        return killed;
    }
}
 */