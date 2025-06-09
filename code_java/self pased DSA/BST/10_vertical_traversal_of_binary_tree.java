/**
 * Problem: Perform vertical traversal of a binary tree.
 *
 * Definition:
 * In vertical traversal, nodes are grouped and printed according to their horizontal distance (hd) from the root.
 * The root node has an hd of 0. For any node:
 * - hd of left child = hd of parent - 1
 * - hd of right child = hd of parent + 1
 *
 * Output is printed column by column from leftmost hd to rightmost hd.
 *
 * Approach:
 * - Use a TreeMap to map horizontal distances (hd) to lists of node values.
 * - Use a queue for level-order traversal, storing pairs of (node, hd).
 * - While traversing, store the node values in the corresponding hd list in the map.
 * - Finally, iterate over the TreeMap to print the vertical order.
 *
 * Why this approach:
 * - TreeMap maintains the keys (hd values) in sorted order, ensuring the vertical lines are printed left to right.
 * - Level-order traversal ensures that we visit nodes in top-down order for each vertical.
 *
 * This approach works because it combines breadth-first traversal with ordered mapping to properly group and order the nodes.
 * Time complexity: O(n log n) due to map operations.
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

public class VerticalTraversal {

    public static void vTraversal(Node root) {
        TreeMap<Integer, List<Integer>> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            Node curr = p.node;
            int hd = p.hd;
            map.putIfAbsent(hd, new ArrayList<>());
            map.get(hd).add(curr.key);

            if (curr.left != null)
                q.add(new Pair(curr.left, hd - 1));
            if (curr.right != null)
                q.add(new Pair(curr.right, hd + 1));
        }

        for (List<Integer> list : map.values()) {
            for (int val : list) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    static class Pair {
        Node node;
        int hd;

        Pair(Node node, int hd) {
            this.node = node;
            this.hd = hd;
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

        vTraversal(root);
    }
}