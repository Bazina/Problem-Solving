class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int mPointer = 0, pPointer = 0, gPointer = 0;
        int collectionTime = 0;

        for (int i = 0; i < garbage.length; i++) {
            char[] garbageChars = garbage[i].toCharArray();
            for (char garbageChar : garbageChars) {
                collectionTime++;
                if (garbageChar == 'M')
                    mPointer = i;
                else if (garbageChar == 'G')
                    gPointer = i;
                else
                    pPointer = i;
            }
        }

        for (int i = 1; i < travel.length; i++)
            travel[i] += travel[i - 1];

        collectionTime += mPointer == 0 ? 0 : travel[mPointer - 1];
        collectionTime += pPointer == 0 ? 0 : travel[pPointer - 1];
        collectionTime += gPointer == 0 ? 0 : travel[gPointer - 1];

        return collectionTime;
    }
}

public class Main {

    public static void main(String[] args) {
        String[] garbage = {"G", "G", "G", "GGM"};
        int[] travel = {2, 4, 3};
        System.out.println(new Solution().garbageCollection(garbage, travel));
    }
}