/**
 * Problem Statement:
 * Implement a doubly linked list with three nodes. Each node should store an integer
 * and have pointers to the previous and next nodes. Connect the nodes appropriately
 * and print the list in forward direction.
 *
 * Approach:
 * - Define a Node structure with data, prev, and next pointers.
 * - Create three nodes and manually connect them to form a doubly linked list.
 * - Use a function `printList` to traverse and print the list from head to tail.
 *
 * Time Complexity:
 * - Creating and connecting nodes: O(1)
 * - Printing the list: O(n), where n is the number of nodes.
 *
 * Space Complexity:
 * - O(n) for storing n nodes in memory.
 */
/* Implementing Doubly linked list
  Having 3 nodes */
#include<iostream>
using namespace std;
struct Node
{
    int data;
    // create pointer
    Node *prev;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
// Create print function to display linklist
void printList(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
// Main function
int main(){
    // These three lines creater 3 independent Nodes
    Node *head=new Node(10);
    Node *temp1=new Node(24);  
    Node *temp2=new Node(29);  
    // connecting nodes 
    head->next=temp1;   // connect 1st node to 2nd 
    temp1->prev=head;   // connect 2nd node to 1st
    temp1->next=temp2;  // connect 2nd node to 3rd
    temp2->prev=temp1;  // connect 3rd node to 2nd
    // print function
    printList(head);
    return 0;
}