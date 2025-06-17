/**
 * Problem Statement:
 * Implement a Circular Singly Linked List in Java supporting the following operations:
 * - Insert at the beginning (naive and efficient methods).
 * - Insert at the end (naive and efficient methods).
 * - Delete the head node (naive and efficient methods).
 * - Delete the Kth node.
 * - Print the list.
 *
 * Approach:
 * - Use a static nested Node class to represent each node.
 * - Maintain circular links while performing insertions and deletions.
 * - Use data swapping for efficient O(1) insertions/deletions.
 * - Use modular, static methods to perform operations.
 *
 * Time Complexity:
 * - Insert at Beginning (Naive): O(n)
 * - Insert at Beginning (Efficient): O(1)
 * - Insert at End (Naive): O(n)
 * - Insert at End (Efficient): O(1)
 * - Delete Head (Naive): O(n)
 * - Delete Head (Efficient): O(1)
 * - Delete Kth Node: O(k)
 * - Print List: O(n)
 *
 * Space Complexity:
 * - O(1) auxiliary space (no additional structures used).
 */
// Circular Linked List implementation in Java with all operations

class CircularLinkedList {
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    // Print circular linked list
    static void printList(Node head) {
        if (head == null) return;
        Node curr = head;
        do {
            System.out.print(curr.data + " ");
            curr = curr.next;
        } while (curr != head);
        System.out.println();
    }

    // Naive insert at beginning
    static Node insertBegin(Node head, int x) {
        Node temp = new Node(x);
        if (head == null) {
            temp.next = temp;
            return temp;
        }
        Node curr = head;
        while (curr.next != head) {
            curr = curr.next;
        }
        curr.next = temp;
        temp.next = head;
        return temp;
    }

    // Efficient insert at beginning
    static Node insertBegin2(Node head, int x) {
        Node temp = new Node(x);
        if (head == null) {
            temp.next = temp;
            return temp;
        }
        temp.next = head.next;
        head.next = temp;
        int t = head.data;
        head.data = temp.data;
        temp.data = t;
        return head;
    }

    // Naive insert at end
    static Node insertEnd(Node head, int x) {
        Node temp = new Node(x);
        if (head == null) {
            temp.next = temp;
            return temp;
        }
        Node curr = head;
        while (curr.next != head) {
            curr = curr.next;
        }
        curr.next = temp;
        temp.next = head;
        return head;
    }

    // Efficient insert at end
    static Node insertEnd2(Node head, int x) {
        Node temp = new Node(x);
        if (head == null) {
            temp.next = temp;
            return temp;
        }
        temp.next = head.next;
        head.next = temp;
        int t = head.data;
        head.data = temp.data;
        temp.data = t;
        return temp;
    }

    // Naive delete head
    static Node deleteHead(Node head) {
        if (head == null || head.next == head) return null;
        Node curr = head;
        while (curr.next != head) {
            curr = curr.next;
        }
        curr.next = head.next;
        head.next = null;
        return curr.next;
    }

    // Efficient delete head
    static Node deleteHead2(Node head) {
        if (head == null || head.next == head) return null;
        Node curr = head.next;
        int t = head.data;
        head.data = curr.data;
        curr.data = t;
        head.next = curr.next;
        return head;
    }

    // Delete Kth element
    static Node delKthElement(Node head, int k) {
        if (head == null) return null;
        if (k == 1) return deleteHead(head);

        Node curr = head;
        for (int i = 0; i < k - 2; i++) {
            curr = curr.next;
        }
        Node temp = curr.next;
        curr.next = temp.next;
        return head;
    }

    public static void main(String[] args) {
        Node head = null;

        head = insertBegin(head, 15);
        head = insertBegin(head, 5);
        head = insertBegin(head, 20);
        head = insertBegin(head, 18);
        System.out.println("insert at beginning (Naive):");
        printList(head);

        head = insertBegin2(head, 11);
        System.out.println("insert at beginning (Efficient):");
        printList(head);

        head = insertEnd(head, 100);
        System.out.println("insert 100 at end (Naive):");
        printList(head);

        head = insertEnd2(head, 90);
        System.out.println("insert 90 at end (Efficient):");
        printList(head);

        head = deleteHead(head);
        System.out.println("after deleting head (Naive):");
        printList(head);

        head = deleteHead2(head);
        System.out.println("after deleting head (Efficient):");
        printList(head);

        head = delKthElement(head, 3);
        System.out.println("after deleting 3rd element:");
        printList(head);
    }
}