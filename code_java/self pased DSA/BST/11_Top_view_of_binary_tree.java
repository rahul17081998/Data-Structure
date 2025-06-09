/**
 * Problem: Print the top view of a binary tree.
 *
 * Definition:
 * The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
 * For each vertical line (i.e., horizontal distance from root), only the first node encountered in top-down level order traversal is included.
 *
 * Approach:
 * - We perform a level order traversal using a queue and track horizontal distances (hd).
 * - We use a TreeMap to store the first node for each horizontal distance.
 * - If a horizontal distance is encountered for the first time, we add the node's value to the map.
 * - Finally, we print the values in order of increasing horizontal distance (from left to right).
 *
 * Why this approach:
 * - Level order traversal ensures we visit the top-most node first for each vertical column.
 * - TreeMap keeps the keys sorted, so we get the left-to-right top view directly.
 *
 * This approach works because it captures the first node seen from top-down at every horizontal distance efficiently.
 * Time Complexity: O(n log n) due to TreeMap operations.
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

public class TopViewBinaryTree {

    static class Pair {
        Node node;
        int hd;

        Pair(Node node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }

    public static void topView(Node root) {
        if (root == null) return;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            Node curr = p.node;
            int hd = p.hd;

            map.putIfAbsent(hd, curr.key);

            if (curr.left != null) q.add(new Pair(curr.left, hd - 1));
            if (curr.right != null) q.add(new Pair(curr.right, hd + 1));
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
        root.right.left.left = new Node(16);

        topView(root);
    }
}
