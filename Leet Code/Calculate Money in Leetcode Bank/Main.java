class Solution {
    public int totalMoney(int n) {
        int fullWeeks = n / 7;
        int start = 28;
        int total = (int) ((fullWeeks / 2.0) * (2 * start + (fullWeeks - 1) * 7));

        if (n % 7 != 0) {
            int remainder = n % 7;
            total += (int) ((remainder / 2.0) * (2 * (fullWeeks + 1) + remainder - 1));
        }

        return total;
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 21;
        System.out.println(new Solution().totalMoney(n));
    }
}