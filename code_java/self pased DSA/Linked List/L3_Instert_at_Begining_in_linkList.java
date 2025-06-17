/**
 * Problem Statement:
 * Implement a singly linked list in C++ where nodes are inserted at the beginning.
 * Each time a new value is inserted, it becomes the new head of the list.
 * After inserting several values, display the contents of the list.
 *
 * Approach:
 * - Define a Node structure to hold integer data and a pointer to the next node.
 * - Implement an `insertBegin` function that:
 *   1. Creates a new node with the given value.
 *   2. Sets its next pointer to the current head.
 *   3. Returns the new node as the new head.
 * - Implement a `printList` function that traverses the list from head and prints each node.
 * - In the main function, build the list by inserting values at the beginning.
 *
 * Time Complexity:
 * - Insertion at beginning: O(1)
 * - Print all elements: O(n), where n is the number of nodes in the list.
 *
 * Space Complexity:
 * - O(n) for storing n nodes in the list.
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
    head=insertBegin(head,30);
    head=insertBegin(head,20);
    head=insertBegin(head,10);
    printList(head);
    return 0;
}