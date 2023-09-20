import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    int rows, columns;

    public int minimumEffortPath(int[][] heights) {
        return dijkstra(heights);
    }

    private void dfs(int[][] heights, boolean[][] visited, int limitEffort, int x, int y) {
        if (visited[x][y])
            return;
        visited[x][y] = true;

        if (x == rows - 1 && y == columns - 1)
            return;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= rows || newY < 0 || newY >= columns)
                continue;

            int newEffort = Math.abs(heights[x][y] - heights[newX][newY]);

            if (newEffort <= limitEffort)
                dfs(heights, visited, limitEffort, newX, newY);
        }
    }

    // Solution with binary search m * n log(10^6)
    private int binarySearch(int[][] heights) {
        rows = heights.length;
        columns = heights[0].length;

        boolean[][] visited = new boolean[rows][columns];

        int l = 0, r = 1000000;
        while (l < r) {
            int mid = (l + r) / 2;

            for (boolean[] booleans : visited)
                Arrays.fill(booleans, false);

            dfs(heights, visited, mid, 0, 0);

            if (visited[rows - 1][columns - 1])
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    // Solution with binary search m * n log(m * n)
    private int dijkstra(int[][] heights) {
        rows = heights.length;
        columns = heights[0].length;

        int[][] efforts = new int[rows][columns];
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(a -> a.effort));
        priorityQueue.add(new Node(0, 0, 0));

        for (int i = 0; i < rows; i++)
            Arrays.fill(efforts[i], Integer.MAX_VALUE);
        efforts[0][0] = 0;

        while (!priorityQueue.isEmpty()) {
            Node currentNode = priorityQueue.poll();

            if (currentNode.effort < efforts[currentNode.x][currentNode.y])
                continue;

            if (currentNode.x == rows - 1 && currentNode.y == columns - 1)
                return currentNode.effort;

            for (int i = 0; i < 4; i++) {
                int newX = currentNode.x + dx[i];
                int newY = currentNode.y + dy[i];

                if (newX < 0 || newX >= rows || newY < 0 || newY >= columns)
                    continue;

                int newEffort = Math.max(Math.abs(heights[currentNode.x][currentNode.y] - heights[newX][newY]), efforts[currentNode.x][currentNode.y]);

                if (newEffort < efforts[newX][newY]) {
                    efforts[newX][newY] = newEffort;
                    priorityQueue.add(new Node(newX, newY, newEffort));
                }
            }
        }

        return efforts[rows - 1][columns - 1];
    }

    static class Node {
        int x;
        int y;
        int effort;

        public Node(int x, int y, int effort) {
            this.x = x;
            this.y = y;
            this.effort = effort;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] heights = {
                {1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}
        };
        System.out.println(new Solution().minimumEffortPath(heights));
    }
}