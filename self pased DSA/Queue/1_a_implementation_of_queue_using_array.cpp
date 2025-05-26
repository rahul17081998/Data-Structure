// time complexity of deque() = O(n), rest all operations take O(1) constant time.
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    // define Queue structure
    int size,cap;
    int *arr;
    Queue(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];   //Create an empty array of "cap" size.
    }
    
    bool isFull()
    {
        return (size==cap);
    }
    bool isEmpty()
    {
        return (size==0);
    }
    void enque(int x)
    {
        if(isFull())    return;
        arr[size] = x;
        size++;
    }
    void deque()
    {
        if(isEmpty())   return;
        for(int i=0; i < size-1; i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
    }
    int getFront()
    {
        if(isEmpty())
            return -1;
        else
            return arr[0];
    }
    int getRear()
    {
        if(isEmpty())
            return -1;
        else
            return arr[size-1];
    }
};

int main(){
    Queue q(5);

    q.enque(5);
    q.enque(2);
    q.enque(3);
    q.enque(31);
    cout<<"\nFront element: "<<q.getFront()<<endl;
    q.deque();  // delete from Front
    cout<<"Front element after deletion: "<<q.getFront()<<endl;
    cout<<"Rear element: "<<q.getRear()<<endl;
    cout<<"Queue is empty? Yes(1) or No(0): "<<q.isEmpty()<<endl;
    cout<<"Size of queue if full? Yes(1) or No(0): "<<q.isFull()<<endl;
}