class Solution {
    protected int cost = 0;

    class RedBlackTree<T extends Comparable<T>> {

        public class RBTNode {
            protected RBTNode leftChild, rightChild, parent;
            protected boolean color;
            protected T value;
            protected int leftSize = 0, rightSize = 0, duplicated;

            public RBTNode(T value) {
                this.value = value;
                this.leftChild = this.rightChild = NIL;
                this.parent = null;
                this.color = true;
                this.duplicated = 1;
            }
        }

        private RBTNode root;
        private final RBTNode NIL;
        protected int size = 0;

        public RedBlackTree() {
            this.NIL = new RBTNode(null);
            this.NIL.duplicated = 0;
            this.NIL.color = false;
            this.NIL.rightChild = null;
            this.NIL.leftChild = null;
            this.NIL.parent = null;
            this.root = this.NIL;
        }

        public void insert(T value) {
            RBTNode node = new RBTNode(value);
            RBTNode curr = root;
            size++;
            int mini = 0, maxi = 0;

            if (root == NIL) {
                root = node;
                root.color = false;
                cost = 0;
                return;
            }

            while (true) {
                int cmp = value.compareTo(curr.value);
                if (cmp > 0) {
                    if (curr.rightChild == NIL) {
                        curr.rightChild = node;
                        curr.rightChild.parent = curr;
                        curr.rightChild.color = true;
                        curr.rightSize++;
                        mini += curr.leftSize + curr.duplicated;
                        break;
                    }
                    curr.rightSize++;
                    mini += curr.leftSize + curr.duplicated;
                    curr = curr.rightChild;
                } else if (cmp < 0) {
                    if (curr.leftChild == NIL) {
                        curr.leftChild = node;
                        curr.leftChild.parent = curr;
                        curr.leftChild.color = true;
                        curr.leftSize++;
                        maxi += curr.rightSize + curr.duplicated;
                        break;
                    }
                    curr.leftSize++;
                    maxi += curr.rightSize + curr.duplicated;
                    curr = curr.leftChild;
                } else {
                    cost = (cost + Math.min(mini + curr.leftSize, maxi + curr.rightSize)) % 1000000007;
                    curr.duplicated++;
                    return;
                }
            }

            cost = (cost + Math.min(mini, maxi)) % 1000000007;
            RBInsertFixUp(node);
        }

        private void RBInsertFixUp(RBTNode node) {
            while (node.parent.color) {
                if (node.parent == node.parent.parent.leftChild) {
                    RBTNode uncle = node.parent.parent.rightChild;

                    if (uncle.color) {
                        uncle.color = node.parent.color = false;
                        node.parent.parent.color = true;
                        node = node.parent.parent;
                    } else {
                        if (node == node.parent.rightChild) {
                            node = node.parent;
                            leftRotate(node);
                        }

                        node.parent.color = false;
                        node.parent.parent.color = true;
                        rightRotate(node.parent.parent);
                    }
                } else {
                    RBTNode uncle = node.parent.parent.leftChild;

                    if (uncle.color) {
                        uncle.color = node.parent.color = false;
                        node.parent.parent.color = true;
                        node = node.parent.parent;
                    } else {
                        if (node == node.parent.leftChild) {
                            node = node.parent;
                            rightRotate(node);
                        }

                        node.parent.color = false;
                        node.parent.parent.color = true;
                        leftRotate(node.parent.parent);
                    }
                }

                if (node == root)
                    break;
            }
            root.color = false;
        }

        private int size(RBTNode node) {
            if (node == null) {
                return 0;
            }
            return node.leftSize + node.rightSize + node.duplicated;
        }

        /***
         * Implementation of right rotation
         * @param root root of the subtree to be rotated right
         */
        private void rightRotate(RBTNode root) {
            RBTNode newRoot = root.leftChild;
            root.leftChild = newRoot.rightChild;
            root.leftSize = size(newRoot.rightChild);

            if (newRoot.rightChild != NIL)
                newRoot.rightChild.parent = root;

            newRoot.parent = root.parent;
            if (root.parent == null)
                this.root = newRoot;
            else if (root == root.parent.rightChild)
                root.parent.rightChild = newRoot;
            else
                root.parent.leftChild = newRoot;

            newRoot.rightChild = root;
            newRoot.rightSize = size(root);
            root.parent = newRoot;
        }

        /***
         * Implementation of left rotation
         * @param root root of the subtree to be rotated left
         */
        private void leftRotate(RBTNode root) {
            RBTNode newRoot = root.rightChild;
            root.rightChild = newRoot.leftChild;
            root.rightSize = size(newRoot.leftChild);

            if (newRoot.leftChild != NIL)
                newRoot.leftChild.parent = root;

            newRoot.parent = root.parent;
            if (root.parent == null)
                this.root = newRoot;
            else if (root == root.parent.leftChild)
                root.parent.leftChild = newRoot;
            else
                root.parent.rightChild = newRoot;


            newRoot.leftChild = root;
            newRoot.leftSize = size(root);
            root.parent = newRoot;
        }
    }

    public int createSortedArray(int[] instructions) {
        RedBlackTree<Integer> redBlackTree = new RedBlackTree<>();
        for (int instruction : instructions) {
            redBlackTree.insert(instruction);
        }

        return cost;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] instructions = {1,3,3,3,2,4,2,1,2};
        Solution solution = new Solution();
        System.out.println(solution.createSortedArray(instructions));
    }
}
