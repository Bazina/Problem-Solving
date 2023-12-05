class Solution {
    public int kthGrammar(int n, int k) {
        boolean inverse = false;

        n = 1 << n - 1;

        while (n != 1) {
            n /= 2;

            if (k > n) {
                k -= n;
                inverse = !inverse;
            }
        }

        return inverse ? 1 : 0;
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 5, k = 14;
        System.out.println(new Solution().kthGrammar(n, k));
    }
}