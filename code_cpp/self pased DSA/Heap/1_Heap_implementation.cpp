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
};
int main(){
    MinHeap h(11);
    return 0;
}