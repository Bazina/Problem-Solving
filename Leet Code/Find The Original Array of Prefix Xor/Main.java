import java.util.Arrays;

class Solution {
    public int[] findArray(int[] pref) {
        for (int i = pref.length - 1; i >= 1; i--)
            pref[i] ^= pref[i - 1];

        return pref;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] pref = {5, 2};
        System.out.println(Arrays.toString(new Solution().findArray(pref)));
    }
}