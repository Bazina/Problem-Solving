class MountainArray {
    private final int[] mountainArray;

    public MountainArray(int[] mountainArray) {
        this.mountainArray = mountainArray;
    }

    public int get(int index) {
        return mountainArray[index];
    }

    public int length() {
        return mountainArray.length;
    }
}

class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peakIdx = findPeak(mountainArr, 0, mountainArr.length() - 1);

        int binarySearchLeft = binarySearch(mountainArr, target, 0, peakIdx, 1);

        if (binarySearchLeft != -1)
            return binarySearchLeft;

        return binarySearch(mountainArr, target, peakIdx, mountainArr.length() - 1, -1);
    }

    private int findPeak(MountainArray array, int l, int r) {
        while (l < r) {
            int mid = (l + r) / 2;
            int element = array.get(mid);
            int nextElement = array.get(mid + 1);

            if (element > nextElement) {
                r = mid;
            } else
                l = mid + 1;
        }

        return l;
    }

    private int binarySearch(MountainArray array, int target, int l, int r, int reverse) {
        while (l <= r) {
            int mid = (l + r) / 2;
            int element = array.get(mid);

            if (element == target)
                return mid;
            else if (element * reverse < target * reverse) {
                l = mid + 1;
            } else
                r = mid - 1;
        }

        return -1;
    }
}

public class Main {
    public static void main(String[] args) {
        int target = 0;
        MountainArray mountainArr = new MountainArray(new int[]{1, 5, 2});
        System.out.println(new Solution().findInMountainArray(target, mountainArr));
    }
}