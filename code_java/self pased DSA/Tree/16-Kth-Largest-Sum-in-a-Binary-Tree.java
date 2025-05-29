/**
 * Problem Summary:
 * Given the root of a binary tree and a positive integer k,
 * the level sum of the tree is defined as the sum of all node values at the same depth level.
 * The task is to find the kth largest level sum in the tree.
 * If the tree has fewer than k levels, return -1.
 *
 * Approach:
 * 1. Use a level order traversal (BFS) to traverse the tree level by level.
 * 2. For each level, calculate the sum of node values.
 * 3. Store all level sums in a list.
 * 4. Sort the list of sums in descending order.
 * 5. Return the kth largest sum if it exists, otherwise return -1.
 */

import java.util.*;

public class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        if (root == null) return -1;

        List<Long> levelSum = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                sum += node.val;

                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }

            levelSum.add(sum);
        }

        if (levelSum.size() < k) return -1;

        // Sort sums in descending order
        Collections.sort(levelSum, Collections.reverseOrder());

        return levelSum.get(k - 1);
    }
}

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}