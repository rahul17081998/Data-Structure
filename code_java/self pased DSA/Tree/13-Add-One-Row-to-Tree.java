/**
 * Given the root of a binary tree and two integers val and depth,
 * add a row of nodes with value val at the given depth.
 *
 * Note:
 * - The root node is at depth 1.
 * - If depth == 1, create a new root with value val, and set the original tree as its left subtree.
 * - Otherwise, for each node at depth-1, add two new nodes with value val as its left and right children.
 *   The original left subtree becomes the left child of the new left node.
 *   The original right subtree becomes the right child of the new right node.
 *
 * Approach:
 * - If depth is 1, create a new root and attach the original root as its left child.
 * - Otherwise, use a level-order traversal (BFS) to reach nodes at depth-1.
 * - For each node at depth-1, insert new nodes with value val as their left and right children.
 * - Attach the original children of those nodes to the new nodes accordingly.
 */

public class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        // Corner case: if depth == 1, new root with val, original tree as left subtree
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }

        // Level order traversal to reach depth-1
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int currentDepth = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();

            // If currentDepth is depth-1, add new row
            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; i++) {
                    TreeNode node = queue.poll();

                    // Insert new node as left child
                    TreeNode tempLeft = node.left;
                    node.left = new TreeNode(val);
                    node.left.left = tempLeft;

                    // Insert new node as right child
                    TreeNode tempRight = node.right;
                    node.right = new TreeNode(val);
                    node.right.right = tempRight;
                }
                // After adding the row, we are done
                break;
            } else {
                // Traverse to next level
                for (int i = 0; i < size; i++) {
                    TreeNode node = queue.poll();
                    if (node.left != null) queue.offer(node.left);
                    if (node.right != null) queue.offer(node.right);
                }
                currentDepth++;
            }
        }
        return root;
    }
}