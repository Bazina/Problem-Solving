class Solution {
    public int findSpecialInteger(int[] arr) {
        int requiredSize = arr.length / 4;
        int count = 1;
        int answer = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (answer != arr[i]) {
                count = 1;
                answer = arr[i];
            } else
                count++;

            if (count > requiredSize)
                return answer;
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
        System.out.println(new Solution().findSpecialInteger(arr));
    }
}