class Solution {

    public int minEatingSpeed(int[] piles, int h) {
        int lo = 0, hi = 0, time = 0, mid = 0;
        for (int pile : piles) {
            if (hi < pile) hi = pile;
        }
        while (hi >= lo) {
            mid = lo + (hi - lo) / 2;
            if (calc(mid, piles, h)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }

    public boolean calc(int mid, int[] piles, int h) {
        int finish = 0;
        for (int pile : piles) {
            finish += Math.ceil((double) pile / mid);
        }
        return finish <= h;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] piles = {30,11,23,4,20};
        int h = 6;
        Solution min = new Solution();
        System.out.println(min.minEatingSpeed(piles, h));
    }
}