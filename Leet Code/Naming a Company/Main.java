import java.util.*;

class Solution {
    public long distinctNames(String[] ideas) {
        long ans = 0, intersection;
        HashSet<String>[] alphabeticGroups = new HashSet[26];

        for (int i = 0; i < 26; i++)
            alphabeticGroups[i] = new HashSet<>();

        for (String idea : ideas)
            alphabeticGroups[idea.charAt(0) - 'a'].add(idea.substring(1));

        for (int i = 0; i < 25; i++)
            for (int j = i + 1; j < 26; j++) {
                intersection = 0;
                for (String ideaA : alphabeticGroups[i])
                    if (alphabeticGroups[j].contains(ideaA))
                        intersection++;

                ans += 2 * (alphabeticGroups[i].size() - intersection) * (alphabeticGroups[j].size() - intersection);
            }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        String[] ideas = {"coffee", "donuts", "time", "toffee"};
        System.out.println(new Solution().distinctNames(ideas));
    }
}