class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for (String word : word1)
            s1.append(word);

        for (String word : word2)
            s2.append(word);

        return (s1.toString()).contentEquals(s2);
    }
}

public class Main {

    public static void main(String[] args) {
        String[] word1 = {"abc", "d", "defg"}, word2 = {"abcddeh"};
        System.out.println(new Solution().arrayStringsAreEqual(word1, word2));
    }
}

/* Implemented
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0, n1 = word1.length, n2 = word2.length;
        char[] currentWord1 = word1[i1].toCharArray();
        char[] currentWord2 = word2[i2].toCharArray();

        while (true) {
            if (currentWord1[j1] != currentWord2[j2])
                return false;

            j1++;
            j2++;
            if (j1 == currentWord1.length && i1 < n1 - 1) {
                currentWord1 = word1[++i1].toCharArray();
                j1 = 0;
            }
            if (j2 == currentWord2.length && i2 < n2 - 1) {
                currentWord2 = word2[++i2].toCharArray();
                j2 = 0;
            }

            if (i1 == n1 - 1 && i2 == n2 - 1 && j1 == currentWord1.length && j2 == currentWord2.length)
                return true;

            else if ((i1 == n1 - 1 && j1 == currentWord1.length) ^ (i2 == n2 - 1 && j2 == currentWord2.length))
                return false;
        }
    }
}
 */