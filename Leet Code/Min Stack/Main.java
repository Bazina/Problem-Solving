import java.util.Stack;

class MinStack {
    Stack<Integer> stack;
    Stack<Integer> mini;
    public MinStack() {
        stack = new Stack<>();
        mini = new Stack<>();
    }

    public void push(int val) {
        stack.push(val);
        if (mini.empty() || mini.peek() >= val)
            mini.push(val);
    }

    public void pop() {
        if (!stack.empty() && !mini.empty() && stack.peek().equals(mini.peek()))
            mini.pop();
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return mini.peek();
    }
}

public class Main {
    public static void main(String[] args) {

    }
}