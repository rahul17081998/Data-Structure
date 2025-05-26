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