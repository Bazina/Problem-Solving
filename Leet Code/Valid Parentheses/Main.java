import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!stack.empty()) {
                char top = stack.peek();
                if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}'))
                    stack.pop();
                else
                    stack.push(s.charAt(i));
            } else
                stack.push(s.charAt(i));
        }

        return stack.empty();
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "()[]{}";
        Solution solution = new Solution();
        System.out.println(solution.isValid(s));
    }
}