/*
Problem Summary:
Given a binary tree, a node X is called "good" if in the path from the root to X, 
there are no nodes with a value greater than X. 
We need to return the count of such "good" nodes in the binary tree.

Approach:
- Perform a pre-order traversal of the tree.
- Keep track of the maximum value encountered from the root to the current node.
- For each node, if its value is greater than or equal to the maximum value so far, it is a "good" node.
- Update the maximum value while traversing.
- Accumulate the count of "good" nodes.
- Return the total count after the traversal is complete.

Time Complexity: O(N), where N is the number of nodes in the tree.
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