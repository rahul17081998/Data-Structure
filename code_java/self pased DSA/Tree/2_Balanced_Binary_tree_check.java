/*
    Problem Statement:
    ------------------
    Given a binary tree, determine whether it is balanced or not.
    A balanced binary tree is defined as a binary tree in which the height difference between
    the left subtree and right subtree of every node is at most 1.

    Why this problem matters:
    -------------------------
    Balanced trees ensure operations like insertion, deletion, and search
    have good time complexity, close to O(log n). An unbalanced tree can degrade to O(n).

    Approaches:
    -----------
    1. Naive Approach (O(n^2) time complexity):
       - For every node, calculate the height of left and right subtrees.
       - Check if the difference in heights is more than 1.
       - Recursively check if left and right subtrees are balanced.
       - Height calculation is done repeatedly for same nodes, causing O(n^2) complexity.

    2. Efficient Approach (O(n) time complexity):
       - Use a bottom-up recursion that returns the height of the subtree if balanced,
         otherwise returns -1 to indicate imbalance.
       - For each node:
         * Recursively get heights of left and right subtrees.
         * If either subtree is unbalanced (returns -1), propagate -1 upwards.
         * If height difference is more than 1, return -1.
         * Else return the max height + 1.
       - This avoids repeated height calculations by combining balance check and height computation.

    Why Efficient Approach Works:
    -----------------------------
    - Each node is visited once.
    - Height and balanced status computed simultaneously.
    - Early termination possible on imbalance detection.

    Steps to solve:
    ---------------
    1. If node is null, return height 0.
    2. Recursively compute left subtree height.
       - If -1, propagate -1 up immediately.
    3. Recursively compute right subtree height.
       - If -1, propagate -1 up immediately.
    4. Check height difference; if > 1, return -1.
    5. Else return max of left and right heights + 1.
    6. The tree is balanced if the final call does not return -1.

    Time Complexity:
    ----------------
    - Naive approach: O(n^2), as height computed repeatedly.
    - Efficient approach: O(n), each node processed once.

    Space Complexity:
    -----------------
    - O(h), where h is height of tree due to recursion stack.

*/

import java.util.*;

class Node {
    int key;
    Node left, right;

    Node(int k) {
        key = k;
        left = right = null;
    }
}

public class BalancedBinaryTreeCheck {

    // Method to calculate height of binary tree (naive)
    static int height(Node root) {
        if (root == null)
            return 0;
        else
            return Math.max(height(root.left), height(root.right)) + 1;
    }

    // Naive approach: O(n^2) time complexity
    static boolean isBalanced(Node root) {
        if (root == null)
            return true;

        int lh = height(root.left);
        int rh = height(root.right);

        return Math.abs(lh - rh) <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }

    // Efficient approach: returns height if balanced, else -1
    static int isBalancedEff(Node root) {
        if (root == null)
            return 0;

        int lh = isBalancedEff(root.left);
        if (lh == -1)  // Left subtree is not balanced
            return -1;

        int rh = isBalancedEff(root.right);
        if (rh == -1)  // Right subtree is not balanced
            return -1;

        if (Math.abs(lh - rh) > 1)  // Current node is not balanced
            return -1;

        return Math.max(lh, rh) + 1; // Return height if balanced
    }

    // Wrapper method to return boolean from efficient approach
    static boolean check(Node root) {
        return isBalancedEff(root) != -1;
    }

    public static void main(String[] args) {
        // Construct sample tree:
        //          10
        //         /  \
        //       20    30
        //            /  \
        //          40    50

        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.right.left = new Node(40);
        root.right.right = new Node(50);

        System.out.println("Is Binary tree Balanced (Naive method): " + isBalanced(root));
        System.out.println("Is Binary tree Balanced (Efficient method returns height or -1): " + isBalancedEff(root));
        System.out.println("Is Binary tree Balanced (Efficient method boolean): " + check(root));
    }
}