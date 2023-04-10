import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;

        while (i < tokens.length) {
            if (tokens[i].equals("+") || tokens[i].equals("-") ||
                    tokens[i].equals("*") || tokens[i].equals("/")) {
                int op1 = stack.pop();
                int op2 = stack.pop();
                stack.push(operation(op1, op2, tokens[i]));
            } else {
                stack.push(Integer.parseInt(tokens[i]));
            }
            i++;
        }

        return stack.peek();
    }

    public int operation(int op1, int op2, String op) {
        return switch (op) {
            case "+" -> op1 + op2;
            case "-" -> op2 - op1;
            case "/" -> op2 / op1;
            case "*" -> op1 * op2;
            default -> -1;
        };
    }
}

public class Main {
    public static void main(String[] args) {
        String[] tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

        Solution min = new Solution();
        System.out.println(min.evalRPN(tokens));
    }
}