/**
 * Problem: Print the bottom view of a binary tree.
 *
 * Definition:
 * The bottom view of a binary tree consists of the nodes that are visible when the tree is viewed from the bottom.
 * For each vertical line (i.e., horizontal distance from root), the last node encountered in level order traversal is included.
 *
 * Approach:
 * - Perform a level order traversal (BFS) using a queue that stores pairs of (node, horizontal distance).
 * - Maintain a TreeMap where key = horizontal distance and value = node's key.
 * - For each node encountered during BFS, update the TreeMap entry for its horizontal distance.
 * - The TreeMap ensures the horizontal distances are sorted.
 * - After traversal, print the values of the TreeMap from leftmost to rightmost.
 *
 * Why this approach:
 * - Level order traversal guarantees that nodes encountered later (deeper or to the right) overwrite earlier nodes for the same horizontal distance.
 * - TreeMap naturally keeps the entries in sorted order for printing left to right.
 *
 * This approach works because it ensures that the most bottom-level node at each horizontal distance is recorded.
 * Time Complexity: O(n log n), where n is the number of nodes (due to TreeMap operations).
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

public class BottomViewBinaryTree {

    static class Pair {
        Node node;
        int hd;

        Pair(Node node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }

    public static void bottomView(Node root) {
        if (root == null) return;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            Node curr = p.node;
            int hd = p.hd;

            map.put(hd, curr.key); // overwrite existing entries

            if (curr.left != null)
                q.add(new Pair(curr.left, hd - 1));
            if (curr.right != null)
                q.add(new Pair(curr.right, hd + 1));
        }

        for (int val : map.values()) {
            System.out.print(val + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node root = new Node(15);
        root.left = new Node(5);
        root.right = new Node(20);
        root.left.left = new Node(3);
        root.right.right = new Node(80);
        root.right.left = new Node(18);
        root.left.right = new Node(16);

        bottomView(root);
    }
}
