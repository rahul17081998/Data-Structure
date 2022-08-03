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
    // Heapify operation
    void MinHeapify(int i)
    {
        int lt,rt,smallest;
        lt=left(i);
        rt=right(i);
        smallest=i;
        if(lt<size && arr[i]>arr[lt])
            smallest=lt;
        if(rt<size && arr[i]>arr[rt])
            smallest=rt;
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            MinHeapify(smallest);
        }
    }
    // Extract(delete) minimum element from Min heap and return new minimum element
    int extractMin()
    {
        if(size==0) return INT_MAX;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        else
        {
            swap(arr[0],arr[size-1]);
            size--;
            MinHeapify(0);
            return arr[size];
        }
        
    }


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
    cout<<h.extractMin()<<endl;
    h.printHeap();
    return 0;
}