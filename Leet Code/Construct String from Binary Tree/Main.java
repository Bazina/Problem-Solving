class Solution {
    StringBuilder answer = new StringBuilder();
    public String tree2str(TreeNode root) {
        preorderTraversal(root);

        return answer.toString();
    }

    private void preorderTraversal(TreeNode node) {
        if (node == null)
            return;

        answer.append(node.val);

        if (node.left != null) {
            answer.append('(');
            preorderTraversal(node.left);
            answer.append(')');
        }

        if (node.right != null) {
            if (node.left == null)
                answer.append('(').append(')');
            answer.append('(');
            preorderTraversal(node.right);
            answer.append(')');
        }
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                1,
                new TreeNode(2, null, new TreeNode(4)),
                new TreeNode(3)
        );
        System.out.println(new Solution().tree2str(root));
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