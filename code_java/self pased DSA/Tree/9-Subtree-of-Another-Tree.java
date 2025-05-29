/*
 * Problem Summary:
 * Given two binary trees, root and subRoot, determine if subRoot is a subtree of root.
 * A subtree of a binary tree 'root' is a tree consisting of a node in 'root' and all of 
 * its descendants. The tree 'root' could also be considered as a subtree of itself.
 *
 * Approach:
 * 1. We first check if two trees are identical by comparing nodes recursively using isSameTree().
 * 2. We traverse the main tree (root) in preorder fashion.
 * 3. At each node, we check if the subtree rooted at that node is identical to subRoot.
 * 4. If yes, return true.
 * 5. If we traverse the entire tree without a match, return false.
 *
 * This approach uses recursion to compare trees and traverses all nodes of root in worst case,
 * leading to a time complexity roughly O(m * n), where m and n are the number of nodes in root and subRoot.
 */

public class Solution {
    private boolean flag = false;

    // Check if two trees are identical (structure and node values)
    private boolean isSameTree(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;

        return root1.val == root2.val &&
               isSameTree(root1.left, root2.left) &&
               isSameTree(root1.right, root2.right);
    }

    // Preorder traversal of root tree to find if any subtree matches subRoot
    private void preOrderTraversal(TreeNode root, TreeNode subRoot) {
        if (root == null) return;

        // Check if current subtree is same as subRoot
        if (isSameTree(root, subRoot)) {
            flag = true;
            return;
        }

        // Recur on left and right subtree
        preOrderTraversal(root.left, subRoot);
        preOrderTraversal(root.right, subRoot);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        flag = false;  // reset flag before traversal
        preOrderTraversal(root, subRoot);
        return flag;
    }

    // Definition for a binary tree node (usually provided by the platform)
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
}