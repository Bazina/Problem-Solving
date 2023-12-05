class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        return Integer.bitCount(n);
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 3;
        System.out.println(new Solution().hammingWeight(n));
    }
}