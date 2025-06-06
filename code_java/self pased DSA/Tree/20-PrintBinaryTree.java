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

    // Print spaces
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
        int maxWidth = (int) Math.pow(2, h) * 2;

        while (level <= maxLevel) {
            int floor = maxLevel - level;
            int edgeLines = (int) Math.pow(2, (Math.max(floor - 1, 0)));
            int firstSpaces = (int) Math.pow(2, floor) - 1;
            int betweenSpaces = (int) Math.pow(2, floor + 1) - 1;

            // Print leading spaces
            printWhitespaces(firstSpaces);

            List<Node> newNodes = new ArrayList<>();
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

            // Print the branches lines
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

            nodes = newNodes;
            level++;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(3);
        root.left = new Node(1);
        root.right = new Node(4);
        root.left.left = new Node(3);
        root.right.left = new Node(1);
        root.right.right = new Node(5);

        printTree(root);
    }
}