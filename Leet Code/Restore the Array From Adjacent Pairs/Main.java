import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] restoreArray(int[][] adjacentPairs) {
        HashMap<Integer, int[]> neighbours = new HashMap<>();


        for (int[] adjacentPair : adjacentPairs) {
            int first = adjacentPair[0], second = adjacentPair[1];

            if (neighbours.containsKey(first))
                neighbours.get(first)[1] = second;
            else
                neighbours.put(first, neighbours.getOrDefault(first, new int[]{second, Integer.MIN_VALUE}));

            if (neighbours.containsKey(second))
                neighbours.get(second)[1] = first;
            else
                neighbours.put(second, neighbours.getOrDefault(second, new int[]{first, Integer.MIN_VALUE}));
        }

        int element = -1;
        int elementNeighbour = -1;
        int[] restoredArray = new int[neighbours.size()];
        for (Map.Entry<Integer, int[]> entry : neighbours.entrySet()) {
            if (entry.getValue()[1] == Integer.MIN_VALUE) {
                element = entry.getKey();
                elementNeighbour = entry.getValue()[0];
            }
        }

        int i = 0;
        while (i < restoredArray.length) {
            int temp = elementNeighbour;
            restoredArray[i++] = element;

            if (i == restoredArray.length)
                break;

            int[] arrayList = neighbours.get(elementNeighbour);
            if (arrayList.length != 1 && arrayList[0] == element)
                elementNeighbour = arrayList[1];
            else
                elementNeighbour = arrayList[0];
            element = temp;
        }

        return restoredArray;
    }
}

public class Main {

    public static void main(String[] args) {
        int[][] adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
        System.out.println(Arrays.toString(new Solution().restoreArray(adjacentPairs)));
    }
}