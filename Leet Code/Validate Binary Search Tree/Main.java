class Solution {
    protected TreeNode root;

    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, null, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isValidBST(TreeNode root, TreeNode lastRootValue, int min, int max) {
        if (root == null)
            return true;

        if (root.val < min || root.val > max || (lastRootValue != null && root.val == lastRootValue.val))
            return false;

        return isValidBST(root.left, root, min, (root.val == Integer.MIN_VALUE) ? root.val : root.val - 1)
               && isValidBST(root.right, root,  (root.val == Integer.MAX_VALUE) ? root.val : root.val + 1, max);
    }

    static class TreeNode {
        protected TreeNode left, right;
        protected int val;

        public TreeNode(int value) {
            this.val = value;
        }

        public TreeNode(int value, TreeNode left, TreeNode right) {
            this.val = value;
            this.left = left;
            this.right = right;
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Solution tree = new Solution();
        tree.root = new Solution.TreeNode(2147483647, null, new Solution.TreeNode(-2147483648));
        System.out.println(tree.isValidBST(tree.root));
    }
}
