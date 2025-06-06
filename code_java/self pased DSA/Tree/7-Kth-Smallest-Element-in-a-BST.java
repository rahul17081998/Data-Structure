/**
 * Problem Summary:
 * ----------------
 * Given the root of a Binary Search Tree (BST) and an integer k,
 * find the kth smallest element in the BST.
 *
 * A BST has the property that the left subtree of a node contains only nodes
 * with values less than the node's value, and the right subtree contains nodes with values greater.
 *
 * In-order traversal of BST yields nodes in ascending sorted order.
 * So the kth node visited in in-order traversal is the kth smallest element.
 *
 * Approach:
 * ---------
 * - Perform in-order traversal (Left -> Node -> Right) because it visits nodes in ascending order.
 * - Maintain a counter to count how many nodes have been visited so far.
 * - When the counter equals k, record the node's value as the answer.
 * - Stop further traversal once kth smallest is found to optimize performance.
 *
 * Why this approach works:
 * -----------------------
 * - In-order traversal naturally sorts BST elements.
 * - Counting nodes during traversal tracks when we reach the kth smallest.
 * - Early stopping avoids unnecessary visits.
 *
 * Time Complexity:
 * ----------------
 * O(H + k), where H is the height of the tree. In worst case O(N).
 *
 * Space Complexity:
 * -----------------
 * O(H) due to recursion stack, where H is height of BST.
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

        inorder(node.left, k);

        count++;
        if (count == k) {
            result = node.val;
            return; // Early exit once kth smallest is found
        }

        inorder(node.right, k);
    }
}