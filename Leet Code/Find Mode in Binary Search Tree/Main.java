import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class Solution {
    HashMap<Integer, Integer> freqMap = new HashMap<>();

    public int[] findMode(TreeNode root) {
        dfs(root);

        int maxCount = 0;
        for (int value : freqMap.values())
            maxCount = Math.max(maxCount, value);

        List<Integer> modes = new ArrayList<>();
        for (var entry : freqMap.entrySet())
            if (maxCount == entry.getValue())
                modes.add(entry.getKey());

        int[] answer = new int[modes.size()];
        for (int i = 0; i < modes.size(); i++)
            answer[i] = modes.get(i);

        return answer;
    }

    private void dfs(TreeNode node) {
        if (node == null)
            return;

        freqMap.put(node.val, freqMap.getOrDefault(node.val, 0) + 1);

        dfs(node.left);
        dfs(node.right);
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                5,
                new TreeNode(
                        3,
                        new TreeNode(
                                2,
                                new TreeNode(1),
                                new TreeNode(2)
                        ),
                        new TreeNode(3)
                ),
                new TreeNode(
                        6,
                        new TreeNode(
                                8,
                                new TreeNode(8),
                                new TreeNode(
                                        10,
                                        new TreeNode(9),
                                        new TreeNode(10)
                                )
                        ),
                        null
                )
        );
        System.out.println(Arrays.toString(new Solution().findMode(root)));
    }
}

class TreeNode {
    protected TreeNode left, right;
    protected int val;

    public TreeNode(int val) {
        this.val = val;
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

/*
import java.util.Arrays;
import java.util.LinkedList;

class Solution {
    int maxCount = 0;
    int[] modes;
    LinkedList<Integer> modesLinkedList = new LinkedList<>();

    private boolean isLeaf(TreeNode node) {
        return node.right == null && node.left == null;
    }

    public int[] findMode(TreeNode root) {
        dfsMaxCount(root, Integer.MIN_VALUE, 0);
        dfs(root, Integer.MIN_VALUE, 0);

        int i = 0;
        modes = new int[modesLinkedList.size()];
        while (!modesLinkedList.isEmpty()) {
            modes[i++] = modesLinkedList.poll();
        }

        return modes;
    }

    private int dfs(TreeNode node, int parent, int count) {
        if (node == null)
            return count;

        if (node.value == parent)
            count++;
        else
            count = 0;

        int newCount = dfs(node.left, node.value, count) - count;
        count = dfs(node.right, node.value, count) + newCount;

        if (count == maxCount)
            modesLinkedList.add(node.value);

        return count;
    }

    private int dfsMaxCount(TreeNode node, int parent, int count) {
        if (node == null)
            return count;

        if (node.value == parent)
            count++;
        else
            count = ;
        maxCount = Math.max(maxCount, count);

        int newCount = dfs(node.left, node.value, count) - count;
        count = dfs(node.right, node.value, count) + newCount;

        if (count == maxCount)
            modesLinkedList.add(node.value);
        return count;
    }
}
 */