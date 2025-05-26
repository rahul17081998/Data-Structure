// minimum element first priority queue -->  Min Heap data structure
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int> >pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
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
    o/p :   Size: 3
            Top element: 5
            5 10 15 */

}