class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; i--)
            if (((num.charAt(i) - '0') & 1) == 1)
                return num.substring(0, i + 1);

        return "";
    }
}

public class Main {
    public static void main(String[] args) {
        String num = "152";
        System.out.println(new Solution().largestOddNumber(num));
    }
}