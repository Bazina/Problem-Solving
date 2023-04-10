import java.util.Arrays;

class Solution {
    public int candy(int[] ratings) {
        int[] candiesRL = new int[ratings.length];
        int[] candiesLR = new int[ratings.length];
        int minNumberOfCandies = 0;
        Arrays.fill(candiesLR, 1);
        Arrays.fill(candiesRL, 1);

        for (int i = 1; i < ratings.length; i++)
            if (ratings[i] > ratings[i - 1])
                candiesLR[i] = candiesLR[i - 1] + 1;

        for (int i = ratings.length - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                candiesRL[i] = candiesRL[i + 1] + 1;

        for (int i = 0; i < ratings.length; i++)
            minNumberOfCandies += Math.max(candiesLR[i], candiesRL[i]);

        return minNumberOfCandies;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] ratings = {29, 51, 87, 87, 72, 12};
        System.out.println(new Solution().candy(ratings));
    }
}