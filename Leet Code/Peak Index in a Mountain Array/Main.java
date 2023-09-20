class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (checkGood(arr, mid))
                return mid;
            else if (checkBefore(arr, mid))
                r = mid;
            else
                l = mid;
        }
        return 0;
    }

    private boolean checkGood(int[] arr, int index) {
        return (index - 1 < 0 || arr[index] > arr[index - 1]) && (index + 1 >= arr.length || arr[index] > arr[index + 1]);
    }

    private boolean checkBefore(int[] arr, int index) {
        return index - 1 >= 0 && arr[index] < arr[index - 1];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr = {0, 2, 1, 0};
        System.out.println(new Solution().peakIndexInMountainArray(arr));
    }
}