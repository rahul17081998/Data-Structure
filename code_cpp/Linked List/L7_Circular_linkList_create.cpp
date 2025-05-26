// Note: This is not a general way of creating circular linklist
#include<iostream>
using namespace std;
// structure of circular linklist
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

// Circulat linklist traversal
// Method 2
void displayList(Node *head)
{
    if(head==NULL) return;
    cout<<head->data<<" ";
    for(Node *p=head->next; p!=head; p=p->next)
    {
        cout<<p->data<<" ";
    }
    cout<<endl;
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
    
    Node *head=new Node(10);
    head->next=head;
    head->next=new Node(5);
    head->next->next=new Node(20);
    head->next->next->next=new Node(15);
    head->next->next->next->next=head;
    printList(head);    // print circular linklist(method 1)
    displayList(head);  // print circular linklist(method 2)
    return 0;
}