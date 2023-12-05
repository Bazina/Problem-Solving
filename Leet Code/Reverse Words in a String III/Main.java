class Solution {
    public String reverseWords(String s) {
        int l = 0, r = 0;
        char[] sCharacters = s.toCharArray();

        while (r < sCharacters.length) {
            if (r + 1 != sCharacters.length && sCharacters[r + 1] != ' ')
                r++;
            else {
                reverseWord(l, r, sCharacters);
                if (r + 1 == sCharacters.length)
                    return String.valueOf(sCharacters);
                else {
                    r += 2;
                    l = r;
                }
            }
        }

        return String.valueOf(sCharacters);
    }

    private void reverseWord(int l, int r, char[] sCharacters) {
        while (l < r) {
            char temp = sCharacters[l];
            sCharacters[l++] = sCharacters[r];
            sCharacters[r--] = temp;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "Let's take LeetCode contest";
        System.out.println(new Solution().reverseWords(s));
    }
}