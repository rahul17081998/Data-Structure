/*
    Problem: Convert Binary Tree to Doubly Linked List (DLL)
    ------------------------------------------------------------------
    Given a Binary Tree, convert it to a Doubly Linked List (DLL) in-place.
    The DLL should have nodes in the same order as the in-order traversal
    of the binary tree.

    Approach:
    - Perform an in-order traversal of the binary tree.
    - Use a static pointer 'prev' to track the previously visited node.
    - For each visited node:
        * Set its left pointer to 'prev' (previous node in DLL).
        * If 'prev' is not null, set 'prev's right pointer to the current node.
    - Maintain a 'head' pointer to the first node of the DLL (leftmost node).
    - The DLL is formed as the traversal progresses.
*/

class Node {
    int key;
    Node left, right;

    public Node(int key) {
        this.key = key;
        this.left = this.right = null;
    }
}

public class ConvertBinaryTreeToDoublyLinkedList {

    static Node prev = null;

    // Function to convert Binary Tree to Doubly Linked List
    static Node BTToDLL(Node root) {
        if (root == null) return null;

        Node head = BTToDLL(root.left);

        if (prev == null) {
            head = root; // This is the leftmost node
        } else {
            root.left = prev;
            prev.right = root;
        }

        prev = root;

        BTToDLL(root.right);

        return head;
    }

    // Function to print the Doubly Linked List
    static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.key + " ");
            curr = curr.right;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(25);
        root.left.right = new Node(23);
        root.right.left = new Node(40);
        root.right.right = new Node(50);

        Node head = BTToDLL(root);
        printList(head);
    }
}