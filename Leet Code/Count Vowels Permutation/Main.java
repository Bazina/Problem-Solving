class Solution {
    public int countVowelPermutation(int n) {
        int mod = (int) 1e9 + 7;
        long countA = 1, countE = 1, countI = 1, countO = 1, countU = 1;
        for (int i = 2; i <= n; i++) {
            long newCountA = countE % mod;
            long newCountE = (countA + countI) % mod;
            long newCountI = (countE + countA + countO + countU) % mod;
            long newCountO = (countI + countU) % mod;
            long newCountU = (countA) % mod;

            countA = newCountA;
            countE = newCountE;
            countI = newCountI;
            countO = newCountO;
            countU = newCountU;
        }

        return (int) ((countA + countE + countI + countO + countU) % mod);
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 3;
        System.out.println(new Solution().countVowelPermutation(n));
    }
}

/* DP O(5 * n^2)
import java.util.HashMap;

class Solution {
    HashMap<Character, char[]> vowelsMap = new HashMap<>() {
        {
            put('a', new char[]{'e'});
            put('e', new char[]{'a', 'i'});
            put('i', new char[]{'a', 'e', 'o', 'u'});
            put('o', new char[]{'i', 'u'});
            put('u', new char[]{'a'});
        }
    };
    HashMap<String, Integer> dp = new HashMap<>();
    char[] vowels = {'a', 'e', 'i', 'o', 'u'};
    int n, mod = (int) 1e9 + 7;

    public int countVowelPermutation(int n) {
        this.n = n;

        int ans = 0;
        for (int i = 0; i < vowels.length; i++) {
            ans = (ans + recur(1, vowels[i])) % mod;
        }

        return ans;
    }

    int recur(int length, char currentChar) {
        if (length == n)
            return 1;

        String neededKey = Integer.toString(n - length + 1) + currentChar;
        if (dp.containsKey(neededKey))
            return dp.get(neededKey);

        int ans = 0;
        var nextChars = vowelsMap.get(currentChar);

        for (char nextChar : nextChars) {
            ans = (ans + recur(length + 1, nextChar)) % mod;
        }

        String key = Integer.toString(n - length + 1) + currentChar;
        dp.put(key, ans);
        return ans;
    }
}
 */