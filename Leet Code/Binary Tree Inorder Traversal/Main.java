import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        inorderTraversal(root, answer);
        return answer;
    }

    private void inorderTraversal(TreeNode root, List<Integer> answer) {
        if (root == null)
            return;

        inorderTraversal(root.left, answer);
        answer.add(root.val);
        inorderTraversal(root.right, answer);
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                1,
                new TreeNode(2, null, new TreeNode(4)),
                new TreeNode(3)
        );
        System.out.println(new Solution().inorderTraversal(root));
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