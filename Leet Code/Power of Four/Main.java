class Solution {
    public boolean isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        double x = Math.log(n) / 1.3862943611198906;
        return x == (int) x;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 0;
        System.out.println(new Solution().isPowerOfFour(n));
    }
}
