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