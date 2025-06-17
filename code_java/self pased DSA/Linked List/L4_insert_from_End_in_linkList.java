/**
 * Problem Statement:
 * Implement a singly linked list in C++ that supports:
 * - Insertion at the end.
 * - Deletion of the first node.
 * - Deletion of the last node.
 * - Insertion at a specified position.
 * - Searching for an element (iteratively and recursively).
 *
 * Approach:
 * - Use a Node struct with integer data and a pointer to the next node.
 * - Each operation is encapsulated in its own function.
 * - Build the list in main and call all functions for demonstration.
 *
 * Time Complexities:
 * - insertEnd: O(n)
 * - deleted (delete first): O(1)
 * - delTail (delete last): O(n)
 * - insertPoss: O(n)
 * - searchLL (iterative search): O(n)
 * - search (recursive search): O(n)
 *
 * Space Complexity:
 * - All operations: O(1) auxiliary space except recursive search which has O(n) call stack space.
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
// Insert Elements from End in Linked List
Node *insertEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    return head;
}
// Delete first node of singly linked list
// Time complexity O(1)
Node *deleted(Node *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        Node *temp=head->next;
        delete head;
        return temp;
    }
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
// Delete Last or tail of Singly Linked List
// Head is never going to change if your link list size greater than 1
Node *delTail(Node *head)
{
    // if List have No node
    if(head==NULL)
        return NULL;
    // if List have only one node
    if(head->next==NULL)
    {   delete head;
        return NULL;
    }
    // if list have morethan one node
    Node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=NULL;
    return head;
}
// Insert at given position in singly linked list
/* input: 10->40->30->40->70
        pos=2
        data=20
output:10->20->40->30->40->70 */
Node *insertPoss(Node *head, int pos, int data)
{
    // create a temprary node having value "data"
    Node *temp=new Node(data);
    // if inserting node at head position
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    // serching just previous position 
    for (int i=1; i<=pos-2 && curr!=NULL; i++)
    {
        curr=curr->next;
    }
    if(curr==NULL)
        return head;
    // insering node at there position
    temp->next=curr->next;   // linking temp node and left side nodes
    curr->next=temp; // linking temp node and right side nodes
    return head;
}
// Find position of an element in a linked list
// Serach in a link list(iterative and recursive)
/* input: 10->40->30->40->70
        x=40
output:4
if element not present o/p -1 */
// iterative solution
// Time complexity=O(n)
int searchLL(Node *head,int x)
{
    Node *curr=head;
    int res=1;
    while(curr!=NULL)
    {
        if(curr->data==x)
        {
            return res;
        }
        curr=curr->next;
        res++;
    }
    return -1;
}
// Find position of an element in a linked list
// recursive function: Method 2
int search(Node *head, int x)
{
    if(head==NULL) return -1;
    if(head->data==x)
    {
        return 1;
    }
    else
    {
        int res=search(head->next,x);
        if(res==-1) return -1;
        else    return (res+1);
    }
}


// Main functin 
int main(){
    Node *head=NULL;
    head=insertEnd(head,10);
    head=insertEnd(head,20);
    head=insertEnd(head,30);
    head=insertEnd(head,40);
    head=insertEnd(head,48);
    head=insertEnd(head,11);
    cout<<"All nodes of linked list: "<<endl;
    printList(head); // print all nodes of linked list
    cout<<"\nAfter deleting starting Node: "<<endl;
    head=deleted(head); // delete starting node
    printList(head);
    cout<<"\nAfter deleting last node: "<<endl;
    head=delTail(head);
    printList(head);
    cout<<"\nAfter insering node at given position and having data(pos=3,data=32)"<<endl;
    head=insertPoss(head,3,32);
    printList(head);
    cout<<"\nsearch elemet position(Iterative method): "<<searchLL(head,32)<<endl;
    cout<<"search elemet position(Recursive method): "<<search(head,32)<<endl;
    return 0;
}