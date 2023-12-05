class Solution {
    public int countHomogenous(String s) {
        long countHomogenous = 0, count = 1, mod = (int) 1e9 + 7;
        char[] sChars = s.toCharArray();

        for (int i = 1; i < s.length(); i++) {
            if (sChars[i] != sChars[i - 1]) {
                countHomogenous = (countHomogenous + count * (count + 1) / 2) % mod;
                count = 1;
            } else
                count++;
        }
        countHomogenous = (countHomogenous + count * (count + 1) / 2) % mod;

        return (int) countHomogenous;
    }
}

public class Main {

    public static void main(String[] args) {
        String s = "zzzzz";
        System.out.println(new Solution().countHomogenous(s));
    }
}