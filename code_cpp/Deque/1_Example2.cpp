/*  
Example 2: some more property and functions in deque
Note:
compile the program by using:
    g++ -std=c++0x 1_Example2.cpp -o 1_Example2
run:
    ./1_Example2   

*/

#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq={3,4,5,2,6};
    auto it=dq.begin(); // begin return you the iterater pointer(it) to the first element i.e. 3
    it++;   // it pointing element 4
    dq.insert(it,20);   // insert element(20) before pointer(it) i.e. dq={2,20,4,5,2,6}
    dq.pop_front();     // delete from front
    dq.pop_back();      // delete from back(rear end)
    cout<<"Size of deque: "<<dq.size()<<endl;
    return 0;
}