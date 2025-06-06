/**
 * Problem Summary:
 * ----------------
 * Given the root of a binary tree where each node has a unique value from 1 to n,
 * and a sequence "voyage" representing the desired preorder traversal of the tree,
 * you can "flip" a node by swapping its left and right children.
 * The goal is to flip the minimum number of nodes so that the preorder traversal matches the voyage.
 * Return a list of the values of all flipped nodes.
 * If it's impossible to match the voyage, return a list containing only -1.
 *
 * Approach:
 * ----------------
 * - Use a recursive Depth-First Search (DFS) to simulate the preorder traversal.
 * - Maintain an index pointer to track the current position in the voyage array.
 * - For each node:
 *   - Check if the node's value matches voyage[index].
 *     - If not, return false immediately (no way to match voyage).
 *   - Increment index (move to next expected node in voyage).
 *   - Check if left child exists and matches voyage[index].
 *     - If it doesn't match, it means we need to flip this node (swap left and right children).
 *     - Record the current node's value in the result list to indicate a flip.
 *     - Visit the right child first, then the left child.
 *   - Otherwise, visit left child first, then right child.
 * - Continue recursively until entire tree is traversed.
 * - If all nodes match voyage correctly, return the flip list.
 * - Otherwise, return [-1].
 *
 * Why This Approach Works:
 * -------------------------
 * - Preorder traversal order is root -> left -> right.
 * - By matching voyage step-by-step, we ensure correctness.
 * - The flip is needed only if the next expected node is on the right child.
 * - Recursively verifying both subtrees confirms if the entire tree matches the voyage.
 *
 * Time Complexity:
 * -----------------
 * O(n) - We visit each node once.
 *
 * Space Complexity:
 * ------------------
 * O(n) - Recursion stack in worst case (skewed tree) + result list.
 */

import java.util.*;

public class Solution {
    private int index;
    private List<Integer> result;
    private int[] voyage;

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        this.index = 0;
        this.result = new ArrayList<>();
        this.voyage = voyage;

        if (!dfs(root)) {
            return Arrays.asList(-1);
        }
        return result;
    }

    private boolean dfs(TreeNode root) {
        if (root == null) return true;
        if (root.val != voyage[index]) return false;

        index++;

        if (root.left != null && root.left.val != voyage[index]) {
            // Flip required: visit right child first, then left child
            result.add(root.val);
            return dfs(root.right) && dfs(root.left);
        } else {
            // No flip required: visit left child then right child
            return dfs(root.left) && dfs(root.right);
        }
    }
}

// TreeNode definition (usually provided in coding platforms)
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}