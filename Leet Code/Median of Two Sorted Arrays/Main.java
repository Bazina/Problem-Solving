class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int totalSize = nums1.length + nums2.length;
        int medianIdx = totalSize / 2;

        if (nums1.length > nums2.length) {
            var dummy = nums1;
            nums1 = nums2;
            nums2 = dummy;
        }

        int l = 0, r = nums1.length - 1;

        while (true) {
            int mid1 = (l + r) / 2;
            if (l + r < 0 && (l + r) % 2 != 0)
                mid1 = (l + r - 1) / 2;

            int mid2 = medianIdx - mid1 - 2;

            int medianNums1 = (mid1 < 0) ? Integer.MIN_VALUE : nums1[mid1];
            int medianNums2 = (mid2 < 0) ? Integer.MIN_VALUE : nums2[mid2];
            int afterMedianNums1 = (mid1 + 1 >= nums1.length) ? Integer.MAX_VALUE : nums1[mid1 + 1];
            int afterMedianNums2 = (mid2 + 1 >= nums2.length) ? Integer.MAX_VALUE : nums2[mid2 + 1];

            if (medianNums1 <= afterMedianNums2 && medianNums2 <= afterMedianNums1) {
                if (totalSize % 2 == 0) {
                    return (Math.max(medianNums1, medianNums2) + Math.min(afterMedianNums1, afterMedianNums2)) / 2.0;
                } else {
                    return Math.min(afterMedianNums1, afterMedianNums2);
                }
            } else if (medianNums2 > afterMedianNums1)
                l = mid1 + 1;
            else
                r = mid1 - 1;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {1, 3};
        int[] nums2 = {};
        System.out.println(new Solution().findMedianSortedArrays(nums1, nums2));
    }
}