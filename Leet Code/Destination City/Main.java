import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> cities = new HashSet<>();

        for (List<String> path : paths) {
            cities.add(path.get(0));
        }

        for (List<String> path : paths) {
            if (!cities.contains(path.get(1)))
                return path.get(1);
        }

        return "";
    }
}

public class Main {
    public static void main(String[] args) {
        List<List<String>> paths = new ArrayList<>();
        paths.add(new ArrayList<>() {{
            add("London");
            add("New York");
        }});
        paths.add(new ArrayList<>() {{
            add("New York");
            add("Lima");
        }});
        paths.add(new ArrayList<>() {{
            add("Lima");
            add("Sao Paulo");
        }});

        System.out.println(new Solution().destCity(paths));
    }
}