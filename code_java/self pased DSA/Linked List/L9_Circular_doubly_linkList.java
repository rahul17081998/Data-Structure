/**
 * Problem Statement:
 * Implement a Circular Doubly Linked List with support for:
 * - Insertion at the head.
 * - Insertion at the end.
 * - Displaying the list contents.
 *
 * Approach:
 * - Define a `Node` struct with `data`, `next`, and `prev` pointers.
 * - Handle the base case of an empty list by pointing `next` and `prev` to the node itself.
 * - For insertions, adjust pointers to maintain circular and doubly linked properties.
 * - Use a `do-while` loop in the display function to traverse from head until it loops back.
 *
 * Time Complexity:
 * - Insertion at head: O(1)
 * - Insertion at end: O(1)
 * - Display list: O(n), where n is the number of nodes
 *
 * Space Complexity:
 * - O(1) auxiliary space
 */
/*
#include<bits/stdc++.h>
using namespace std;
// structure of circular doubly link list

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
// Insert at head
Node *insertAtHead(Node *head, int x)
{
    Node *temp=new Node(x);
    
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    Node *curr=head->prev;  // curr pointing last elemet
    curr->next=temp;
    temp->next=head;
    head->prev=temp;
    temp->prev=curr;
    return temp;
    

    // other method
    // temp->prev=head->prev;
    // temp->next=head;
    // head->prev->next=temp;
    // head->prev=temp;
    // return temp;    
    
}
// Insert at end in doubly linklist
Node *insertAtEnd(Node *head, int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    Node *curr=head->prev;  // curr pointing last elemet
    curr->next=temp;
    temp->next=head;
    head->prev=temp;
    temp->prev=curr;
    return head;

}
// Circulat linklist traversal
// Method 1
void printList(Node *head)
{
    if(head==NULL) return;
    Node *curr=head;
    do
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    } while (curr!=head);
    cout<<endl;
}
int main(){
    // Node *head=new Node(10);
    // head->next=head;
    // head->prev=head;
	// Node *temp1=new Node(20);
	// Node *temp2=new Node(30);
	// head->next=temp1;
	// temp1->next=temp2;
	// temp2->next=head;
	// temp2->prev=temp1;
	// temp1->prev=head;
	// head->prev=temp2;
    Node *head=NULL;
	head=insertAtHead(head,5);
	head=insertAtHead(head,51);
	head=insertAtHead(head,100);
    cout<<"print elements after insert at head: \n";
	printList(head);

    head=insertAtEnd(head,91);
    head=insertAtEnd(head,22);
    cout<<"print elements after insert at end: \n";
	printList(head);

    return 0;
}
*/



// revise linklist concept
#include<bits/stdc++.h>
using namespace std;

// create doubly linklist structure
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
// Insert at head in doubly connected circular linklist
Node *insertAttHead(Node *head, int x)
{
    Node *temp=new Node(x);
    if (head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    Node *curr=head->next;
    curr->next=temp;
    temp->next=head;
    temp->prev=curr;
    head->prev=temp;
    return temp;

}
// insert at end
Node *insertAttEnd(Node *head, int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    Node *curr=head->prev;
    curr->next=temp;
    temp->next=head;
    temp->prev=curr;
    head->prev=temp;
    return head;

}
// display function
void PrintCircularList(Node *head)
{
    if(head==NULL) return;
    Node *curr=head;
    do
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    } while (curr!=head);
    cout<<endl;
    
}
int main()
{
    Node *head=NULL;
    head=insertAttHead(head,45);
    head=insertAttHead(head,4);
    head=insertAttHead(head,5);
    PrintCircularList(head);

    cout<<"\nAfter Inserted at end: ";
    head=insertAttEnd(head,11);
    head=insertAttEnd(head,12);
    PrintCircularList(head);
    return 0;
}