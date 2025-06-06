/*
 * Problem Summary:
 * ----------------
 * Given two binary trees, `root` and `subRoot`, determine if `subRoot` is a subtree of `root`.
 * A subtree of `root` is defined as a tree consisting of a node in `root` and all of its descendants.
 * Note: `root` itself can be considered a subtree of itself.
 *
 * Approach:
 * ---------
 * 1. Define a helper method `isSameTree()` to check if two trees are identical in structure and node values.
 * 2. Traverse the main tree `root` using preorder traversal.
 * 3. At each node of `root`, check if the subtree rooted at that node matches `subRoot` using `isSameTree()`.
 * 4. If a match is found, return true immediately.
 * 5. If no match is found after traversing all nodes, return false.
 *
 * Why this approach works:
 * ------------------------
 * - Checking every subtree of `root` ensures we don't miss any potential match.
 * - `isSameTree()` does a deep comparison of two trees to verify if they are identical.
 * - Preorder traversal visits every node, enabling us to check every subtree root.
 *
 * Complexity:
 * -----------
 * Time: O(m * n) in the worst case, where:
 * - m = number of nodes in `root`
 * - n = number of nodes in `subRoot`
 * Because for each node in `root`, we might compare it to `subRoot` (which takes O(n) time).
 *
 * Space: O(h) due to recursion stack, where h is height of `root`.
 */

public class Solution {
    private boolean flag = false;

    private boolean isSameTree(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;

        return root1.val == root2.val &&
                isSameTree(root1.left, root2.left) &&
                isSameTree(root1.right, root2.right);
    }

    private void preOrderTraversal(TreeNode root, TreeNode subRoot) {
        if (root == null) return;

        if (isSameTree(root, subRoot)) {
            flag = true;
            return;
        }

        preOrderTraversal(root.left, subRoot);
        preOrderTraversal(root.right, subRoot);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        flag = false;
        preOrderTraversal(root, subRoot);
        return flag;
    }

    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
}