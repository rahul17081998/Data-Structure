// priority queue use by default maxHeap data structure
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int>pq;
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
}