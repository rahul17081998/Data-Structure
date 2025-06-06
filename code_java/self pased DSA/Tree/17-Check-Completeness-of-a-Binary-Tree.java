/**
 * Problem: Check if a Binary Tree is Complete
 * -------------------------------------------
 * A complete binary tree is defined as a binary tree where every level,
 * except possibly the last, is completely filled, and all nodes in the
 * last level are as far left as possible.
 *
 * Why this matters:
 * Complete binary trees are important in data structures like heaps,
 * where shape properties affect performance.
 *
 * Approach:
 * - Use a level-order traversal (BFS) to visit nodes level-by-level from left to right.
 * - Maintain a flag that indicates if a missing child (null) has been encountered.
 * - Once a missing child is found, all following nodes should not have any children.
 *   If a node after that has children, the tree is not complete.
 *
 * Why this works:
 * In a complete binary tree, nodes must fill every position from left to right
 * without gaps until the last level. Encountering a null child signals the start
 * of possible missing nodes. If any node afterwards has children, it violates completeness.
 *
 * Steps to solve:
 * 1. Initialize a queue and add the root.
 * 2. Traverse nodes level-wise:
 *    - If current node has a left child and flag is false, enqueue left child.
 *      Else, if flag is true but left child exists, return false.
 *    - If current node has a right child and flag is false, enqueue right child.
 *      Else, if flag is true but right child exists, return false.
 *    - If left or right child is missing, set flag true.
 * 3. If traversal finishes without violations, return true.
 *
 * Time Complexity: O(N), N = number of nodes (each node visited once)
 * Space Complexity: O(N) due to queue in worst case
 */

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) return true;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean flag = false; // Indicates a missing child has been seen

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            if (current.left != null) {
                if (flag) {
                    // Previously encountered a missing child, but found a left child now
                    return false;
                }
                queue.offer(current.left);
            } else {
                // Missing left child found, set flag
                flag = true;
            }

            if (current.right != null) {
                if (flag) {
                    // Previously encountered a missing child, but found a right child now
                    return false;
                }
                queue.offer(current.right);
            } else {
                // Missing right child found, set flag
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