// we can built priority queue using already existing 
// array or vector
// minimum element first priority queue -->  Min Heap data structure
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={22,4,23,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int>pq(arr,arr+n);
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top element: "<<pq.top()<<endl;
    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
    /*
    o/p :   Size: 8
            Top element: 23
            23 22 15 10 5 5 4 2 
    */

}