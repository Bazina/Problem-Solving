class Solution {
    char[][] board;
    String word;

    int n, m;
    int[] dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
    boolean[][] visited;

    public boolean exist(char[][] board, String word) {
        this.word = word;
        this.board = board;
        this.n = board.length;
        this.m = board[0].length;
        this.visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word.charAt(0))
                    if (dfs(i, j, 0))
                        return true;
            }
        }

        return false;
    }

    private boolean dfs(int i, int j, int k) {
        if (k + 1 == word.length())
            return true;

        visited[i][j] = true;

        boolean exist = false;
        for (int l = 0; l < 4; l++) {
            int newI = i + dx[l];
            int newJ = j + dy[l];

            if (newI < 0 || newI >= n || newJ < 0 || newJ >= m)
                continue;

            char nextChar = board[newI][newJ];

            if (!visited[newI][newJ] && nextChar == word.charAt(k + 1))
                exist = dfs(newI, newJ, k + 1);

            if (exist) break;
        }
        visited[i][j] = false;

        return exist;
    }
}

public class Main {
    public static void main(String[] args) {
        char[][] board = new char[][]{
                {'A', 'A'}
        };
        String word = "AAA";
        System.out.println(new Solution().exist(board, word));
    }
}