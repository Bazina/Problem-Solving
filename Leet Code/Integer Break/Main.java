class Solution {
    public int integerBreak(int n) {
        if (n < 4)
            return n - 1;

        if (n % 3 == 0)
            return (int) Math.pow(3, (double) n / 3);
        else if (n % 3 == 1)
            return 4 * (int) Math.pow(3, (double) (n - 4) / 3);
        else
            return 2 * (int) Math.pow(3, (double) (n - 2) / 3);
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 4;
        System.out.println(new Solution().integerBreak(n));
    }
}