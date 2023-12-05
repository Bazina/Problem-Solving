class Solution {
    public boolean backspaceCompare(String s, String t) {
        int sBackspaceCount = 0, tBackspaceCount = 0;
        int i = s.length() - 1, j = t.length() - 1;
        char[] sChar = s.toCharArray(), tChar = t.toCharArray();

        while (i >= 0 || j >= 0) {
            while (i >= 0 && sChar[i] == '#') {
                sBackspaceCount++;
                i--;
            }

            while (j >= 0 && tChar[j] == '#') {
                tBackspaceCount++;
                j--;
            }

            while (j >= 0 && tChar[j] != '#' && tBackspaceCount > 0) {
                j--;
                tBackspaceCount--;
            }

            while (i >= 0 && sChar[i] != '#' && sBackspaceCount > 0) {
                i--;
                sBackspaceCount--;
            }

            if (i >= 0 && j >= 0 && tBackspaceCount == 0 && sBackspaceCount == 0) {
                if (sChar[i] == '#' || tChar[j] == '#')
                    continue;

                if (sChar[i] == tChar[j]) {
                    i--;
                    j--;
                } else
                    return false;
            }

            if ((i >= 0 && j < 0 && sChar[i] != '#') || (j >= 0 && i < 0 && tChar[j] != '#'))
                return false;
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "isfcow#", t = "isfcog#w#";
        System.out.println(new Solution().backspaceCompare(s, t));
    }
}