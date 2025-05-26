/*
Design a data structure which support 
following operations in O(1) time complexity.

    insertMin(x)
    insertMax(x)
    getMin()        // return min element
    getMax()        // return max element
    extractMin()    // delete min element
    extractMax()    // delete max element
*/

#include<iostream>
#include<deque>
using namespace std;
struct MyDs
{
    deque<int>dq;
    void insertMin(int x)
    {
        dq.push_front(x);
    }
    void insertMax(int x)
    {
        dq.push_back(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
    void extractMin(){
        dq.pop_front();
    }
    void extractMax(){
        dq.pop_front();
    }
};
int main(){
    MyDs md;
    md.insertMin(5);
    md.insertMax(10);
    md.insertMin(3);
    md.insertMax(15);
    md.insertMin(2);
    cout<<"Minimum: "<<md.getMin()<<endl;
    cout<<"Maximum: "<<md.getMax()<<endl;
    md.insertMin(1);
    cout<<"Minimum: "<<md.getMin()<<endl;
    md.insertMax(20);
    cout<<"Maximum: "<<md.getMax()<<endl;
    return 0;
}