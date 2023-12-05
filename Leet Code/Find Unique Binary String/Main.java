import java.util.BitSet;

class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums.length;
        BitSet existBitSet = new BitSet(n + 3);

        for (String num : nums) {
            char[] nChars = num.toCharArray();
            int x = 0;
            for (int j = 0; j < n; j++)
                x = (x << 1) | (nChars[j] - '0');

            existBitSet.set(Math.min(x, n + 2));
        }

        for (int i = 0; i < n + 1; i++)
            if (!existBitSet.get(i))
                return toBinaryString(i, n);

        return "";
    }

    private String toBinaryString(int i, int size) {
        char[] binaryString = new char[size];
        char[] shortBinaryString = Integer.toBinaryString(i).toCharArray();

        for (int j = shortBinaryString.length - 1, l = size - 1; j >= 0; j--, l--)
            binaryString[l] = shortBinaryString[j];

        if (shortBinaryString.length < size)
            for (int j = size - shortBinaryString.length - 1; j >= 0; j--)
                binaryString[j] = '0';

        return new String(binaryString);
    }
}

public class Main {

    public static void main(String[] args) {
        String[] nums = {"111", "011", "101"};
        System.out.println(new Solution().findDifferentBinaryString(nums));
    }
}