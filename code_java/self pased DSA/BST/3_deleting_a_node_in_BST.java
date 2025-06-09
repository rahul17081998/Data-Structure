/**
 * Problem: Delete a node from a Binary Search Tree (BST)
 *
 * Description:
 * Given a BST and a key 'x', delete the node with the key value 'x' while maintaining
 * the BST properties. A BST is a binary tree where:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree contains only nodes with keys greater than the node's key.
 *
 * Approach:
 * We use a recursive approach to delete a node from the BST.
 * - If the key is smaller than the current node, go to the left subtree.
 * - If the key is greater, go to the right subtree.
 * - If the key matches, handle three cases:
 *   1. Node has no left child: return right child.
 *   2. Node has no right child: return left child.
 *   3. Node has two children:
 *      - Find the inorder successor (smallest node in the right subtree).
 *      - Replace the current node’s key with the successor's key.
 *      - Recursively delete the successor node.
 *
 * Why this approach:
 * This recursive method preserves the BST properties while properly managing memory.
 * It efficiently handles all three deletion cases and uses the inorder successor
 * strategy to maintain correct order when the node has two children.
 *
 * This works because:
 * - Recursive calls ensure the correct subtree is modified.
 * - Replacing with inorder successor maintains the BST ordering.
 * - Leaf or one-child cases are resolved by directly reconnecting child nodes.
 */

import java.util.*;

class Node {
    int key;
    Node left, right;

    Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
    }
}

public class BSTDelete {

    // Inorder successor: leftmost node in right subtree
    public static Node getSuccessor(Node curr) {
        curr = curr.right;
        while (curr != null && curr.left != null) {
            curr = curr.left;
        }
        return curr;
    }

    // Delete a node in BST
    public static Node delNode(Node root, int x) {
        if (root == null)
            return root;

        if (x < root.key)
            root.left = delNode(root.left, x);
        else if (x > root.key)
            root.right = delNode(root.right, x);
        else {
            // Node with only one child or no child
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            } else {
                // Node with two children
                Node succ = getSuccessor(root);
                root.key = succ.key;
                root.right = delNode(root.right, succ.key);
            }
        }
        return root;
    }

    // Search in BST (recursive)
    public static boolean search(Node root, int x) {
        if (root == null)
            return false;
        if (x == root.key)
            return true;
        else if (x < root.key)
            return search(root.left, x);
        else
            return search(root.right, x);
    }

    // Inorder traversal
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

        int x = 15;
        root = delNode(root, x);

        System.out.println("Inorder traversal after deletion:");
        inorder(root);
    }
}