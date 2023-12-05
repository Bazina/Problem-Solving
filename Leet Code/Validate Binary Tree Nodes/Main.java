import java.util.Arrays;

class Solution {
    int[] leftChild, rightChild;
    boolean[] visited;
    private boolean isValidBinaryTree(int currentNode) {
        visited[currentNode] = true;

        int currentNodeRightChild = rightChild[currentNode];
        int currentNodeLeftChild = leftChild[currentNode];

        if (currentNodeRightChild != -1) {
            if (visited[currentNodeRightChild])
                return false;

            if (!isValidBinaryTree(currentNodeRightChild))
                return false;
        }

        if (currentNodeLeftChild != -1) {
            if (visited[currentNodeLeftChild])
                return false;

            return isValidBinaryTree(currentNodeLeftChild);
        }

        return true;
    }

    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int numberOfRoots = n, root = -1;
        int[] childParent = new int[n];
        Arrays.fill(childParent, -1);

        for (int i = 0; i < n; i++) {
            int currentLeftChild = leftChild[i], currentRightChild = rightChild[i];
            if (currentLeftChild != -1) {
                if (childParent[currentLeftChild] == -1) {
                    childParent[currentLeftChild] = i;
                    numberOfRoots--;
                } else
                    return false;
            }

            if (currentRightChild != -1) {
                if (childParent[currentRightChild] == -1) {
                    childParent[currentRightChild] = i;
                    numberOfRoots--;
                } else
                    return false;
            }
        }

        if (numberOfRoots != 1)
            return false;

        for (int i = 0; i < n; i++) {
            if (childParent[i] == -1) {
                root = i;
                break;
            }
        }

        this.leftChild = leftChild;
        this.rightChild = rightChild;
        visited = new boolean[n];

        if (!isValidBinaryTree(root))
            return false;

        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 7;
        int[] leftChild = {1, 3, -1, -1, -1, 6, -1};
        int[] rightChild = {2, 4, -1, -1, -1, -1, -1};
        System.out.println(new Solution().validateBinaryTreeNodes(n, leftChild, rightChild));
    }
}