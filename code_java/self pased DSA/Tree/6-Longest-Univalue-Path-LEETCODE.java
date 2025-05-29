/*
 Problem Summary:
 Given the root of a binary tree, return the length of the longest path where each node in the path has the same value.
 This path may or may not pass through the root. The length is the number of edges between nodes.

 Approach:
 - Use Depth-First Search (DFS) to traverse the tree.
 - At each node, recursively find the longest univalue path in the left and right subtrees.
 - If the child node has the same value as the current node, include it in the current path; otherwise, reset to 0.
 - Keep track of the maximum path length found during traversal.
 - Return the length of the longest path found.
*/

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int maxLen = 0;

    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return maxLen;
    }

    private int dfs(TreeNode node) {
        if (node == null) return 0;

        int left = dfs(node.left);
        int right = dfs(node.right);

        int leftPath = 0, rightPath = 0;

        if (node.left != null && node.left.val == node.val) {
            leftPath = left + 1;
        }

        if (node.right != null && node.right.val == node.val) {
            rightPath = right + 1;
        }

        maxLen = Math.max(maxLen, leftPath + rightPath);
        return Math.max(leftPath, rightPath);
    }
}