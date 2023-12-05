import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> stackOperations = new ArrayList<>();

        int targetIdx = 0;
        for (int i = 1; i <= n; i++) {
            if (target[targetIdx] == i) {
                stackOperations.add("Push");
                targetIdx++;
            } else {
                stackOperations.add("Push");
                stackOperations.add("Pop");
            }

            if (targetIdx == target.length)
                break;
        }

        return stackOperations;
    }
}

public class Main {

    public static void main(String[] args) {
        int n = 7;
        int[] target = {2, 3, 6};
        System.out.println(new Solution().buildArray(target, n));
    }
}