import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int shortestPathLength(int[][] graph) {
        if (graph.length == 1)
            return 0;

        int cost = 0;
        int n = graph.length;
        int endState = (1 << n) - 1;
        boolean[][] seen = new boolean[n][endState];
        Queue<Node> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            queue.add(new Node(i, 1 << i));
            seen[i][1 << i] = true;
        }

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node currentNode = queue.poll();

                for (int neighbour : graph[currentNode.id]) {
                    int nextState = currentNode.state | (1 << neighbour);

                    if (nextState == endState)
                        return cost + 1;

                    if (!seen[neighbour][nextState]) {
                        seen[neighbour][nextState] = true;
                        queue.add(new Node(neighbour, nextState));
                    }
                }
            }
            cost++;
        }

        return -1;
    }

    static class Node {
        int id;
        int state;

        public Node(int id, int state) {
            this.id = id;
            this.state = state;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] graph = {
                {1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}
        };
        System.out.println(new Solution().shortestPathLength(graph));
    }
}