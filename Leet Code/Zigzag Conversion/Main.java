class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || (s.length() <= numRows))
           return s;

        StringBuilder answer = new StringBuilder();
        int gaps = numRows - 2;
        int nextIdx = numRows + gaps;
        int nextJump = nextIdx - 2;

        int i = 0;

        while (i < numRows) {
            int idx = i;
            if (i == numRows - 1 || i == 0) {
                while (idx < s.length()) {
                    answer.append(s.charAt(idx));
                    if (nextIdx == 0)
                        break;
                    idx += nextIdx;
                }
            } else {
                while (idx < s.length()) {
                    answer.append(s.charAt(idx));
                    if (idx + nextJump < s.length())
                        answer.append(s.charAt(idx + nextJump));
                    idx += nextIdx;
                }
                nextJump -= 2;
            }
            i++;
        }

        return answer.toString();
    }
}
public class Main {
    public static void main(String[] args) {
        String s = "ABCD";
        int numRows = 5;
        System.out.println(new Solution().convert(s, numRows));
    }
}