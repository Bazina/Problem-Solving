class Solution {
    int count = 0;

    public int averageOfSubtree(TreeNode root) {
        dfs(root, new int[]{0, 0});

        return count;
    }

    private int[] dfs(TreeNode node, int[] state) {
        if (node == null)
            return new int[]{0, 0};

        int[] leftState = dfs(node.left, new int[]{0, 0});
        int[] rightState = dfs(node.right, new int[]{0, 0});

        state[0] = leftState[0] + rightState[0] + node.val;
        state[1] = leftState[1] + rightState[1] + 1;

        if (state[0] / state[1] == node.val)
            count++;

        return state;
    }
}

public class Main {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                4,
                new TreeNode(
                        8,
                        new TreeNode(
                                0,
                                new TreeNode(3),
                                null
                        ),
                        new TreeNode(
                                1,
                                null,
                                new TreeNode(2)
                        )
                ),
                new TreeNode(
                        5,
                        null,
                        new TreeNode(6)
                )
        );
        System.out.println(new Solution().averageOfSubtree(root));
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