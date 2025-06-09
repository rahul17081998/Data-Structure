/**
 * Problem: Insert a node into a Binary Search Tree (BST)
 *
 * Description:
 * Given a Binary Search Tree (BST) and a value 'x', insert a node with value 'x'
 * into the BST such that the properties of BST are maintained.
 *
 * A BST is a binary tree in which each node has at most two children,
 * and for each node:
 * - All the keys in the left subtree are less than the node's key.
 * - All the keys in the right subtree are greater than the node's key.
 *
 * Approach:
 * We use both recursive and iterative approaches to insert a new value into the BST.
 *
 * Recursive:
 * - If the tree is empty, return a new node as the root.
 * - If the value already exists, do not insert and return the existing node.
 * - If the value is less than the current node's key, recursively insert into the left subtree.
 * - If the value is greater than the current node's key, recursively insert into the right subtree.
 *
 * Iterative:
 * - Traverse the tree until we find the correct place to insert the new node.
 * - Avoid inserting duplicate values.
 *
 * Why these approaches:
 * - Recursive approach is clean and directly maps the logical structure of a BST.
 * - Iterative approach can avoid function call overhead for very deep trees.
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

public class BSTInsertion {
    static List<Integer> v = new ArrayList<>();

    // Insert in BST: Recursive approach
    public static Node insert(Node root, int x) {
        if (root == null)
            return new Node(x);
        if (x == root.key)
            return root;
        else if (x < root.key)
            root.left = insert(root.left, x);
        else
            root.right = insert(root.right, x);
        return root;
    }

    // Insert in BST: Iterative approach
    public static Node insertIterative(Node root, int x) {
        Node newNode = new Node(x);
        if (root == null)
            return newNode;

        Node parent = null, curr = root;
        while (curr != null) {
            parent = curr;
            if (x == curr.key)
                return root; // duplicate, do not insert
            else if (x < curr.key)
                curr = curr.left;
            else
                curr = curr.right;
        }

        if (x < parent.key)
            parent.left = newNode;
        else
            parent.right = newNode;

        return root;
    }

    // Inorder traversal
    public static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.key + " ");
            v.add(root.key);
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

        // Recursive insertion
        root = insert(root, 10);

        // Iterative insertion (uncomment to test)
        // root = insertIterative(root, 10);

        inorder(root);
        System.out.println("\nprint nodes: ");
        for (int item : v) {
            System.out.print(item + " ");
        }
    }
}