class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1, area, ans = 0;
        while (i <= j) {
            area = (height[i] < height[j]) ? height[i] * (j - i) : height[j] * (j - i);
            ans = Math.max(area, ans);
            if (i < height.length - 1 && height[i] < height[j]) i++;
            else if (j > 0 && height[j] <= height[i]) j--;
            else break;
        }
        return ans;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] height = {4,3,2,1,4};
        Solution max = new Solution();
        System.out.println(max.maxArea(height));
    }
}
