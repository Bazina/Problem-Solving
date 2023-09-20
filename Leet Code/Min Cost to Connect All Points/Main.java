import java.util.Arrays;

class Solution {
    private static boolean isValidEdge(int[] distances, boolean[] mstVisited, int j, int[] adjacencyMatrix) {
        return adjacencyMatrix[j] > 0 && !mstVisited[j] && distances[j] > adjacencyMatrix[j];
    }

    private void buildGraph(int[][] points, int[][] adjacencyMatrix, int[] distances) {
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[0] = 0;

        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                adjacencyMatrix[i][j] = calculateDistance(points[i], points[j]);
            }
        }
    }

    private int calculateDistance(int[] point1, int[] point2) {
        return Math.abs(point1[0] - point2[0]) + Math.abs(point1[1] - point2[1]);
    }

    private int getMinimumVertex(int[] distances, boolean[] mstVisited) {
        int minDistance = Integer.MAX_VALUE;
        int vertex = -1;

        for (int i = 0; i < distances.length; i++) {
            if (!mstVisited[i] && minDistance > distances[i]) {
                minDistance = distances[i];
                vertex = i;
            }
        }

        return vertex;
    }

    private int primAlgorithm(int[][] adjacencyMatrix, int[] distances, boolean[] mstVisited, int numberOfVertices) {
        int[] costs = new int[numberOfVertices];

        for (int i = 0; i < numberOfVertices; i++) {
            int nextVertex = getMinimumVertex(distances, mstVisited);
            mstVisited[nextVertex] = true;

            for (int j = 0; j < numberOfVertices; j++) {
                if (isValidEdge(distances, mstVisited, j, adjacencyMatrix[nextVertex])) {
                    distances[j] = adjacencyMatrix[nextVertex][j];
                    costs[j] = distances[j];
                }
            }
        }
        return Arrays.stream(costs).sum();
    }

    public int minCostConnectPoints(int[][] points) {
        int[][] adjacencyMatrix = new int[points.length][points.length];
        int[] distances = new int[points.length];
        boolean[] mstVisited = new boolean[points.length];

        buildGraph(points, adjacencyMatrix, distances);

        return primAlgorithm(adjacencyMatrix, distances, mstVisited, points.length);
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] points = {
                {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
        };
        System.out.println(new Solution().minCostConnectPoints(points));
    }
}