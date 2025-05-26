// This logic is only valid for positive elements 
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int minm;
void push(int x)
{
    if(s.empty()==true)
    {
        s.push(x);
        minm = x;
    }
    else if (x>minm)
    {
        s.push(x);
    }
    else if(x<=minm)
    {
        s.push(x-minm);
        minm=x; 
    }
}

void pop()
{
    if(s.top()>=0)
    {
        s.pop();
    }
    else
    {
        minm=minm-s.top();
        s.pop();
    }
    
}
void getmin()
{
    cout<<minm<<endl;
}
void peek()
{
    cout<<s.top()<<endl;
}
int main(){
    push(12);
    push(6);

    push(10);
    push(3);
    push(42);
    getmin();   // output 3
    pop();
    pop();
    getmin();   // output 6
    peek();
    return 0;
}