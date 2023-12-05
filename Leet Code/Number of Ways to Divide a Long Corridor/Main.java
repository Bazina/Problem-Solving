class Solution {
    int n, mod = (int) 1e9 + 7;
    public int numberOfWays(String corridor) {
        n = corridor.length();
        int seatsCount = 0, lastIdx = -1;
        long answer = 1;
        char[] corridorChars = corridor.toCharArray();

        for (int i = 0; i < n; i++) {
            if (corridorChars[i] == 'S') {
                seatsCount++;

                if (seatsCount == 2) {
                    seatsCount = 0;
                    lastIdx = i;
                } else if (lastIdx != -1) {
                    answer = (answer * (i - lastIdx)) % mod;
                }
            }
        }

        if (seatsCount == 1 || lastIdx == -1)
            return 0;
        return (int) answer;
    }
}

public class Main {

    public static void main(String[] args) {
        String corridor = "PP";
        System.out.println(new Solution().numberOfWays(corridor));
    }
}