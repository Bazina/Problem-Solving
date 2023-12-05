import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target)
            return 0;

        HashMap<Integer, ArrayList<Integer>> adjacencyList = new HashMap<>();

        for (int i = 0; i < routes.length; i++) {
            int[] route = routes[i];
            for (int busStop : route) {
                if (!adjacencyList.containsKey(busStop))
                    adjacencyList.put(busStop, new ArrayList<>());
                adjacencyList.get(busStop).add(i);
            }
        }

        if (!adjacencyList.containsKey(source) || !adjacencyList.containsKey(target))
            return -1;

        Queue<Integer> bfsQueue = new LinkedList<>();
        HashSet<Integer> visitedStop = new HashSet<>();
        HashSet<Integer> visitedRoute = new HashSet<>();

        int cost = 1;
        bfsQueue.add(source);
        visitedStop.add(source);

        while (!bfsQueue.isEmpty()) {
            int size = bfsQueue.size();

            for (int i = 0; i < size; i++) {
                int currentNode = bfsQueue.poll();

                for (int route : adjacencyList.get(currentNode)) {
                    if (visitedRoute.contains(route))
                        continue;
                    visitedRoute.add(route);

                    for (int busStop : routes[route]) {
                        if (visitedStop.contains(busStop))
                            continue;

                        if (busStop == target)
                            return cost;

                        bfsQueue.add(busStop);
                        visitedStop.add(busStop);
                    }
                }
            }
            cost++;
        }

        return -1;
    }
}

public class Main {

    public static void main(String[] args) {
        int source = 1;
        int target = 10;
        int[][] routes = {{1, 7, 5, 10}, {10, 2}, {2, 1}};
        System.out.println(new Solution().numBusesToDestination(routes, source, target));
    }
}

/* O(M^2 * K)
import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target)
            return 0;

        HashMap<Integer, ArrayList<int[]>> adjacencyList = new HashMap<>();
        HashMap<Integer, HashSet<Integer>> routesMap = new HashMap<>();
        HashMap<Integer, Boolean> visited = new HashMap<>();

        for (int i = 0; i < routes.length; i++) {
            int[] route = routes[i];
            HashSet<Integer> busStopsSet = new HashSet<>();
            for (int j = 0; j < route.length; j++) {
                busStopsSet.add(route[j]);
                addEdge(adjacencyList, route, j, i);
            }
            routesMap.put(i, busStopsSet);
        }

        Queue<int[]> bfsQueue = new LinkedList<>();
        for (int[] busStop : adjacencyList.getOrDefault(source, new ArrayList<>())) {
            bfsQueue.add(new int[]{busStop[0], 1, busStop[1]});
        }

        while (!bfsQueue.isEmpty()) {
            int[] currentElement = bfsQueue.poll();
            int currentNode = currentElement[0];
            int currentCost = currentElement[1];
            int currentRoute = currentElement[2];

            visited.put(currentNode, true);

            if (currentNode == target || routesMap.get(currentRoute).contains(target))
                return currentCost;

            for (int[] busStop : adjacencyList.getOrDefault(currentNode, new ArrayList<>())) {
                if (visited.getOrDefault(busStop[0], false))
                    continue;

                int newCost = currentCost;
                int newRoute = busStop[1];
                if (newRoute != currentRoute) {
                    newCost++;
                }

                bfsQueue.add(new int[]{busStop[0], newCost, newRoute});
            }
        }

        return -1;
    }
 */