/**
 * Problem Summary:
 * ----------------
 * Given the root of a binary tree, return the length of the longest path where each node in the path has the same value.
 * The path may or may not pass through the root. The length is the number of edges between nodes.
 *
 * Example:
 *         5
 *        / \
 *       4   5
 *      / \   \
 *     1   1   5
 * The longest univalue path is 2 (edges connecting the right subtree nodes with value 5).
 *
 * Approach:
 * ----------------
 * - Use Depth-First Search (DFS) to traverse the tree starting from root.
 * - For each node:
 *     - Recursively get the longest univalue path length from left child (left).
 *     - Recursively get the longest univalue path length from right child (right).
 *     - If left child exists and has the same value as current node, leftPath = left + 1; else 0.
 *     - If right child exists and has the same value as current node, rightPath = right + 1; else 0.
 * - Update the global max length as max(maxLen, leftPath + rightPath).
 *   (This accounts for the path passing through current node combining left and right).
 * - Return the max of leftPath and rightPath because when returning to parent,
 *   only one side can be extended upwards.
 *
 * Why this approach works:
 * ----------------
 * - It correctly counts consecutive edges with same value downward from each node.
 * - Combining left and right paths at each node covers paths that pass through the node.
 * - It efficiently computes answers bottom-up, avoiding repeated calculations.
 *
 * Time Complexity:
 * ----------------
 * O(N), where N is the number of nodes, as each node is visited once.
 *
 * Space Complexity:
 * ----------------
 * O(H), where H is the height of the tree, due to recursion stack.
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

        // Recursively find longest same-value paths in left and right subtrees
        int left = dfs(node.left);
        int right = dfs(node.right);

        int leftPath = 0, rightPath = 0;

        // Check if left child continues the univalue path
        if (node.left != null && node.left.val == node.val) {
            leftPath = left + 1;
        }

        // Check if right child continues the univalue path
        if (node.right != null && node.right.val == node.val) {
            rightPath = right + 1;
        }

        // Update max length if path through this node is longer
        maxLen = Math.max(maxLen, leftPath + rightPath);

        // Return max path length extending from current node to its parent
        return Math.max(leftPath, rightPath);
    }
}