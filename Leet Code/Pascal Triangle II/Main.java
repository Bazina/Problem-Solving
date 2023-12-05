import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> answer = new ArrayList<>(rowIndex + 1);

        if (rowIndex == 0) return new ArrayList<>() {{
            add(1);
        }};

        if (rowIndex == 1) return new ArrayList<>() {{
            add(1);
            add(1);
        }};

        long element = 1, n = rowIndex + 1;
        for (int i = 1; i <= n; i++) {
            answer.add((int) element);
            element = element * (rowIndex + 1 - i) / i;
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        int rowIndex = 30;
        System.out.println(new Solution().getRow(rowIndex));
    }
}