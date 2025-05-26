// Implementing queue data structure using link list.
// Queue follow FIFO technique.
// All operatons have O(1) time complexity.
#include<bits/stdc++.h>
using namespace std;
// create a node of linklist
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
// structure for queue
struct Queue{
    Node *front, *rear;
    int size;
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    // insert item into queue from Rear end
    void enque(int x){
        Node *temp = new Node(x);
        size++;
        if(front==NULL){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;  // rear pointer shift
    }
    // Delete item from Queue from front end
    void deque(){
        if(front==NULL) return;
        size--;
        Node *temp=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete(temp);
    }
    // size of Queue
    int getsize(){
        return size;
    }
    // get front item
    int getFront(){
        return front->data;
    }
    // get rear item
    int getRear(){
        return rear->data;
    }
};
int main(){
    Queue q;
    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);
    cout<<"size of queue: "<<q.getsize()<<endl;
    q.deque();
    cout<<"size after deque: "<<q.getsize()<<endl;
    cout<<"Front item: "<<q.getFront()<<endl;
    cout<<"Rear item: "<<q.getRear()<<endl;
    return 0;
}