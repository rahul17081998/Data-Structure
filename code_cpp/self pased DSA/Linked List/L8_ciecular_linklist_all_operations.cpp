#include<iostream>
using namespace std;
// structure of circular linklist
struct Node{
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
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
// Insert at begining of circular linklist: Method 1
// Naive method O(n)
Node *insertBegin(Node *head,int x)
{
    // create a node value x
    Node *temp=new Node(x);
    // If no element is present in circular linklist
    if(head==NULL)
        temp->next=temp;
    else
    {
        // if at least one element present
        Node *curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        
    }
    return temp;
}
// Effective method 
// Insert at begining of circular linklist: Method 2
// insert new element at 2nd position 
// then swap 1st and 2nd element
// time =O(1)
Node *insertBegin2(Node *head, int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        // insert item at 2nd poistion(below 2 linke code)
        temp->next=head->next;
        head->next=temp;
        // swap the item
        int t=head->data;
        head->data=temp->data;
        temp->data=t;

        return head;    // returning old head(no change)
    }
}
// Insert at the end of Circular Linked List
// time 𝛳(n)
Node *insertEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        Node *curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        return head;
    }
}
// Effective method
// insert at end
// insert new element at 2nd position 
// then swap 1st and 2nd element
// take head pointer at 2nd position
// time =O(1)
Node *insertEnd2(Node *head, int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        // insert item at 2nd poistion(below 2 line code)
        temp->next=head->next;
        head->next=temp;
        // swap the item
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        head=head->next;    // keep head pointer at 2nd position
        return head;    // returning old head(no change)
    }
}
// Delete Head of Circular Linked List
// Naive mathod
// time = O(n)
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
        Node *curr=head;    // curr pointing head node
        Node *tail=head;
        while(tail->next!=head)
        {
            tail=tail->next;    
        }
        // Now tail pointer reach at last node
        head=head->next;    // keep head at 2nd position
        tail->next=head;    // connecting tail to head
        curr->next=NULL;    // disconnecting curr node(previously head)
        delete curr;
        return head;


        // other method
        // we can solve only using one extra pointer
        /*
        Node *tail=head;
        while(tail->next!=head)
        {
            tail=tail->next;
        }
        tail->next=head->next;
        delete head;
        return (tail->next); */
    }
}
// Delete Head of Circular Linked List
// Effective method
// time = O(1)
Node *deleteHead2(Node *head)
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
        curr=curr->next;
        //swap data
        int t=head->data;
        head->data=curr->data;
        curr->data=t;
        // delete curr node
        head->next=curr->next; // link head(new head) with next of curr node 
        curr->next=NULL;    // disconnect curr node
        delete curr;
        return head;
    }    
}
// Delete Kth of a Circular Linked List
Node *delKthElement(Node *head, int k)
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
        Node *target=head;
        int count=1;
        while(count<k-1)
        {
            curr=curr->next;
            target=target->next;
            count++;
        }
        target=target->next;

        curr->next=target->next;
        target->next=NULL;
        delete target;
        return head;
    }
}
// main function
int main(){
    Node *head=NULL;
    head=insertBegin(head,15);
    head=insertBegin(head,5);
    head=insertBegin(head,20);
    head=insertBegin(head,18);
    cout<<"insert at begining(Naive method):"<<endl;
    printList(head);

    head=insertBegin2(head,11);
    cout<<"insert at begining(Effective method):"<<endl;
    printList(head);

    cout<<"insert 100 at End(Naive method):"<<endl;
    head=insertEnd(head,100);
    printList(head);

    cout<<"insert 90 at End(Effective method):"<<endl;
    head=insertEnd2(head,90);
    printList(head);

    cout<<"After deleting head(Naive method):"<<endl;
    head=deleteHead(head);
    printList(head);

    cout<<"After deleting head(Effective method):"<<endl;
    head=deleteHead2(head);
    printList(head);

    cout<<"After deleting 3rd element(15):"<<endl;
    head=delKthElement(head,3);
    printList(head);
    return 0;
}