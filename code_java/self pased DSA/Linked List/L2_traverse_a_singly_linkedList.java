/**
 * Problem Statement:
 * You are given a singly linked list of integers. Implement a C++ program to:
 * 1. Traverse and print the linked list using three methods:
 *    - Iteratively with a while loop and a separate pointer.
 *    - Iteratively by directly modifying the head pointer (or reference).
 *    - Recursively.
 * 2. Demonstrate all three traversals on the same linked list.
 *
 * Approach:
 * - Define a Node structure with integer data and a pointer to the next node.
 * - Construct the linked list manually.
 * - Implement and call the three printing methods.
 *
 * Steps:
 * 1. Define a Node struct with constructor and next pointer.
 * 2. Create a linked list manually in the main method.
 * 3. Write three functions:
 *    - Iterative traversal using a temporary pointer.
 *    - Iterative traversal using head reference.
 *    - Recursive traversal.
 * 4. Call these functions to print the list.
 *
 * Time and Space Complexity:
 * - Time Complexity (All Methods): O(n), where n is the number of nodes in the list.
 * - Space Complexity:
 *   - Iterative methods: O(1)
 *   - Recursive method: O(n) due to call stack.
 *
 * Algorithm for printList:
 * 1. Set a temporary node to head.
 * 2. While the node is not null:
 *    a. Print the node's data.
 *    b. Move to the next node.
 *
 * Algorithm for printOtherWay:
 * 1. While head is not null:
 *    a. Print head's data.
 *    b. Move head to the next node.
 *
 * Algorithm for rPrint:
 * 1. Base Case: If head is null, return.
 * 2. Print head's data.
 * 3. Recurse on the next node.
 */
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
// first method to print linklist
void printList(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
}

// fsecound method to print linklist
void printOtherWay(Node *head)
{
    while (head!=NULL)
    {
        cout<<(head->data)<<" ";
        head=head->next;
    }
    
}

// Recursive display of linklist
void rPrint(Node *head)
{
    if(head==NULL)
        return;
    else
        cout<<head->data<<" ";
        rPrint(head->next);
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);  
    head->next->next=new Node(30);  
    head->next->next->next=new Node(40);
    printList(head); // first way to print linklist

    // secound method to print linklist
    cout<<endl;
    printOtherWay(head);
    cout<<endl;
    printOtherWay(head);
    cout<<endl;
    //recursuve method to display
    rPrint(head);

    return 0;
}