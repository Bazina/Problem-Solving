import java.util.Arrays;

class Solution {
    public int[][] transpose(int[][] matrix) {
        int[][] transposedMatrix = new int[matrix[0].length][matrix.length];

        for (int i = 0; i < matrix[0].length; i++)
            for (int j = 0; j < matrix.length; j++)
                transposedMatrix[i][j] = matrix[j][i];

        return transposedMatrix;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] matrix = {
                {2, -10, 18},
                {4, 5, -7},
        };
        System.out.println(Arrays.deepToString(new Solution().transpose(matrix)));
    }
}