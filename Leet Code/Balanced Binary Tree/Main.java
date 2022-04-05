class Solution {
    static class TreeNode {
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

    protected TreeNode root;

    private boolean isLeaf(TreeNode node) {
        return node.right == null && node.left == null;
    }

    private int height(TreeNode root) {
        if (root == null) return -1;

        if (isLeaf(root)) return 0;

        return 1 + Math.max(height(root.right), height(root.left));
    }

    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;

        int balanceFactor = Math.abs(height(root.left) - height(root.right));

        return balanceFactor <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }
}

public class Main {

    public static void main(String[] args) {
        Solution tree = new Solution();
        tree.root = new Solution.TreeNode(3,
                new Solution.TreeNode(9),
                new Solution.TreeNode(20,
                        new Solution.TreeNode(15),
                        new Solution.TreeNode(7)));
        System.out.println(tree.isBalanced(tree.root));
    }
}
