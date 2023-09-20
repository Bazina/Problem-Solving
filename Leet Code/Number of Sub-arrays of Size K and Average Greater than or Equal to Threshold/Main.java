class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int sum = 0, cnt = 0;
        threshold *= k;

        for (int i = 0; i < arr.length; i++) {
            if (i >= k)
                sum -= arr[i - k];

            sum += arr[i];

            if (i >= k - 1 && sum >= threshold)
                cnt++;
        }

        return cnt;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
        int k = 3;
        int threshold = 5;
        System.out.println(new Solution().numOfSubarrays(arr, k, threshold));
    }
}