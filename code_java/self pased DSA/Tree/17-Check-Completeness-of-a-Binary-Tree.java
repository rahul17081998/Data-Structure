/**
 * Given the root of a binary tree, determine if it is a complete binary tree.
 *
 * Problem Summary:
 * A complete binary tree is a binary tree in which every level, except possibly the last,
 * is completely filled, and all nodes in the last level are as far left as possible.
 * The last level can have between 1 and 2^h nodes (inclusive), where h is the height of the tree.
 *
 * Approach:
 * - Use a level order traversal (BFS) to visit nodes level by level from left to right.
 * - During traversal, once a node is found that does not have a left or right child,
 *   set a flag to mark that no more child nodes should appear after this.
 * - If after this flag is set, any node has children, it means the tree is not complete.
 * - If we traverse all nodes without violation, the tree is complete.
 */

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) return true;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean flag = false; // Flag to indicate missing child detected

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            if (current.left != null) {
                if (flag) {
                    // If previously a missing child was found but current node has left child,
                    // then tree is not complete
                    return false;
                }
                queue.offer(current.left);
            } else {
                // Missing left child, set flag
                flag = true;
            }

            if (current.right != null) {
                if (flag) {
                    // If previously a missing child was found but current node has right child,
                    // then tree is not complete
                    return false;
                }
                queue.offer(current.right);
            } else {
                // Missing right child, set flag
                flag = true;
            }
        }
        return true;
    }
}

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}