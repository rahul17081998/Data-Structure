// Time complexity=O(1)
// Aux. Space= O(n)
#include<bits/stdc++.h>
using namespace std;
// global variable
stack<int> ms;  // Creat a main stack
stack<int> as;  // Creat a auxilary stack

void push(int x)
{
    if(ms.empty()==true)    // Base case :if stack is empty 
    {
        ms.push(x);
        as.push(x);
    }
    else
    {
        ms.push(x);
        if(as.top() >= ms.top())    
            as.push(x);
    }
}

void pop()
{
    if(ms.top()==as.top())
    {
        as.pop();
    }
    ms.pop();
}
void getMin()
{
    cout<<as.top()<<endl;
}
int main(){
    
    push(10);
    push(24);
    push(14);
    push(5);
    push(20);
    getMin();
    pop();
    pop();
    getMin();


    return 0;
}