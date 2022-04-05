class Solution {

    public int trap(int[] height) {
        int l = 0, r = height.length - 1, ans = 0;
        int l_max = 0, r_max = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= l_max) l_max = height[l];
                else ans += l_max - height[l];
                l++;
            } else {
                if (height[r] >= r_max) r_max = height[r];
                else ans += r_max - height[r];
                r--;
            }
        }
        return ans;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        Solution min = new Solution();
        System.out.println(min.trap(height));
    }
}