#include<iostream>
using namespace std;
//create node
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
// create stack structure
struct myStack
{
    Node *head;
    int sz;
    myStack()
    {
        head=NULL;
        sz=0;
    }
    void push(int x)
    {
    Node *temp=new Node(x);
    temp->next=head;
    head=temp;
    sz++;
    }
    int pop()
    {
        if(head==NULL){cout<<"Error! empty stack\n"; exit(1);}
        Node *temp=head;
        int res=temp->data;
        head=head->next;
        delete(temp);
        sz--;
        return res;
    }
    int size()
    {
        return sz;
    }
    int peek()
    {
        if(head==NULL)
        {
            cout<<"Error! Empty stack\n";
            exit(1);
        }
        return head->data;
    }
    bool isEmpty()
    {
        return (head==NULL);
    }
};


int main(){
    myStack s;
    s.push(3);
    s.push(30);
    s.push(35);
    cout<<s.size()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.size()<<endl;
    return 0;
}