import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> groupedPeople = new ArrayList<>();
        HashMap<Integer, List<Integer>> groupedPeopleByIds = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            List<Integer> group = groupedPeopleByIds.getOrDefault(groupSizes[i], new ArrayList<>());
            group.add(i);
            groupedPeopleByIds.put(groupSizes[i], group);
            if (group.size() == groupSizes[i]) {
                groupedPeople.add(List.copyOf(group));
                group.clear();
            }
        }

        return groupedPeople;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] groupSizes = {2, 1, 3, 3, 3, 2};
        System.out.println(new Solution().groupThePeople(groupSizes));
    }
}