class Solution {
    public boolean winnerOfGame(String colors) {
        char[] colorsCharArray = colors.toCharArray();
        int score = 0;
        int l = 0, r = 0;
        while (l < colorsCharArray.length - 1) {
            while (r < colorsCharArray.length && colorsCharArray[r] == colorsCharArray[l]) {
                r++;
            }

            if (l < r - 1) {
                if (colorsCharArray[l] == 'A')
                    score += r - 1 - l - 1;
                else
                    score -= r - 1 - l - 1;
            }

            l = r;
        }

        return score > 0;
    }
}

public class Main {
    public static void main(String[] args) {
        String colors = "ABBAAA";
        System.out.println(new Solution().winnerOfGame(colors));
    }
}