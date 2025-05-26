#include<iostream>
#include<stdlib.h>
using namespace std;
// use structure
struct myStack
{
    int *arr;
    int cap;
    int top;
    myStack(int c)
    {
        cap=c;
        top=-1;
        arr= new int[cap];
    }
    void push(int x)
    {
        if (top==cap-1)
        {
            cout<<"Error! size overflow\n";
            exit(1);
        }
        top++;
        arr[top]=x;
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Error! underflow\n";
            exit(1);
        }
        int res=arr[top];
        top--;
        return res;
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"Error! underflow\n";
            exit(1);
        }
        return arr[top];
    }
    int size()
    {
        return (top+1);
    }
    bool isEmpty()
    {
        return (top==-1);
    }
};

int main(){
    myStack s(5);
    //Underflow
    // cout<<s.pop()<<endl;
    // cout<<s.peek()<<endl;
    s.push(4);
    s.push(21);
    s.push(30);
    s.push(10);
    s.push(10);
    //overflow
    // s.push(10);
    // s.push(10);
    // s.push(10);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}