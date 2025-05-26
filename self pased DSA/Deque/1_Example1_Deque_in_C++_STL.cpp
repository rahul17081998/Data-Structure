// C++ STL in Deque
// Example 1
#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;    // initialize the deque with some item, Note: If you do not initialize the deque its no problem it will crate empty deque 
    dq.push_front(5);
    dq.push_front(15);
    dq.push_front(51);
    dq.push_back(50);
    for(auto x:dq)
    {
        cout<<x<<" ";
    }
    cout<<dq.front()<<" "<<dq.back();
    return 0;
}