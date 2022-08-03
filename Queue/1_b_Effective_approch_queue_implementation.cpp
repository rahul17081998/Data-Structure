#include<bits/stdc++.h>
using namespace std;
// All operations of queue have O(1) time complexity.
struct Queue{
    int *arr;
    int size,cap,front;
    Queue(int c){
        arr=new int[c];
        cap=c;
        size=0;
        front=0;
    }
    bool isFull()
    {
        return (cap==size);
    }
    bool isEmpty()
    {
        return (size==0);
    }
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return front;
        }
    }
    int getRear()
    {
        if(isEmpty())
            return -1;
        else
            return (front+size-1)%cap;
    }
    void enque(int x)
    {
        if(isFull())
            return;
        int rear=getRear();
        rear=(rear+1)%cap;
        arr[rear] = x;
        size++;
    }
    void deque()
    {
        if(isEmpty()) return;
        front = (front+1)%cap;
        size--;
    }
};
int main(){
    Queue q(5);  // initiallizing queue with capicity 5

    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.deque();
    cout<<q.getFront()<<endl;
    return 0;
}