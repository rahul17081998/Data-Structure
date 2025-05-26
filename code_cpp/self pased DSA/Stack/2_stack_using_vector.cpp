#include<bits/stdc++.h>
using namespace std;
struct MyStack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        int res=v.back();
        v.pop_back();
        return res;
    }
    int size()
    {
        return v.size();
    }
    int peek()
    {
        return v.back();
    }
    bool isEmpty()
    {
        return v.empty();
    }
};  // end of structure
int main()
{
    MyStack s;
    s.push(10);
    s.push(13);
    s.push(14);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;

    
    return 0;
}