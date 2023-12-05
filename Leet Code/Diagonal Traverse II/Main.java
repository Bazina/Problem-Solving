import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        List<Integer[]> flatNumsList = new ArrayList<>();

        for (int i = 0; i < nums.size(); i++) {
            List<Integer> row = nums.get(i);
            for (int j = 0; j < row.size(); j++) {
                flatNumsList.add(new Integer[]{i, i + j, row.get(j)});
            }
        }

        flatNumsList.sort((o1, o2) -> {
            if (o1[1].compareTo(o2[1]) == 0)
                return o2[0].compareTo(o1[0]);
            return o1[1].compareTo(o2[1]);
        });

        int[] flatNums = new int[flatNumsList.size()];
        for (int i = 0; i < flatNums.length; i++)
            flatNums[i] = flatNumsList.get(i)[2];

        return flatNums;
    }
}

public class Main {

    public static void main(String[] args) {
        List<List<Integer>> nums = new ArrayList<>() {{
            add(new ArrayList<>() {{
                add(1);
                add(2);
                add(3);
                add(4);
                add(5);
            }});
            add(new ArrayList<>() {{
                add(6);
                add(7);
            }});
            add(new ArrayList<>() {{
                add(8);
            }});
            add(new ArrayList<>() {{
                add(9);
                add(10);
                add(11);
            }});
            add(new ArrayList<>() {{
                add(12);
                add(13);
                add(14);
                add(15);
                add(16);
            }});
        }};

        System.out.println(Arrays.toString(new Solution().findDiagonalOrder(nums)));
    }
}