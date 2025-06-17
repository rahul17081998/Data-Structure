// Circular linked list creation and traversal (method 1 and 2)

/**
 * Problem Statement:
 * Implement a circular singly linked list in Java with the following:
 * - A Node class containing an integer and a reference to the next node.
 * - Manual construction of a circular linked list with four nodes.
 * - Two traversal methods:
 *   1. Using a do-while loop.
 *   2. Using a for loop.
 *
 * Approach:
 * - Define a Node class with a constructor.
 * - Create and connect four nodes so that the last node points back to the head.
 * - Implement two display functions for the circular linked list.
 *
 * Time Complexity:
 * - Traversal: O(n), where n is the number of nodes.
 *
 * Space Complexity:
 * - O(1) auxiliary space.
 */
public class CircularLinkedList {
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    // Method 1: do-while loop traversal
    static void printList(Node head) {
        if (head == null) return;
        Node curr = head;
        do {
            System.out.print(curr.data + " ");
            curr = curr.next;
        } while (curr != head);
        System.out.println();
    }

    // Method 2: for loop traversal
    static void displayList(Node head) {
        if (head == null) return;
        System.out.print(head.data + " ");
        for (Node p = head.next; p != head; p = p.next) {
            System.out.print(p.data + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Proper creation of circular linked list
        Node head = new Node(10);
        Node second = new Node(5);
        Node third = new Node(20);
        Node fourth = new Node(15);

        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = head; // Complete the circular linkage

        printList(head);    // Method 1 traversal
        displayList(head);  // Method 2 traversal
    }
}