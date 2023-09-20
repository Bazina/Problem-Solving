class Solution {
    public boolean validPalindrome(String s) {
        int i = 0, j = s.length() - 1;

        while (i <= j) {
            if (s.charAt(i) != s.charAt(j))
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            i++;
            j--;
        }

        return true;
    }

    private boolean isPalindrome(String s, int i, int j) {
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        String str = "abaabab";
        System.out.println(new Solution().validPalindrome(str));
    }
}

/* Iterative Approach
class Solution {
    public boolean validPalindrome(String s) {
        int i1 = 0, j1 = s.length() - 1, cnt1 = 0, cnt2 = 0, i2 = 0, j2 = s.length() - 1;

        while (i1 <= j1) {
            if (s.charAt(i1) == s.charAt(j1)) {
                i1++;
                j1--;
            } else if (i1 + 1 <= j1 && s.charAt(i1 + 1) == s.charAt(j1)) {
                if (i2 == -1) {
                    i2 = i1;
                    j2 = j1;
                }
                j1--;
                i1 += 2;
                cnt1++;
            } else
                break;

            if (cnt1 > 1)
                break;
        }

        if (i1 > j1 && cnt1 <= 1)
            return true;

        while (i2 <= j2) {
            if (s.charAt(i2) == s.charAt(j2)) {
                i2++;
                j2--;
            } else if (j2 - 1 >= i2 && s.charAt(i2) == s.charAt(j2 - 1)) {
                j2 -= 2;
                i2++;
                cnt2++;
            } else
                return false;

            if (cnt2 > 1)
                return false;
        }

        return true;
    }
}
 */