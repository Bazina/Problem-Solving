import java.util.PriorityQueue;

class SeatManager {
    PriorityQueue<Integer> seats;
    int minSeat;

    public SeatManager(int n) {
        seats = new PriorityQueue<>();
        minSeat = 1;
    }

    public int reserve() {
        if (!seats.isEmpty())
            return seats.poll();

        int seat = minSeat;
        minSeat++;
        return seat;
    }

    public void unreserve(int seatNumber) {
        seats.add(seatNumber);
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 5;
        SeatManager obj = new SeatManager(n);
        int param1 = obj.reserve();
        System.out.println(param1);
        obj.unreserve(param1);
        int param2 = obj.reserve();
        System.out.println(param2);
        int param3 = obj.reserve();
        System.out.println(param3);
    }
}