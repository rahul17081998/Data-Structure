/*
    This Java program defines a binary tree and checks whether it is balanced.
    A balanced binary tree is one where the height difference between the left and right subtree
    of every node is at most 1.

    The program includes:
    - A Node class to define tree nodes.
    - A method to calculate the height of the tree.
    - A naive approach to check if a binary tree is balanced (O(n^2) time complexity).
    - An efficient approach to check if a binary tree is balanced (O(n) time complexity).
    - A main method to demonstrate usage with a sample tree.
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

    // Method to calculate height of binary tree
    static int height(Node root) {
        if (root == null)
            return 0;
        else
            return Math.max(height(root.left), height(root.right)) + 1;
    }

    // Naive approach: O(n^2) time
    static boolean isBalanced(Node root) {
        if (root == null)
            return true;

        int lh = height(root.left);
        int rh = height(root.right);

        return Math.abs(lh - rh) <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }

    // Efficient approach: O(n) time
    static int isBalancedEff(Node root) {
        if (root == null)
            return 0;

        int lh = isBalancedEff(root.left);
        if (lh == -1)
            return -1;

        int rh = isBalancedEff(root.right);
        if (rh == -1)
            return -1;

        if (Math.abs(lh - rh) > 1)
            return -1;

        return Math.max(lh, rh) + 1;
    }

    static boolean check(Node root) {
        return isBalancedEff(root) != -1;
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.right.left = new Node(40);
        root.right.right = new Node(50);

        System.out.println("Is Binary tree Balanced (Naive method): " + isBalanced(root));
        System.out.println("Is Binary tree Balanced (Efficient method return height or -1): " + isBalancedEff(root));
        System.out.println("Is Binary tree Balanced (Efficient method return boolean): " + check(root));
    }
}