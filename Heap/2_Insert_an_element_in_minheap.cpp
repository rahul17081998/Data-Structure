#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int *arr;
    int capacity;
    int size;

    public:
    MinHeap(int c)
    {
        arr=new int[c];
        capacity=c;
        size=0;
    }
    int left(int i) {return (2*i+1);}
    int right(int i) {return (2*i+2);}
    int parent(int i) {return (i-1)/2;}
    // insert an element in Min heap
    void insert(int x)
    {
        if(capacity==size)
            return;
        size++;
        arr[size-1]=x;
        for(int i=size-1; i!=0 && arr[parent(i)]>arr[i];)
        {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    // print array
    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
};
int main(){
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    h.insert(1);
    

    
    // print
    h.printHeap();
    return 0;
}