/**
 * Problem Statement:
 * Implement a Circular Doubly Linked List that supports:
 * - Insertion at the head.
 * - Insertion at the end.
 * - Traversal and printing of the list.
 *
 * Approach:
 * - Use a `Node` struct with `data`, `next`, and `prev` pointers.
 * - For insertion at head:
 *   - Handle the empty list case.
 *   - Insert before the current head and adjust circular links.
 * - For insertion at end:
 *   - Use the `prev` pointer of the head to reach the tail.
 *   - Link the new node between the tail and the head.
 * - For traversal, use a `do-while` loop to navigate until we return to the head.
 *
 * Time Complexity:
 * - Insertion at head: O(1)
 * - Insertion at end: O(1)
 * - Traversal: O(n)
 *
 * Space Complexity:
 * - Auxiliary space: O(1)
 */
/* example-1
I/P:    10->20->30->40
        x=25
O/P:    10->20->25->30->40

example-2
I/P:    10->25
        x=5
O/P:    5->10->25
*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    // creating a Node
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
// Sorted Insert in a Singly Linked List
Node *insertAtCorrect(Node *head,int x)
{
    Node *temp=new Node(x);
    // if no element
    if(head==NULL) return temp;
    // insert at first place
    if((head->data)>x)
    {
        temp->next=head;
        return temp;
    }
    // insert after head pos and also tail case
    Node *curr=head;
    while(curr->next != NULL && curr->next->data < x )
    {
        curr=curr->next;
    }
    temp->next =curr->next;
    curr->next=temp;
    return head;
    
}
// Insert from Begining in linked list
Node *insertBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    return temp;
}
// Display the elements of linked list
void printList(Node *head)
{
    while(head!=NULL)
    {
        cout<<(head->data)<<" ";
        head=head->next;
    }
}
// Main functin 
int main(){
    Node *head=NULL;
    head=insertBegin(head,40);
    head=insertBegin(head,30);
    head=insertBegin(head,20);
    head=insertBegin(head,10);
    printList(head);

    cout<<"\nSorted Insert in a Singly Linked List: \n";
    head=insertAtCorrect(head,4);
    head=insertAtCorrect(head,25);
    head=insertAtCorrect(head,39);
    head=insertAtCorrect(head,50);
    printList(head);
    return 0;
}
/**
 * Problem Statement:
 * Implement a Circular Doubly Linked List that supports:
 * - Insertion at the head.
 * - Insertion at the end.
 * - Traversal and printing of the list.
 *
 * Approach:
 * - Use a `Node` class with `data`, `next`, and `prev` references.
 * - For insertion at head:
 *   - Handle the empty list case.
 *   - Insert before the current head and adjust circular links.
 * - For insertion at end:
 *   - Use the `prev` reference of the head to reach the tail.
 *   - Link the new node between the tail and the head.
 * - For traversal, use a `do-while` loop to navigate until we return to the head.
 *
 * Time Complexity:
 * - Insertion at head: O(1)
 * - Insertion at end: O(1)
 * - Traversal: O(n)
 *
 * Space Complexity:
 * - Auxiliary space: O(1)
 */
public class SortedInsertSinglyLinkedList {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Sorted Insert in a Singly Linked List
    static Node insertAtCorrect(Node head, int x) {
        Node temp = new Node(x);

        if (head == null || head.data > x) {
            temp.next = head;
            return temp;
        }

        Node curr = head;
        while (curr.next != null && curr.next.data < x) {
            curr = curr.next;
        }
        temp.next = curr.next;
        curr.next = temp;
        return head;
    }

    // Insert from Beginning in linked list
    static Node insertBegin(Node head, int x) {
        Node temp = new Node(x);
        temp.next = head;
        return temp;
    }

    // Display the elements of linked list
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertBegin(head, 40);
        head = insertBegin(head, 30);
        head = insertBegin(head, 20);
        head = insertBegin(head, 10);
        printList(head);

        System.out.println("\nSorted Insert in a Singly Linked List: ");
        head = insertAtCorrect(head, 4);
        head = insertAtCorrect(head, 25);
        head = insertAtCorrect(head, 39);
        head = insertAtCorrect(head, 50);
        printList(head);
    }
}