/**
 * Problem Statement:
 * Implement a doubly linked list in C++ that supports the following operations:
 * - Insertion at the beginning.
 * - Insertion at the end.
 * - Deletion of the head node.
 * - Deletion of the last node.
 * - Reversing the list.
 * - Displaying the list.
 *
 * Approach:
 * - Define a Node structure with data, prev, and next pointers.
 * - Implement individual functions for each operation to maintain modularity.
 * - Demonstrate all functionalities in the main function.
 *
 * Time Complexities:
 * - insertBegin: O(1)
 * - insertEnd: O(n)
 * - deleteHead: O(1)
 * - delEnd: O(n)
 * - reverseDll: O(n)
 * - printList: O(n)
 *
 * Space Complexity:
 * - O(1) auxiliary space for all operations (excluding storage for nodes).
 */
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data=d;
        prev=next=NULL;
        
    }
};
// Insert at begining of Doubly Link List
Node *insertBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    return temp;
}
// Insert at begining of Doubly Link List
Node *insertEnd(Node *head,int data)
{
    Node *temp=new Node(data);  // creater a newnode name--> temp
    // corner case, when there is no element
    if(head==NULL)
        return temp;
    // when elements have atleast 1 or more
    Node *curr=head;    // create curr pointer, initially at head
    while(curr->next!=NULL)
    {   
        curr=curr->next;
    }
    // curr pointer pointing last element now
    // link temp node with curr node
    curr->next=temp; 
    temp->prev=curr;
    return head;
}
// display function
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
// Reverse the doubly linklist
// time and space: 1 traversal linklist and constant space
// concept: swap prev and next pointer
Node *reverseDll(Node *head)
{
    if(head==NULL or head->next==NULL) 
    {
        return head;
    }
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL)
    {
        // swap prev and next pointer(first 3 line code)
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        // Go to next element, next pointer changes to previous pointer
        curr=curr->prev;
    }
    return prev->prev;
}
// Delete head of Doubly linklist
// time 𝛳(1)
Node *deleteHead(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr=head;
        head=head->next;
        head->prev=NULL;
        delete curr;
        return head;
    }

}
// Delete Last of a Doubly Linked List
// Time = 𝛳(n)
Node *delEnd(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp=head;
        // Method 1
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        // Now temp pointer pointing previous of last element
        temp->next=NULL;
        delete (temp->next);
        return head;

        /*
        // Method 2
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        // temp pointing last element
        temp->prev->next=NULL;
        delete temp;
        return head; */
    }
}
int main(){
    Node *head=NULL;
    head=insertBegin(head,30);
    head=insertBegin(head,20);
    head=insertBegin(head,10);
    head=insertEnd(head,43);
    head=insertEnd(head,42);
    head=insertEnd(head,49);
    
    cout<<"Display doubly linklist\n";
    printList(head);
    
    cout<<"After deleting head doubly linklist\n";
    head=deleteHead(head);
    printList(head);
    
    cout<<"After deleting last node, doubly linklist\n";
    head=delEnd(head);
    printList(head);
    
    cout<<"Reversed doubly linklist\n";
    head=reverseDll(head);
    printList(head);

    return 0;
}