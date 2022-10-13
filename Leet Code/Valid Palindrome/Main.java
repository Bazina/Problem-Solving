class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                i++;
                continue;
            }

            if (!Character.isLetterOrDigit(s.charAt(j))) {
                j--;
                continue;
            }

            if (Character.toLowerCase(s.charAt(i)) == Character.toLowerCase(s.charAt(j))) {
                i++;
                j--;
            } else
                return false;
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        String str = "A man, a plan, a canal: Panama";
        Solution solution = new Solution();
        System.out.println(solution.isPalindrome(str));
    }
}