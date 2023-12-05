class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        int ans = 1, n = arr.length;
        int[] count = new int[n + 1];

        for (int j : arr) count[Math.min(n, j)]++;

        for (int i = 2; i <= n; i++)
            ans = Math.min(ans + count[i], i);

        return ans;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println(new Solution().maximumElementAfterDecrementingAndRearranging(arr));
    }
}