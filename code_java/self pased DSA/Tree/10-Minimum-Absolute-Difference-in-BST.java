/**
 * Problem Summary:
 * ----------------
 * We are given a Binary Search Tree (BST), and we want to find the minimum absolute difference
 * between values of any two nodes in that tree.
 *
 * Why is this problem interesting?
 * - The BST property guarantees that for any node, all nodes in the left subtree are smaller
 *   and all nodes in the right subtree are larger.
 * - This sorted order of nodes can be exploited to find minimum differences efficiently.
 *
 * Algorithm and Approach:
 * -----------------------
 * 1. In-order traversal of a BST:
 *    - Visiting nodes in the order: left child -> node -> right child.
 *    - This traversal produces nodes in sorted ascending order.
 *    - So, if we list out node values during in-order traversal, the list will be sorted.
 *
 * 2. Minimum difference in a sorted list:
 *    - The minimum absolute difference between any two numbers in a sorted list
 *      must be found between some pair of adjacent elements.
 *    - Hence, we only need to check consecutive nodes during the traversal instead of all pairs.
 *
 * 3. Tracking state during traversal:
 *    - Maintain a variable `lastNodeValue` to store the value of the previously visited node.
 *    - Maintain `minDiff` initialized to a large value (e.g., Integer.MAX_VALUE).
 *    - For each node visited:
 *       * Calculate the difference between current node's value and `lastNodeValue`.
 *       * Update `minDiff` if the current difference is smaller.
 *       * Update `lastNodeValue` to current node’s value.
 *
 * 4. Result:
 *    - After the traversal completes, `minDiff` holds the minimum absolute difference between any two nodes.
 *
 * Why This Works:
 * ---------------
 * - Because the BST in-order traversal outputs sorted values, checking adjacent nodes guarantees
 *   that no smaller difference exists beyond these neighbors.
 * - If we compared non-adjacent nodes, the difference would only be equal or larger.
 * - This reduces a potential O(n^2) problem (checking all pairs) to O(n).
 *
 * Complexity:
 * -----------
 * - Time Complexity: O(n), where n is the number of nodes, as each node is visited once.
 * - Space Complexity: O(h), where h is the height of the tree, due to recursion stack space.
 */

public class Solution {
    private Integer lastNodeValue = null; // To store the value of previously visited node
    private int minDiff = Integer.MAX_VALUE; // To store the minimum difference found

    // Helper function for inorder traversal
    private void inorder(TreeNode root) {
        if (root == null) return;

        // Traverse left subtree
        inorder(root.left);

        // If lastNodeValue is not null, update the minDiff
        if (lastNodeValue != null) {
            minDiff = Math.min(minDiff, Math.abs(root.val - lastNodeValue));
        }

        // Update lastNodeValue to current node's value
        lastNodeValue = root.val;

        // Traverse right subtree
        inorder(root.right);
    }

    public int getMinimumDifference(TreeNode root) {
        inorder(root);
        return minDiff;
    }
}

// Definition for a binary tree node (commonly used in LeetCode problems)
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}