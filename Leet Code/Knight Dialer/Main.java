class Solution {
    public int knightDialer(int n) {
        if (n == 1)
            return 10;

        int mod = (int) 1e9 + 7;
        long count0 = 1, count1 = 4, count2 = 2, count4 = 2;
        for (int i = 2; i <= n; i++) {
            long newCount0 = (count4) % mod;
            long newCount1 = (2 * count2 + 2 * count4) % mod;
            long newCount2 = (count1) % mod;
            long newCount4 = (2 * count0 + count1) % mod;

            count0 = newCount0;
            count1 = newCount1;
            count2 = newCount2;
            count4 = newCount4;
        }

        return (int) ((count0 + count1 + count2 + count4) % mod);
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 5000;
        System.out.println(new Solution().knightDialer(n));
    }
}