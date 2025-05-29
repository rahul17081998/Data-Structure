/**
 * Problem Summary:
 * ----------------
 * Given the root of a Binary Search Tree (BST) and an integer k,
 * find the kth smallest element in the BST.
 *
 * A BST is a binary tree where the left subtree contains only nodes with values less than the root,
 * and the right subtree only nodes with values greater than the root.
 *
 * The in-order traversal of a BST yields values in sorted (ascending) order.
 * So, the kth element in this traversal is the kth smallest element.
 *
 * Approach:
 * ---------
 * - Use in-order traversal (Left -> Node -> Right).
 * - Maintain a counter that increments as we visit nodes.
 * - When the counter reaches k, record the current node’s value as the result.
 * - Terminate traversal once the kth smallest is found to save time.
 */

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    private int count = 0;
    private int result = -1;

    public int kthSmallest(TreeNode root, int k) {
        inorder(root, k);
        return result;
    }

    private void inorder(TreeNode node, int k) {
        if (node == null) return;

        // Traverse left subtree
        inorder(node.left, k);

        // Visit current node
        count++;
        if (count == k) {
            result = node.val;
            return; // Early exit
        }

        // Traverse right subtree
        inorder(node.right, k);
    }
}