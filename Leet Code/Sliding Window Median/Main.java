import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

class Solution {
    static class Pair {
        private final int idx;
        private final int value;

        public Pair(int idx, int value) {
            this.idx = idx;
            this.value = value;
        }
    }

    static class PairComparator implements Comparator<Pair> {
        @Override
        public int compare(Pair o1, Pair o2) {
            if (o1.value == o2.value)
                return o1.idx - o2.idx;
            return o1.value - o2.value;
        }
    }

    TreeSet<Pair> leftSet = new TreeSet<>(new PairComparator()), rightSet = new TreeSet<>(new PairComparator());
    int idx = 0;

    public void addNum(int num) {
        if (!rightSet.isEmpty() && num > rightSet.first().value)
            rightSet.add(new Pair(idx, num));
        else {
            leftSet.add(new Pair(idx, num));
        }

        reBalance();

        idx++;
    }

    public void remove(int num, int idx) {
        if (!leftSet.isEmpty() && leftSet.contains(new Pair(num, idx)))
            leftSet.remove(new Pair(idx, num));
        else
            rightSet.remove(new Pair(idx, num));

        reBalance();
    }

    public void reBalance() {
        if (rightSet.size() > leftSet.size() + 1) {
            Pair remove = rightSet.first();
            rightSet.remove(remove);
            leftSet.add(remove);
        } else if (leftSet.size() > rightSet.size() + 1) {
            Pair remove = leftSet.last();
            leftSet.remove(remove);
            rightSet.add(remove);
        }
    }

    public double findMedian() {
        if (idx % 2 == 0)
            return (leftSet.last().value + rightSet.first().value) / 2.0;

        return leftSet.size() > rightSet.size() ? leftSet.last().value : rightSet.first().value;
    }

    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] result = new double[nums.length - k + 1];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            addNum(nums[i]);
            if (i - k + 1 >= 0) {
                result[j++] = findMedian();
                remove(nums[i - k + 1], i - k + 1);
            }
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;

        System.out.println(Arrays.toString(new Solution().medianSlidingWindow(nums, k)));
    }
}
