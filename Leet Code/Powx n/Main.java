class Solution {
    public double myPow(double x, int n) {
        if (x == 0)
            return 0;

        if (n == 0 || x == 1)
            return 1;

        long nLong = n;
        if (n < 0) {
            nLong *= -1;
            x = 1 / x;
        }

        double result = 1.0;

        while (nLong > 0) {
            if (nLong % 2 == 1) {
                result *= x;
                n--;
            }

            nLong >>= 1;
            x = x * x;
        }

        return result;
    }
}
public class Main {
    public static void main(String[] args) {
        double x = 2.0000;
        int n = -5;
        System.out.println(new Solution().myPow(x, n));
    }
}