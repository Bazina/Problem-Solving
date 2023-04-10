import java.util.Comparator;
import java.util.PriorityQueue;

class MedianFinder {
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder()), minHeap = new PriorityQueue<>();
    int idx = 0;

    public MedianFinder() {

    }

    public void addNum(int num) {
        if (!minHeap.isEmpty() && num > minHeap.peek())
            minHeap.add(num);
        else {
            maxHeap.add(num);
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.add(minHeap.poll());
        } else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.add(maxHeap.poll());
        }

        idx++;
    }

    public double findMedian() {
        if (idx % 2 == 0)
            return (maxHeap.peek() + minHeap.peek()) / 2.0;

        return maxHeap.size() > minHeap.size() ? maxHeap.peek() : minHeap.peek();
    }
}

public class Main {
    public static void main(String[] args) {
        MedianFinder medianFinder = new MedianFinder();
        medianFinder.addNum(-1);    // arr = [1]
        System.out.println(medianFinder.findMedian()); // return 1
        medianFinder.addNum(-2);    // arr = [1, 3]
        System.out.println(medianFinder.findMedian()); // return 2
        medianFinder.addNum(-3);    // arr[-1, 1, 3]
        System.out.println(medianFinder.findMedian()); // return 1
        medianFinder.addNum(-4);    // arr[-3, -1, 1, 3]
        System.out.println(medianFinder.findMedian()); // return 0
        medianFinder.addNum(-5);    // arr[-3, -1, 1, 3, 5]
        System.out.println(medianFinder.findMedian()); // return 1
        //medianFinder.addNum(3);    // arr[-3, -1, 1, 3, 3, 5]
        //System.out.println(medianFinder.findMedian()); // return 2
        //medianFinder.addNum(6);    // arr[-3, -1, 1, 3, 3, 5, 6]
        //System.out.println(medianFinder.findMedian()); // return 3
        //medianFinder.addNum(7);    // arr[-3, -1, 1, 3, 3, 5, 6, 7]
        //System.out.println(medianFinder.findMedian()); // return 3
    }
}
