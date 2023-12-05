import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> largestValues(TreeNode root) {
        if (root == null)
            return new ArrayList<>();

        List<Integer> largestValues = new ArrayList<>();
        dfs(root, largestValues, 0);

        return largestValues;
    }

    private void dfs(TreeNode node, List<Integer> largestValues, int depth) {
        if (node == null)
            return;

        if (largestValues.size() == depth)
            largestValues.add(node.val);
        else if (largestValues.get(depth) < node.val)
            largestValues.set(depth, node.val);

        dfs(node.left, largestValues, depth + 1);
        dfs(node.right, largestValues, depth + 1);
    }
}

class TreeNode {
    protected TreeNode left, right;
    protected int val;

    public TreeNode() {
    }

    public TreeNode(int value) {
        this.val = value;
    }

    public TreeNode(int value, TreeNode left, TreeNode right) {
        this.val = value;
        this.left = left;
        this.right = right;
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                1,
                new TreeNode(
                        3,
                        new TreeNode(5),
                        new TreeNode(3)
                ),
                new TreeNode(
                        2,
                        null,
                        new TreeNode(9)
                )
        );
        System.out.println(new Solution().largestValues(root));
    }
}

/* BFS
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<Integer> largestValues(TreeNode root) {
        if (root == null)
            return new ArrayList<>();

        int level = 0, max = Integer.MIN_VALUE;
        List<Integer> largestValues = new ArrayList<>();
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair currentNode = queue.poll();

            if (level + 1 == currentNode.level) {
                largestValues.add(max);
                level++;
                max = Integer.MIN_VALUE;
            }
            max = Math.max(currentNode.node.val, max);

            if (currentNode.node.left != null)
                queue.add(new Pair(currentNode.node.left, currentNode.level + 1));
            if (currentNode.node.right != null)
                queue.add(new Pair(currentNode.node.right, currentNode.level + 1));
        }
        largestValues.add(max);

        return largestValues;
    }
}

class Pair {
    TreeNode node;
    int level;

    public Pair(TreeNode node, int level) {
        this.node = node;
        this.level = level;
    }
}
 */