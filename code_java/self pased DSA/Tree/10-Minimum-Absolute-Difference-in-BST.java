/**
 * Problem Summary:
 * Given a Binary Search Tree (BST), find the minimum absolute difference
 * between values of any two nodes in the tree.
 *
 * Approach:
 * Since the BST's in-order traversal yields nodes in sorted order,
 * we can perform an in-order traversal to visit nodes in ascending order.
 * By keeping track of the previous node's value during traversal,
 * we calculate the difference between the current node and the previous node,
 * and update the minimum difference found so far.
 * This approach runs in O(n) time where n is the number of nodes in the BST,
 * and uses O(h) space due to recursion stack, where h is the height of the tree.
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