/**
 * Problem: Check if a binary tree is a Binary Search Tree (BST).
 *
 * Definition:
 * A Binary Search Tree (BST) is a binary tree in which for each node,
 * all elements in the left subtree are smaller and all elements in the right subtree are greater.
 *
 * Approach:
 * We use a recursive method that checks if each node's value is within a valid range.
 * - For the left child, the valid range is (min, node.key)
 * - For the right child, the valid range is (node.key, max)
 * - Initially, the range is (-∞, ∞) for the root.
 *
 * Why this approach:
 * This approach ensures that every node satisfies the BST property relative to all its ancestors, not just its immediate parent.
 *
 * This approach works because it verifies the global BST constraint using range limits passed during recursion.
 * Time complexity: O(n), where n is the number of nodes.
 */

import java.util.*;

class Node {
    int key;
    Node left, right;

    Node(int key) {
        this.key = key;
        left = right = null;
    }
}

public class CheckForBST {

    public static boolean isBST(Node root, int min, int max) {
        if (root == null) {
            return true;
        }
        if (root.key <= min || root.key >= max) {
            return false;
        }
        return isBST(root.left, min, root.key) && isBST(root.right, root.key, max);
    }

    public static void inorder(Node root, List<Integer> result) {
        if (root != null) {
            inorder(root.left, result);
            System.out.print(root.key + " ");
            result.add(root.key);
            inorder(root.right, result);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(15);
        root.left = new Node(5);
        root.right = new Node(20);
        root.left.left = new Node(3);
        root.right.right = new Node(80);
        root.right.left = new Node(18);
        root.right.left.left = new Node(16);

        System.out.println("Tree is BST or not: " + isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE));
        List<Integer> v = new ArrayList<>();
        inorder(root, v);
    }
}