// Queue in C++ STL
#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(20);
    q.push(23);
    q.push(13);
    cout<<"\nSize: "<<q.size()<<endl;
    cout<<q.front()<<" "<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<" "<<q.back()<<endl<<endl;
    // traverse the Queue and print all items
    while(q.empty()!=true)
    {
        cout<<q.front()<<" "<<q.back()<<endl;
        q.pop();
    }
    return 0;
}