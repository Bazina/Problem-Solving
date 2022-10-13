import java.util.Arrays;

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int[] ints : matrix) {
            if (target == ints[matrix[0].length - 1])
                return true;
            if (target < ints[matrix[0].length - 1]) {
                return Arrays.binarySearch(ints, target) >= 0;
            }
        }
        return false;
    }
}

public class Main {

    public static void main(String[] args) {
        int[][] matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 3;
        Solution min = new Solution();
        System.out.println(min.searchMatrix(matrix, target));
    }
}