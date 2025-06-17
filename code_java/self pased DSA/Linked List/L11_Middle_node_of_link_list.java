
/**
 * Problem Statement:
 * Find the middle element of a singly linked list.
 * - If the list has an odd number of elements, return the middle.
 * - If the list has an even number, return the second middle element.
 *
 * Approaches:
 * 1. Naive Method:
 *    - Count the number of nodes (O(n)).
 *    - Traverse again to the middle node (O(n)).
 *    - Total Time: O(n), Space: O(1)
 *
 * 2. Efficient Method (Two-pointer approach):
 *    - Move 'slow' pointer one node at a time, 'fast' pointer two at a time.
 *    - When 'fast' reaches the end, 'slow' will be at the middle.
 *    - Time: O(n), Space: O(1)
 *
 * Example:
 * Input: 10 -> 20 -> 30 -> 40 -> 34
 * Output: 30
 *
 * Input: 20 -> 14 -> 68 -> 5 -> 24 -> 18
 * Output: 5 (second mid)
 */
public class MiddleOfLinkedList {

    static class Node {
        int data;
        Node next;

        Node(int x) {
            data = x;
            next = null;
        }
    }

    // Efficient solution using slow and fast pointers
    static void middleEfficient(Node head) {
        if (head == null) return;
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        System.out.println("Middle element is (Efficient method): " + slow.data);
    }

    // Naive solution using two passes
    static void middle(Node head) {
        if (head == null) return;

        int size = 0;
        Node curr = head;
        while (curr != null) {
            size++;
            curr = curr.next;
        }

        System.out.println("\nSize: " + size);

        curr = head;
        for (int i = 0; i < size / 2; i++) {
            curr = curr.next;
        }
        System.out.println("Middle element is: " + curr.data);
    }

    // Insert from beginning
    static Node insertBegin(Node head, int x) {
        Node temp = new Node(x);
        temp.next = head;
        return temp;
    }

    // Print list
    static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertBegin(head, 40);
        head = insertBegin(head, 30);
        head = insertBegin(head, 38);
        head = insertBegin(head, 20);
        head = insertBegin(head, 5);
        head = insertBegin(head, 10);

        printList(head);
        middle(head);
        middleEfficient(head);
    }
}