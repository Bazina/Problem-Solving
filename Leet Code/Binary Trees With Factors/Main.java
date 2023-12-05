import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length, mod = (int) 1e9 + 7;
        HashMap<Integer, Long> dp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            dp.put(arr[i], 1L);
            for (int j = 0; arr[j] <= (int) Math.sqrt(arr[i]); j++) {
                if (arr[i] % arr[j] == 0) {
                    int factor = arr[i] / arr[j];
                    if (dp.containsKey(factor)) {
                        long previousTrees = dp.get(arr[j]) * dp.get(arr[i] / arr[j]);
                        if (factor != arr[j])
                            previousTrees *= 2;
                        dp.put(arr[i], dp.get(arr[i]) + previousTrees);
                    }
                }
            }
        }

        long result = 0;
        for (long ways: dp.values())
            result = (result + ways) % mod;

        return (int) result;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] arr = {2, 4, 5, 10};
        System.out.println(new Solution().numFactoredBinaryTrees(arr));
    }
}