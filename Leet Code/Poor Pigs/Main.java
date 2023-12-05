class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ratio = minutesToTest / minutesToDie;
        float minPigs = (float) (Math.log(buckets) / Math.log(ratio + 1));
        return (int) Math.ceil(minPigs);
    }
}

public class Main {

    public static void main(String[] args) {
        int buckets = 125, minutesToDie = 1, minutesToTest = 4;
        System.out.println(new Solution().poorPigs(buckets, minutesToDie, minutesToTest));
    }
}