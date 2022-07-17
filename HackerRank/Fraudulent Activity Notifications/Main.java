import java.io.*;
import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.toList;

class Result {
    public static int activityNotifications(List<Integer> expenditure, int d) {
        int maxi = Collections.max(expenditure);
        int mini = Collections.min(expenditure);
        int[] frequency = new int[201];

        for (int i = 0; i < d; i++)
            frequency[expenditure.get(i)]++;

        int notification = 0;

        for (int i = d; i < expenditure.size(); i++) {
            int firstMedianIdx = 0, secondMedianIdx = 0, start, end;

            for (start = mini; (firstMedianIdx + frequency[start]) * 2 <= d; start++)
                firstMedianIdx += frequency[start];

            for (end = maxi; (secondMedianIdx + frequency[end]) * 2 <= d; end--)
                secondMedianIdx += frequency[end];

            if (expenditure.get(i) >= start + end)
                notification++;

            frequency[expenditure.get(i)]++;
            frequency[expenditure.get(i - d)]--;
        }

        return notification;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("D:\\Library\\Programming\\" +
                                                                          "Competitive Programming\\Training\\" +
                                                                          "HackerRank\\" +
                                                                          "Fraudulent Activity Notifications" +
                                                                          "\\src\\output.txt"));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int d = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> expenditure = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                .map(Integer::parseInt).collect(toList());

        int result = Result.activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
