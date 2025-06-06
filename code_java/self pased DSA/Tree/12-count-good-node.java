/**
 * Problem Summary:
 * Given a binary tree, a node X is called "good" if in the path from the root to X,
 * there are no nodes with a value greater than X.
 * We need to return the count of such "good" nodes in the binary tree.
 *
 * Example:
 *          3
 *        /   \
 *       1     4
 *      /     / \
 *     3     1   5
 * Good nodes here are: 3 (root), 3 (left-left), 4, and 5 → total 4.
 *
 * Approach:
 * - Use a Preorder traversal (root -> left -> right) to explore the tree.
 * - Maintain a variable `maxValue` which tracks the maximum value seen on the path from root to current node.
 * - For each node:
 *     - If node's value >= maxValue, it is a "good" node.
 *     - Update maxValue for child calls to max(maxValue, node's value).
 * - Accumulate count of good nodes in a global or class variable.
 * - Return the count after traversal completes.
 *
 * Why this works:
 * - We carry forward the maximum value seen so far from root to the current node.
 * - If the current node's value is >= that max, it means no node in the path is greater.
 * - Hence the node qualifies as "good."
 *
 * Steps to solve:
 * 1. Initialize count to zero.
 * 2. Traverse the tree starting from root with maxValue = root.key.
 * 3. For each node, check if it's good and update count.
 * 4. Update maxValue for recursive calls.
 * 5. Continue until all nodes are processed.
 * 6. Return the count.
 *
 * Time Complexity: O(N), N = number of nodes (each node visited once).
 * Space Complexity: O(H), H = height of tree (recursion stack).
 */

class Node {
    int key;
    Node left, right;

    Node(int key) {
        this.key = key;
        left = right = null;
    }
}

public class Solution {
    int ans = 0;

    private void preOrder(Node root, int maxValue) {
        if (root == null) return;

        // If current node's value is greater or equal to maxValue, it's a good node
        if (root.key >= maxValue) {
            ans++;
        }

        // Update maxValue for the next recursive calls
        maxValue = Math.max(maxValue, root.key);

        preOrder(root.left, maxValue);
        preOrder(root.right, maxValue);
    }

    public int goodNode(Node root) {
        if (root == null) return 0;

        ans = 0;
        preOrder(root, root.key);
        return ans;
    }

    public static void main(String[] args) {
        // Construct the binary tree
        /*
                 3
               /   \
              1     4
             /     / \
            3     1   5
        */
        Node root = new Node(3);
        root.left = new Node(1);
        root.right = new Node(4);
        root.left.left = new Node(3);
        root.right.left = new Node(1);
        root.right.right = new Node(5);

        Solution solution = new Solution();
        System.out.println(solution.goodNode(root)); // Output: 4
    }
}