class Solution {
    public int maxCoins(int[] piles) {
        int[] frequency = new int[10004];
        int maxCoins = 0, maxCoin = 0;

        for (int pile : piles) {
            maxCoin = Math.max(maxCoin, pile);
            frequency[pile]++;
        }

        int i = maxCoin, round = piles.length / 3;
        boolean isMe = false;
        while (round > 0) {
            if (frequency[i] > 0) {
                if (isMe) {
                    maxCoins += i;
                    round--;
                }
                frequency[i]--;
                isMe = !isMe;
            } else
                i--;
        }

        return maxCoins;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] piles = {2, 4, 1, 2, 7, 8};

        System.out.println(new Solution().maxCoins(piles));
    }
}

/* O(N * log n)
import java.util.Arrays;

class Solution {
    public int maxCoins(int[] piles) {
        int maxCoins = 0;
        Arrays.sort(piles);

        int i = piles.length - 1, j = 0;
        while (i > j) {
            maxCoins += piles[i - 1];
            i -= 2;
            j++;
        }

        return maxCoins;
    }
}
 */