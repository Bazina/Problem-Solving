class Solution {
    public int numberOfMatches(int n) {
        return n - 1;
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 15;
        System.out.println(new Solution().numberOfMatches(n));
    }
}