/**
 * Problem: Add One Row to Tree
 * ------------------------------------------------
 * Given the root of a binary tree and two integers val and depth,
 * add a new row of nodes with value val at the given depth.
 *
 * Notes:
 * - The root node is considered at depth 1.
 * - If depth == 1, create a new root with value val and set the original tree as its left subtree.
 * - Otherwise, for each node at depth-1, add two new nodes with value val as its left and right children.
 *   The original left subtree becomes the left child of the new left node,
 *   and the original right subtree becomes the right child of the new right node.
 *
 * Approach:
 * - If depth is 1, create a new root node with value val and set the existing root as its left child.
 * - Else, perform a level order traversal (BFS) to reach nodes at depth-1.
 * - For each node at depth-1, insert new nodes with value val as their left and right children.
 * - Attach the original children of those nodes to the newly inserted nodes accordingly.
 *
 * Why it works:
 * - Level order traversal ensures we stop exactly at the nodes whose children must be replaced.
 * - Inserting new nodes at depth-1 preserves the tree structure below the new row.
 *
 * Steps:
 * 1. Check if depth == 1, handle as special case.
 * 2. Use a queue for BFS traversal to reach level depth-1.
 * 3. At depth-1, iterate over all nodes:
 *    - Save references to current left and right children.
 *    - Create new nodes with val as left and right children.
 *    - Attach original children to new nodes accordingly.
 * 4. Return the updated root.
 *
 * Time Complexity: O(N), where N is number of nodes, since we may visit each node once.
 * Space Complexity: O(W), W = maximum width of the tree (queue size in BFS).
 */

import java.util.Queue;
import java.util.LinkedList;

public class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        // Special case: add new root
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int currentDepth = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();

            // When current depth is depth - 1, insert the new row
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
                // Finished adding new row, break
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