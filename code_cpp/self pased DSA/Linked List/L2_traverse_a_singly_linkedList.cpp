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