/**
 * Problem: Search for a given key in a Binary Search Tree (BST).
 *
 * Definition:
 * A Binary Search Tree (BST) is a binary tree in which each node has the following properties:
 * - The left subtree of a node contains only nodes with keys less than the node’s key.
 * - The right subtree of a node contains only nodes with keys greater than the node’s key.
 *
 * Goal:
 * Given the root of a BST and a key, determine whether the key exists in the tree.
 *
 * Approach:
 * We use a recursive method to perform the search:
 * - If the current node is null, the key is not present.
 * - If the key equals the current node’s key, return true.
 * - If the key is less than the current node’s key, search the left subtree.
 * - Otherwise, search the right subtree.
 *
 * Why this approach:
 * This approach leverages the BST property to eliminate half of the tree at each step,
 * reducing the time complexity to O(h), where h is the height of the tree.
 * In a balanced BST, this gives O(log n) performance.
 *
 * This method is efficient because it narrows the search space using the inherent ordering of the BST.
 */

class Node {
    int key;
    Node left, right;

    Node(int key) {
        this.key = key;
        left = right = null;
    }
}

public class BSTSearch {

    // Recursive method to search in BST
    public static boolean search(Node root, int x) {
        if (root == null) return false;
        if (root.key == x) return true;
        else if (x < root.key) return search(root.left, x);
        else return search(root.right, x);
    }

    public static void main(String[] args) {
        Node root = new Node(15);
        root.left = new Node(10);
        root.right = new Node(20);
        root.left.left = new Node(8);
        root.left.right = new Node(12);

        int target = 10;
        System.out.println("Found " + target + "? " + search(root, target));
    }
}