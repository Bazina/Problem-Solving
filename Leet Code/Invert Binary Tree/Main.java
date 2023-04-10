import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    protected TreeNode left, right;
    protected int value;

    public TreeNode(int value) {
        this.value = value;
    }

    public TreeNode(int value, TreeNode left, TreeNode right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return null;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            TreeNode right = node.right;
            TreeNode left = node.left;

            if (right != null)
                queue.add(right);
            if (left != null)
                queue.add(left);

            node.left = right;
            node.right = left;
        }

        return root;
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode tree = new TreeNode(4,
                new TreeNode(
                        2,
                        new TreeNode(1),
                        new TreeNode(3)
                ),
                new TreeNode(
                        7,
                        new TreeNode(6),
                        new TreeNode(9)
                )
        );
        System.out.println(new Solution().invertTree(tree));
    }
}
