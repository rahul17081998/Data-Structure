
/**
 * Problem: Compute the vertical sum in a binary tree.
 *
 * Definition:
 * The vertical sum of a binary tree is the sum of all nodes that are located in the same vertical line when the tree is viewed from the top.
 * Each node is assigned a horizontal distance (hd) from the root node. The root has hd = 0.
 * - hd for left child = parent hd - 1
 * - hd for right child = parent hd + 1
 *
 * Approach:
 * We perform a recursive traversal (preorder traversal) of the binary tree.
 * While visiting each node, we maintain a map from hd to sum of nodes at that hd.
 * We add the value of the current node to the corresponding hd in the map.
 *
 * Why this approach:
 * This approach ensures that we process every node once and collect all vertical sums in a single traversal.
 * The TreeMap in Java keeps keys (horizontal distances) in sorted order for final output.
 *
 * This approach works efficiently because it leverages a map to accumulate vertical sums and
 * uses recursion with hd tracking to assign nodes to their respective vertical lines.
 * Time Complexity: O(n), where n is the number of nodes.
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

public class VerticalSumBinaryTree {

    public static void vSum(Node root, int hd, TreeMap<Integer, Integer> map) {
        if (root == null) return;
        vSum(root.left, hd - 1, map);
        map.put(hd, map.getOrDefault(hd, 0) + root.key);
        vSum(root.right, hd + 1, map);
    }

    public static void vSumMain(Node root) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        vSum(root, 0, map);
        System.out.println("Vertical sum:");
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            System.out.print(entry.getValue() + " ");
        }
        System.out.println();
    }

    public static void inorder(Node root, List<Integer> v) {
        if (root != null) {
            inorder(root.left, v);
            System.out.print(root.key + " ");
            v.add(root.key);
            inorder(root.right, v);
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

        vSumMain(root);
        // List<Integer> v = new ArrayList<>();
        // inorder(root, v);
    }
}