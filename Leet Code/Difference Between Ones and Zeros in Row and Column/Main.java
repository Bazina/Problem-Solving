import java.util.Arrays;

class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int[] columnPrefix = new int[grid[0].length];
        int[] rowPrefix = new int[grid.length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int add = grid[i][j] == 0 ? -1 : 1;
                columnPrefix[j] += add;
                rowPrefix[i] += add;
            }
        }

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                grid[i][j] = columnPrefix[j] + rowPrefix[i];
            }
        }

        return grid;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] grid = {
                {0,1,1},
                {1,0,1},
                {0,0,1}
        };
        System.out.println(Arrays.deepToString(new Solution().onesMinusZeros(grid)));
    }
}