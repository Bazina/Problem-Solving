import java.util.Arrays;

class Graph {
    int[][] dp = new int[101][101];
    int BIG = (int) 1e9;
    int n;

    public Graph(int n, int[][] edges) {
        this.n = n;
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], BIG);
            dp[i][i] = 0;
        }

        for (int[] edge : edges)
            dp[edge[0]][edge[1]] = edge[2];

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    public void addEdge(int[] edge) {
        int from = edge[0], to = edge[1], cost = edge[2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = Math.min(dp[i][j], dp[i][from] + dp[to][j] + cost);
            }
        }
    }

    public int shortestPath(int node1, int node2) {
        if (dp[node1][node2] == BIG)
            return -1;
        return dp[node1][node2];
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 4;
        int[][] edges = new int[][]{
                {0, 2, 5},
                {0, 1, 2},
                {1, 2, 1},
                {3, 0, 3}
        };
        Graph obj = new Graph(n, edges);

        int[] edge = new int[]{1, 3, 4};
        obj.addEdge(edge);

        int shortestPath = obj.shortestPath(0, 3);
        System.out.println(shortestPath);
    }
}

/* Dijkstra O((E + V) log V)
import java.util.*;

class Graph {
    List<List<int[]>> adjacencyList = new ArrayList<>();

    public Graph(int n, int[][] edges) {
        for (int i = 0; i < n; i++)
            adjacencyList.add(new ArrayList<>());

        for (int[] edge : edges)
            addEdge(edge);
    }

    public void addEdge(int[] edge) {
        adjacencyList.get(edge[0]).add(new int[]{edge[1], edge[2]});
    }

    public int shortestPath(int node1, int node2) {
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(e -> e[1]));
        int[] distance = new int[adjacencyList.size()];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[node1] = 0;

        priorityQueue.add(new int[]{node1, 0});

        while (!priorityQueue.isEmpty()) {
            int[] currentElement = priorityQueue.poll();
            int currentNode = currentElement[0];
            int currentCost = currentElement[1];

            if (currentCost > distance[currentNode])
                continue;

            if (node2 == currentNode)
                return distance[currentNode];

            for (int[] neighbour : adjacencyList.get(currentNode)) {
                int newCost = neighbour[1] + currentCost;
                if (newCost < distance[neighbour[0]]) {
                    distance[neighbour[0]] = newCost;
                    priorityQueue.add(new int[]{neighbour[0], newCost});
                }
            }
        }

        return (distance[node2] != Integer.MAX_VALUE) ? distance[node2] : -1;
    }
}
 */