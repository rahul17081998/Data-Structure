/**
 * Problem: Find the floor of a given integer 'x' in a Binary Search Tree (BST).
 *
 * Definition of Floor in BST:
 * Floor of 'x' in a BST is the greatest value in the BST which is less than or equal to 'x'.
 *
 * Approach:
 * We use an iterative traversal of the BST starting from the root.
 * At each node:
 * - If the node's key is equal to 'x', then it is the floor.
 * - If the node's key is greater than 'x', move to the left subtree (as all values in right are even greater).
 * - If the node's key is less than 'x', store this node as a potential result and move to the right subtree (hoping to find a closer value).
 *
 * Why this approach:
 * This leverages the properties of BST where the left child is less than the node and right child is greater.
 * The traversal is efficient, with a time complexity of O(h), where h is the height of the tree.
 * In a balanced BST, this gives O(log n) performance.
 *
 * This approach works because at each step we make a decision that discards half of the tree,
 * reducing the search space optimally while keeping track of the best floor value found so far.
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

public class FloorInBST {

    public static Node floor(Node root, int x) {
        Node res = null;
        while (root != null) {
            if (root.key == x) {
                return root;
            } else if (root.key > x) {
                root = root.left;
            } else {
                res = root;
                root = root.right;
            }
        }
        return res;
    }

    public static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.key + " ");
            inorder(root.right);
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

        Node result = floor(root, 17);
        if (result != null) {
            System.out.println("Floor of 17 is: " + result.key);
        } else {
            System.out.println("No floor found");
        }

        // inorder(root); // optional: to verify BST structure
    }
}