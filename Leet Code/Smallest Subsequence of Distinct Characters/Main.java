import java.util.Stack;

class Solution {
    public String smallestSubsequence(String s) {
        boolean[] visited = new boolean[26];
        int[] charLastIndex = new int[26];

        for (int i = 0; i < s.length(); i++) {
            charLastIndex[s.charAt(i) - 'a'] = i;
        }

        Stack<Character> monotonicStack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char nextChar = s.charAt(i);
            if (visited[nextChar - 'a'])
                continue;
            while (!monotonicStack.empty() && nextChar < monotonicStack.peek() && i < charLastIndex[monotonicStack.peek() - 'a']) {
                visited[monotonicStack.pop() - 'a'] = false;
            }

            visited[nextChar - 'a'] = true;
            monotonicStack.add(nextChar);
        }

        char[] answer = new char[monotonicStack.size()];
        int i = monotonicStack.size() - 1;
        while (!monotonicStack.empty()) {
            answer[i--] = monotonicStack.pop();
        }

        return String.valueOf(answer);
    }
}

public class Main {
    public static void main(String[] args) {
        String words = "xyzaxyz";
        System.out.println(new Solution().smallestSubsequence(words));
    }
}