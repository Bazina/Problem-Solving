class Solution {
    public String decodeAtIndex(String s, int k) {
        long decodedStringLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i)))
                decodedStringLength *= Character.getNumericValue(s.charAt(i));
            else
                decodedStringLength++;
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            char currentCharacter = s.charAt(i);
            if (Character.isDigit(currentCharacter)) {
                decodedStringLength /= Character.getNumericValue(currentCharacter);
                k %= decodedStringLength;
            } else if (k == 0 || k == decodedStringLength)
                return Character.toString(currentCharacter);
            else {
                decodedStringLength--;
            }
        }

        return Character.toString(s.charAt(0));
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "a2b3";
        int k = 3;
        System.out.println(new Solution().decodeAtIndex(s, k));
    }
}