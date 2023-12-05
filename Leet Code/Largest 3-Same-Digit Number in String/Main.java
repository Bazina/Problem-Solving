class Solution {
    public String largestGoodInteger(String num) {
        char maxi = '\0';
        char[] numChars = num.toCharArray();

        for (int i = 1; i < numChars.length - 1; i++)
            if (numChars[i] == numChars[i - 1] && numChars[i] == numChars[i + 1])
                maxi = (char) Math.max(maxi, numChars[i]);

        return maxi == '\0' ? "" : new String(new char[]{maxi, maxi, maxi});
    }
}

public class Main {

    public static void main(String[] args) {
        String num = "677713333999";
        System.out.println(new Solution().largestGoodInteger(num));
    }
}