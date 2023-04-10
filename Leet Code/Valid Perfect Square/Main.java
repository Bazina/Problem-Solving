class Solution {
    public boolean isPerfectSquare(int num) {
        long r = 1048576, l = 0;
        while (l + 1 < r) {
            long mid = (l + r) / 2;
            long midSq = mid * mid;

            if (midSq < num)
                l = mid + 1;
            else if (midSq == num)
                return true;
            else
                r = mid;
        }

        return l * l == num;
    }
}

public class Main {
    public static void main(String[] args) {
        int num = 441;
        System.out.println(new Solution().isPerfectSquare(num));
    }
}