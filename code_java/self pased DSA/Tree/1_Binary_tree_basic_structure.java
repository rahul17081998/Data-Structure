// Summary:
// This Java program defines a Binary Tree structure and implements various operations such as:
// - Inorder, Preorder, and Postorder traversals
// - Level order traversal (standard and line by line)
// - Tree height calculation
// - Counting total number of nodes
// - Calculating the maximum node value
// - Printing the left view of the tree (recursive and iterative)
// - Checking the Children Sum Property
// - Efficient node count for Complete Binary Trees
// - Serialization of the tree using pre-order traversal

import java.util.*;

class Node {
    int key;
    Node left, right;

    Node(int key) {
        this.key = key;
        left = right = null;
    }
}

public class BinaryTree {
    static int maxLevel = 0;
    static final int EMPTY = -1;

    public static void inorder(Node root, int[] count) {
        if (root != null) {
            inorder(root.left, count);
            System.out.print(root.key + " ");
            count[0]++;
            inorder(root.right, count);
        }
    }

    public static void preorder(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    public static void postorder(Node root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.key + " ");
        }
    }

    public static int height(Node root) {
        if (root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }

    public static void printkDist(Node root, int k) {
        if (root == null) return;
        if (k == 0) System.out.print(root.key + " ");
        else {
            printkDist(root.left, k - 1);
            printkDist(root.right, k - 1);
        }
    }

    public static void levelTrav(Node root) {
        int h = height(root);
        for (int i = 0; i <= h; i++) {
            printkDist(root, i);
        }
    }

    public static void printLevel(Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node curr = q.poll();
            System.out.print(curr.key + " ");
            if (curr.left != null) q.add(curr.left);
            if (curr.right != null) q.add(curr.right);
        }
    }

    public static void printLevelorderLine(Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while (q.size() > 1) {
            Node curr = q.poll();
            if (curr == null) {
                System.out.println();
                q.add(null);
                continue;
            }
            System.out.print(curr.key + " ");
            if (curr.left != null) q.add(curr.left);
            if (curr.right != null) q.add(curr.right);
        }
    }

    public static void printLevelByLevel(Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                Node curr = q.poll();
                System.out.print(curr.key + " ");
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }
            System.out.println();
        }
    }

    public static int getSize(Node root) {
        if (root == null) return 0;
        return 1 + getSize(root.left) + getSize(root.right);
    }

    public static int maxNode(Node root) {
        if (root == null) return Integer.MIN_VALUE;
        return Math.max(root.key, Math.max(maxNode(root.left), maxNode(root.right)));
    }

    public static void printLeft(Node root, int level) {
        if (root == null) return;
        if (maxLevel < level) {
            System.out.print(root.key + " ");
            maxLevel = level;
        }
        printLeft(root.left, level + 1);
        printLeft(root.right, level + 1);
    }

    public static void printLeftView(Node root) {
        maxLevel = 0;
        printLeft(root, 1);
    }

    public static void printLeftM2(Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                Node curr = q.poll();
                if (i == 0) System.out.print(curr.key + " ");
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }
        }
    }

    public static boolean isCSum(Node root) {
        if (root == null || (root.left == null && root.right == null)) return true;
        int sum = 0;
        if (root.left != null) sum += root.left.key;
        if (root.right != null) sum += root.right.key;
        return (root.key == sum) && isCSum(root.left) && isCSum(root.right);
    }

    public static int countNode(Node root) {
        if (root == null) return 0;
        return 1 + countNode(root.left) + countNode(root.right);
    }

    public static int countNodeEff1(Node root) {
        int lh = 0, rh = 0;
        Node curr = root;
        while (curr != null) {
            lh++;
            curr = curr.left;
        }
        curr = root;
        while (curr != null) {
            rh++;
            curr = curr.right;
        }
        if (lh == rh) {
            return (int) Math.pow(2, lh) - 1;
        } else {
            return 1 + countNodeEff1(root.left) + countNodeEff1(root.right);
        }
    }

    public static void serialize(Node root, List<Integer> arr) {
        if (root == null) {
            arr.add(EMPTY);
            return;
        }
        arr.add(root.key);
        serialize(root.left, arr);
        serialize(root.right, arr);
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.right.left = new Node(40);
        root.right.right = new Node(50);

        int[] count1 = {0};
        System.out.print("\nInorder Traversal: ");
        inorder(root, count1);
        System.out.println("\nCount node: " + count1[0]);

        List<Integer> serialized = new ArrayList<>();
        serialize(root, serialized);
        System.out.println("Serialized Tree: " + serialized);
    }
}