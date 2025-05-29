/*
 * Program to find the maximum width of a binary tree.
 * The width of a level is defined as the number of nodes at that level.
 * This implementation uses level-order traversal (BFS) with a queue
 * to compute the maximum width across all levels of the tree.
 */

import java.util.LinkedList;
import java.util.Queue;

class Node {
    int key;
    Node left, right;

    Node(int key) {
        this.key = key;
        left = right = null;
    }
}

public class MaxWidthBinaryTree {

    public static int maxWidth(Node root) {
        if (root == null) return 0;

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        int res = 0;
        while (!q.isEmpty()) {
            int count = q.size();
            res = Math.max(res, count);
            for (int i = 0; i < count; i++) {
                Node curr = q.poll();
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(25);
        root.left.right = new Node(23);
        root.right.left = new Node(40);
        root.right.right = new Node(50);

        System.out.println(maxWidth(root));
    }
}