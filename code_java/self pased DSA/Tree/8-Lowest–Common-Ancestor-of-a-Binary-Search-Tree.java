/**
 * Problem Summary:
 * ----------------
 * Given a Binary Search Tree (BST) and two nodes p and q, find their Lowest Common Ancestor (LCA).
 * The LCA is the lowest node in the tree that has both p and q as descendants.
 * A node can be a descendant of itself.
 *
 * Approach:
 * ---------
 * 1. Find the path from the root to node p and store it in a list.
 * 2. Find the path from the root to node q and store it in another list.
 * 3. Use a HashSet to store all nodes in p's path for O(1) lookup.
 * 4. Traverse q's path from the end towards the start, and find the first node
 *    that is also in p's path. This node is the LCA.
 *
 * Why this approach works:
 * ------------------------
 * - Both paths start at the root and end at p and q respectively.
 * - The LCA is the deepest node where the two paths intersect.
 * - Storing paths explicitly lets us find the intersection efficiently.
 *
 * Time Complexity:
 * ----------------
 * O(N) to find both paths in worst case.
 *
 * Space Complexity:
 * -----------------
 * O(N) for storing paths.
 */

import java.util.*;

public class Solution {
    // Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }

    /**
     * Helper method to find the path from root to target node.
     * It uses preorder traversal to store nodes along the path.
     *
     * @param root Current node in traversal.
     * @param target Node to find.
     * @param path Temporary path from root to current node.
     * @param ans Final path from root to target.
     */
    private void preOrder(TreeNode root, TreeNode target, List<TreeNode> path, List<TreeNode> ans) {
        if (root == null) return;

        path.add(root);

        if (root == target) {
            ans.addAll(path); // Copy current path to answer
            return;
        }

        preOrder(root.left, target, path, ans);
        preOrder(root.right, target, path, ans);

        // Backtrack: remove current node before returning to previous level
        path.remove(path.size() - 1);
    }

    /**
     * Main method to find LCA.
     * Steps:
     * - Find path from root to p
     * - Find path from root to q
     * - Use a HashSet for quick membership test of nodes in p's path
     * - Traverse q's path from the end and return the first common node found
     *
     * @param root Root of the BST
     * @param p Node p
     * @param q Node q
     * @return Lowest Common Ancestor node
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> path1 = new ArrayList<>();
        List<TreeNode> path2 = new ArrayList<>();
        List<TreeNode> tempPath = new ArrayList<>();

        preOrder(root, p, tempPath, path1);
        tempPath.clear();
        preOrder(root, q, tempPath, path2);

        Set<TreeNode> set = new HashSet<>(path1);

        for (int i = path2.size() - 1; i >= 0; i--) {
            if (set.contains(path2.get(i))) {
                return path2.get(i);
            }
        }

        return null; // No common ancestor found (should not happen)
    }
}