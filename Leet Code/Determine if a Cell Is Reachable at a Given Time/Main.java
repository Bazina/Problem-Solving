class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dy = Math.abs(fy - sy);
        int dx = Math.abs(fx - sx);

        if (t == 1 && dy == 0 && dx == 0)
            return false;

        return t >= Math.max(dx, dy);
    }
}

public class Main {

    public static void main(String[] args) {
        int sx = 1, sy = 2, fx = 1, fy = 2, t = 1;
        System.out.println(new Solution().isReachableAtTime(sx, sy, fx, fy, t));
    }
}

/*
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diagonal = Math.min(Math.abs(fx - sx), Math.abs(fy - sy));
        int steps = Math.max(Math.abs(fx - sx), Math.abs(fy - sy)) - diagonal;

        if (t == 1 && diagonal + steps == 0)
            return false;

        return t >= diagonal + steps;
    }
}
 */