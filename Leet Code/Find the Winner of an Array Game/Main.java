class Solution {
    public int getWinner(int[] arr, int k) {
        int n = arr.length;
        int max = arr[0], currentK = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
                currentK = 1;
            } else
                currentK++;

            if (currentK == k)
                return max;
        }

        return max;
    }
}

public class Main {

    public static void main(String[] args) {
        int k = 2;
        int[] arr = {2, 1, 3, 5, 4, 6, 7};
        System.out.println(new Solution().getWinner(arr, k));
    }
}