import java.util.Arrays;

class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length, answer = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0 && i > 0)
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        for (int[] ints : matrix) {
            Arrays.sort(ints);

            for (int j = 0; j < n; j++)
                answer = Math.max(answer, ints[j] * (n - j));
        }

        return answer;
    }
}

public class Main {

    public static void main(String[] args) {
        int[][] matrix = {
                {0, 0, 1},
                {1, 1, 1},
                {1, 0, 1}
        };

        System.out.println(new Solution().largestSubmatrix(matrix));
    }
}