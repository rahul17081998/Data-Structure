/**
 * Problem Summary:
 * Given a Binary Search Tree (BST), find the lowest common ancestor (LCA) of two given nodes p and q.
 * The LCA is defined as the lowest node in the BST that has both p and q as descendants
 * (a node can be a descendant of itself).
 *
 * Approach:
 * 1. Traverse the tree from root to find the path for node p.
 * 2. Traverse the tree from root to find the path for node q.
 * 3. Store these paths in two separate lists.
 * 4. Use a HashSet to store nodes from the path of p for quick lookup.
 * 5. Traverse the path of q from the end towards the start and find the first node
 *    that is also present in the path of p — this node is the LCA.
 *
 * This approach works by explicitly storing the paths to both nodes and then
 * finding the deepest common node on these paths.
 */

import java.util.*;

public class Solution {
    // Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }

    // Helper method to find the path from root to target node and store it in 'path'
    private void preOrder(TreeNode root, TreeNode target, List<TreeNode> path, List<TreeNode> ans) {
        if (root == null) return;

        path.add(root);

        if (root == target) {
            ans.addAll(path);
            return;
        }

        preOrder(root.left, target, path, ans);
        preOrder(root.right, target, path, ans);

        // Backtrack: remove current node from path when returning to previous node
        path.remove(path.size() - 1);
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> path1 = new ArrayList<>();
        List<TreeNode> path2 = new ArrayList<>();
        List<TreeNode> tempPath = new ArrayList<>();

        // Find path from root to p
        preOrder(root, p, tempPath, path1);
        // Clear tempPath and reuse for q
        tempPath.clear();
        // Find path from root to q
        preOrder(root, q, tempPath, path2);

        // Insert all nodes of path1 into a HashSet for O(1) lookup
        Set<TreeNode> set = new HashSet<>(path1);

        // Traverse path2 from the end to start to find first common node in path1
        for (int i = path2.size() - 1; i >= 0; i--) {
            if (set.contains(path2.get(i))) {
                return path2.get(i);
            }
        }

        return null; // LCA not found (should not happen given valid inputs)
    }
}