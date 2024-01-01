import java.util.Arrays;

class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;
        int[][] newImg = new int[m][n];
        int[] dx = {0, 0, 1, 1, 1, -1, -1, -1, 0};
        int[] dy = {1, -1, 1, -1, 0, 1, -1, 0, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int k = 0; k < dx.length; k++) {
                    int nextI = dx[k] + i;
                    int nextJ = dy[k] + j;
                    if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) continue;
                    count++;
                    newImg[i][j] += img[nextI][nextJ];
                }
                newImg[i][j] /= count;
            }
        }

        return newImg;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] img = {
                {100, 200, 100},
                {200, 50, 200},
                {100, 200, 100}
        };
        System.out.println(Arrays.deepToString(new Solution().imageSmoother(img)));
    }
}