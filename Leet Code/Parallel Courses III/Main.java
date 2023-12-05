import java.util.ArrayList;
import java.util.List;

class Solution {
    List<Integer>[] adjacencyList;
    int n, idx;
    int[] time, timeCost;
    int[][] relations;

    public int minimumTime(int n, int[][] relations, int[] time) {
        this.n = n;
        this.idx = n - 1;
        this.relations = relations;
        this.time = time;
        timeCost = new int[n + 1];
        adjacencyList = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        for (int[] prerequisitePair : relations) {
            adjacencyList[prerequisitePair[0]].add(prerequisitePair[1]);
        }

        for (int i = 1; i <= n; i++) {
            if (timeCost[i] == 0)
                dfs(i);
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            maxTime = Math.max(maxTime, timeCost[i]);
        }

        return maxTime;
    }

    private void dfs(int node) {
        int maxTime = 0;

        for (int child : adjacencyList[node]) {
            if (timeCost[child] == 0)
                dfs(child);
            maxTime = Math.max(maxTime, timeCost[child]);
        }

        timeCost[node] = time[node - 1] + maxTime;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 6;
        int[] time = {1, 2, 3, 4, 5, 6};
        int[][] relations = {
                {1, 5},
                {2, 5},
                {3, 5},
                {3, 4},
                {5, 4},
                {6, 3},
                {6, 5}
        };
        System.out.println(new Solution().minimumTime(n, relations, time));
    }
}

/* Kahn's Algo
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    List<Integer>[] adjacencyList;
    int n, idx;
    int[] time, inDegrees;
    int[][] relations;

    public int minimumTime(int n, int[][] relations, int[] time) {
        this.n = n;
        this.idx = n - 1;
        this.relations = relations;
        this.time = time;
        inDegrees = new int[n + 1];
        adjacencyList = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        for (int[] prerequisitePair : relations) {
            adjacencyList[prerequisitePair[0]].add(prerequisitePair[1]);
            inDegrees[prerequisitePair[1]]++;
        }

        return calculateMinTime();
    }

    private int calculateMinTime() {
        int maxTime = 0;
        int[] timeCost = new int[n + 1];
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            if (inDegrees[i] == 0) {
                queue.add(i);
                timeCost[i] = time[i - 1];
                maxTime = Math.max(maxTime, timeCost[i]);
            }
        }

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();

            for (int child : adjacencyList[currentNode]) {
                inDegrees[child]--;
                timeCost[child] = Math.max(timeCost[child], timeCost[currentNode] + time[child - 1]);
                if (inDegrees[child] == 0) {
                    maxTime = Math.max(maxTime, timeCost[child]);
                    queue.add(child);
                }
            }
        }

        return maxTime;
    }
}
 */