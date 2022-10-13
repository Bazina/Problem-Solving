class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int[] diff = new int[gas.length + 1];
        int sumCost = 0, sumGas = 0;

        for (int i = 0; i < gas.length; i++) {
            diff[i + 1] = gas[i] - cost[i];
            sumGas += gas[i];
            sumCost += cost[i];
        }

        if (sumGas < sumCost)
            return -1;

        int total = 0, idx = 1;
        for (int i = 1; i < diff.length; i++) {
            if (total + diff[i] < 0) {
                total = 0;
                idx = i + 1;
            } else {
                total += diff[i];
            }
        }

        return idx - 1;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] gas = {3, 1, 1}, cost = {1, 2, 2};
        Solution min = new Solution();
        System.out.println(min.canCompleteCircuit(gas, cost));
    }
}