/*  Middle of a linklist
example
I/P:    10->20->30->40->34
O/P:    30

example
I/P:    20->14->68->5->24->18
O/P:    5   (secound mid)

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
// Efficient solution
void MiddleEfficient(Node *head)
{
    if(head==NULL) return;
    Node *slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle element is(Efficient method): "<<slow->data<<endl;
}
// Middle of a linklist
void middle(Node *head)
{
    Node *curr=head;
    int size=1;
    if(head==NULL) return;
    // if(head->next==NULL) cout<<"middle element si "<<head->data<<endl;
    while(curr->next != NULL)
    {
        size++;
        curr=curr->next;
    }
    cout<<"\nSize: "<<size<<endl;
    Node *currd=head;
    if(size%2==0)
    {
        for (int i = 1; i < size/2+1; i++)
        {
            currd=currd->next;
        }
        cout<<"Middle element is "<<currd->data<<endl;
    }
    else
    {
        for (int i = 1; i < size/2+1; i++)
        {
            currd=currd->next;
        }
        cout<<"Middle element is "<<currd->data<<endl;
    }

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
    head=insertBegin(head,38);
    head=insertBegin(head,20);
    head=insertBegin(head,5);
    head=insertBegin(head,10);
    printList(head);
    middle(head);
    MiddleEfficient(head);
    return 0;
}