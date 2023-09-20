import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

class Solution {
    HashMap<String, List<String>> flightGraph = new HashMap<>();
    List<String> itinerary = new ArrayList<>();

    private void eulerDfs(String airport) {
        List<String> nextAirports = flightGraph.get(airport);

        while (nextAirports != null && !nextAirports.isEmpty()) {
            String nextAirport = nextAirports.remove(nextAirports.size() - 1);
            eulerDfs(nextAirport);
        }

        itinerary.add(airport);
    }
    
    public List<String> findItinerary(List<List<String>> tickets) {
        for (List<String> ticket : tickets) {
            String from = ticket.get(0);
            String to = ticket.get(1);
            flightGraph.computeIfAbsent(from, k -> new ArrayList<>()).add(to);
        }

        for (List<String> destinations : flightGraph.values())
            destinations.sort(Collections.reverseOrder());
        
        eulerDfs("JFK");

        Collections.reverse(itinerary);

        return itinerary;
    }
}

public class Main {
    public static void main(String[] args) {
        List<List<String>> tickets = new ArrayList<>() {
            {
                add(new ArrayList<>() {{
                    add("MUC");
                    add("LHR");
                }});
                add(new ArrayList<>() {{
                    add("JFK");
                    add("MUC");
                }});
                add(new ArrayList<>() {{
                    add("SFO");
                    add("SJC");
                }});
                add(new ArrayList<>() {{
                    add("LHR");
                    add("SFO");
                }});
            }
        };
        System.out.println(new Solution().findItinerary(tickets));
    }
}