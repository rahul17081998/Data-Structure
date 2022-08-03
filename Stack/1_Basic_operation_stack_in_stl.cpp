#include<iostream>
#include<stack>

using namespace std;
int main()
{
    stack<int> s;
    s.push(20);
    s.push(9);
    s.push(12);
    cout<<"\nTop element "<<s.top();
    s.pop();
    cout<<"\nTop element "<<s.top()<<endl;
    if(s.empty()==1)
        cout<<"True\n";
    else
        cout<<"False\n";
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
    s.push(32);
    s.push(13);
    s.push(44);
    s.push(31);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}