import java.util.Arrays;

class MyHashMap {
    int[] hashMapArray;

    public MyHashMap() {
        hashMapArray = new int[1_000_005];
        Arrays.fill(hashMapArray, -1);
    }

    public void put(int key, int value) {
        hashMapArray[key] = value;
    }

    public int get(int key) {
        return hashMapArray[key];
    }

    public void remove(int key) {
        hashMapArray[key] = -1;
    }
}

public class Main {
    public static void main(String[] args) {
        MyHashMap obj = new MyHashMap();
        System.out.println(obj.get(1));
        obj.put(1, 1);
        System.out.println(obj.get(1));
        obj.remove(1);
        System.out.println(obj.get(1));
    }
}