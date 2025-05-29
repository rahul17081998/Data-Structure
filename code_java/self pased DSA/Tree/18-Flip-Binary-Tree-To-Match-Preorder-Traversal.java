/*
Problem Summary:
You are given the root of a binary tree where each node has a unique value from 1 to n.
You are also given a sequence "voyage" which represents the desired preorder traversal of the tree.
You can "flip" a node by swapping its left and right children.
The goal is to flip the minimum number of nodes so that the preorder traversal of the tree matches the given voyage.
Return a list of the values of all flipped nodes. If it's impossible to match the voyage, return a list containing only -1.

Approach:
- Use a recursive DFS to traverse the tree in preorder.
- Maintain an index to track the current position in the voyage array.
- At each node, check if the node value matches voyage[index].
- If not, return false (impossible to match).
- Otherwise, increment index and check the left child.
- If the left child's value does not match voyage[index], flip the current node by visiting right first then left.
- Record the node's value in the flip result list when a flip occurs.
- Continue recursively, and if any step fails, return false.
- If the entire traversal matches the voyage, return the list of flipped nodes.

Time Complexity: O(n), where n is the number of nodes.
Space Complexity: O(n) due to recursion stack and result list.
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
            // Need to flip: visit right subtree first, then left subtree
            result.add(root.val);
            return dfs(root.right) && dfs(root.left);
        } else {
            // No flip needed
            return dfs(root.left) && dfs(root.right);
        }
    }
}

// Definition for a binary tree node (usually provided in coding platforms).
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}