/**
 * Problem: Pretty Print Binary Tree
 * ---------------------------------
 * Given a binary tree, print it in a visually structured manner,
 * showing the node values level by level along with branches ('/' and '\')
 * connecting parents to children.
 *
 * Why is this useful?
 * - Helps visualize the structure of the tree in console output.
 * - Useful for debugging or teaching binary tree concepts.
 *
 * Approach:
 * 1. Calculate the height of the tree to determine levels.
 * 2. For each level, print node values with appropriate spacing.
 * 3. Print branches connecting nodes to their children using '/' and '\'.
 * 4. Use a queue-like structure (here a list) to track nodes at each level.
 * 5. Carefully calculate spacing based on the level and maximum width,
 *    using powers of 2 to align nodes evenly.
 *
 * Why it works:
 * - Binary tree levels grow exponentially (2^level),
 *   so spacing uses powers of two to maintain alignment.
 * - Printing spaces before and between nodes ensures each node is
 *   positioned correctly horizontally.
 * - Branches are printed in multiple lines between levels,
 *   with spacing adjusted to connect parent nodes to children.
 *
 * Steps to solve:
 * - Compute height h.
 * - For each level from 1 to h:
 *     - Calculate spaces: leading (firstSpaces) and between nodes (betweenSpaces).
 *     - Print node values with spaces.
 *     - Print edge lines (branches) for this level.
 *     - Prepare nodes for next level (left and right children or nulls).
 * - Repeat until all levels printed.
 *
 * Time Complexity: O(N) to visit each node once.
 * Space Complexity: O(N) for storing nodes at each level.
 *
 * Example Output for the given tree:
 *
 *         3
 *       /   \
 *      1     4
 *     /     / \
 *    3     1   5
 *
 * Printed as:
 *
 *        3
 *       / \
 *      1   4
 *     /   / \
 *    3   1   5
 *
 * (The printed output includes spaces to align the nodes visually,
 *  and slashes (/) and backslashes (\) connect parents to their children.)
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

public class PrettyPrintBinaryTree {

    // Calculate height of tree
    static int height(Node root) {
        if (root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }

    // Print spaces helper
    static void printWhitespaces(int count) {
        for (int i = 0; i < count; i++) {
            System.out.print(" ");
        }
    }

    // Print the binary tree level by level with branches
    static void printTree(Node root) {
        int h = height(root);
        int maxLevel = h;
        List<Node> nodes = new ArrayList<>();
        nodes.add(root);

        int level = 1;

        while (level <= maxLevel) {
            int floor = maxLevel - level;
            int edgeLines = (int) Math.pow(2, Math.max(floor - 1, 0));
            int firstSpaces = (int) Math.pow(2, floor) - 1;
            int betweenSpaces = (int) Math.pow(2, floor + 1) - 1;

            // Print leading spaces before first node in this level
            printWhitespaces(firstSpaces);

            List<Node> newNodes = new ArrayList<>();
            // Print node keys
            for (Node node : nodes) {
                if (node != null) {
                    System.out.print(node.key);
                    newNodes.add(node.left);
                    newNodes.add(node.right);
                } else {
                    System.out.print(" ");
                    newNodes.add(null);
                    newNodes.add(null);
                }
                printWhitespaces(betweenSpaces);
            }
            System.out.println();

            // Print branch lines '/' and '\' connecting nodes to children
            for (int i = 1; i <= edgeLines; i++) {
                for (int j = 0; j < nodes.size(); j++) {
                    printWhitespaces(firstSpaces - i);
                    if (nodes.get(j) == null) {
                        // print spaces for missing nodes
                        printWhitespaces(edgeLines * 2 + i + 1);
                        continue;
                    }

                    if (nodes.get(j).left != null)
                        System.out.print("/");
                    else
                        System.out.print(" ");

                    printWhitespaces(i * 2 - 1);

                    if (nodes.get(j).right != null)
                        System.out.print("\\");
                    else
                        System.out.print(" ");

                    printWhitespaces(edgeLines * 2 - i);
                }
                System.out.println();
            }

            nodes = newNodes; // move to next level nodes
            level++;
        }
    }

    public static void main(String[] args) {
        // Example tree:
        //        3
        //       / \
        //      1   4
        //     /   / \
        //    3   1   5
        Node root = new Node(3);
        root.left = new Node(1);
        root.right = new Node(4);
        root.left.left = new Node(3);
        root.right.left = new Node(1);
        root.right.right = new Node(5);

        printTree(root);
    }
}