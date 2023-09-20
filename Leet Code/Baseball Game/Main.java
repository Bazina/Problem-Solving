import java.util.Stack;

class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> scoreStack = new Stack<>();
        int currentScore, previousScore, newScore, totalScore = 0;

        for (int i = 0; i < operations.length; i++) {
            switch (operations[i]) {
                case "D":
                    currentScore = scoreStack.peek();
                    scoreStack.push(currentScore * 2);
                    totalScore += scoreStack.peek();
                    break;
                case "C":
                    totalScore -= scoreStack.peek();
                    scoreStack.pop();
                    break;
                case "+":
                    currentScore = scoreStack.pop();
                    previousScore = scoreStack.pop();
                    newScore = currentScore + previousScore;
                    scoreStack.push(previousScore);
                    scoreStack.push(currentScore);
                    scoreStack.push(newScore);
                    totalScore += newScore;
                    break;
                default:
                    scoreStack.push(Integer.parseInt(operations[i]));
                    totalScore += scoreStack.peek();
            }
        }

        return totalScore;
    }
}

public class Main {
    public static void main(String[] args) {
        String[] operations = {"5", "2", "C", "D", "+"};
        System.out.println(new Solution().calPoints(operations));
    }
}