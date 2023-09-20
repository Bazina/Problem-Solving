class Solution {
    public int myAtoi(String s) {
        int answer = 0, sign = 1, i = 0;

        while (i < s.length() && s.charAt(i) == ' ')
            i++;

        if (i < s.length() && s.charAt(i) == '+')
            i++;
        else if (i < s.length() && s.charAt(i) == '-') {
            i++;
            sign = -1;
        }

        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i) - '0';

            if ((answer > Integer.MAX_VALUE / 10) || (answer == Integer.MAX_VALUE / 10 && digit > 7))
                return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;

            answer = answer * 10 + digit;
            i++;
        }

        return answer * sign;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "2147483646";
        System.out.println(new Solution().myAtoi(s));
    }
}