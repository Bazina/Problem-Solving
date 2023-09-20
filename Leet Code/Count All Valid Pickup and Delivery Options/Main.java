class Solution {
    long mod = 1000000007;

    public int countOrders(int n) {
        long ans = 1;
        for (long i = 1; i <= n; i++) {
            ans = (ans * (i * 2 - 1) * i) % mod;
        }
        return (int) (ans % mod);
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 3;
        System.out.println(new Solution().countOrders(n));
    }
}