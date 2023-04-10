class Solution {
    public int maxProfit(int[] prices) {
        int l = 0, r = 1, mx = 0;

        while (r < prices.length) {
            int val = prices[r] - prices[l];
            if (val > 0)
                mx = Math.max(mx, val);
            else
                l = r;
            r++;
        }

        return mx;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] prices = {2, 1, 2, 1, 0, 1, 2};
        Solution min = new Solution();
        System.out.println(min.maxProfit(prices));
    }
}