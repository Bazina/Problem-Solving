import java.util.Arrays;

class Solution {
    public int[] sortByBits(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            arr[i] += Integer.bitCount(arr[i]) * 10001;

        Arrays.sort(arr);

        for (int i = 0; i < arr.length; i++)
            arr[i] %= 10001;

        return arr;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        System.out.println(Arrays.toString(new Solution().sortByBits(arr)));
    }
}