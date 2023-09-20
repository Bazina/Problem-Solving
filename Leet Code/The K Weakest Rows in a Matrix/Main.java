import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> counting = new PriorityQueue<>(mat.length, (a, b) -> {
            if (a[0] != b[0])
                return Integer.compare(a[0], b[0]);
            else
                return Integer.compare(a[1], b[1]);
        });
        int[] kWeakestRows = new int[k];

        for (int i = 0; i < mat.length; i++) {
            int lastSoldierIndex = findLastSolider(mat[i]);
            counting.add(new int[]{lastSoldierIndex + 1, i});
        }

        int count = 0;
        while (count < k && !counting.isEmpty()) {
            kWeakestRows[count++] = counting.poll()[1];
        }

        return kWeakestRows;
    }

    private int findLastSolider(int[] mat) {
        int l = 0, r = mat.length - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (mat[mid] == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] mat = {
                {1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}
        };
        int k = 3;
        System.out.println(Arrays.toString(new Solution().kWeakestRows(mat, k)));
    }
}