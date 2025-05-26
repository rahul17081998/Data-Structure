#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    queue<int> q1,q2;
    int curr_size;
    Stack(){
        curr_size=0;
    }
    int top()
    {
        if(q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return curr_size;
    }
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }
    void push(int x)
    {
        curr_size++;
        // empty the queue q1 and temperally store into q2
        while(q1.empty()==false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // push new data into q1
        q1.push(x);
        // push rest of data from q2 to q1
        while(q2.empty()==false)
        {
            q1.push(q2.front());
            q2.pop();
        }

    }
};

int main(){
    Stack s; 
	s.push(10); 
	s.push(5); 
	s.push(15); 
	s.push(20);

	cout << "current size: " << s.size() << endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 

	cout << "current size: " <<  s.size() << endl; 
    return 0;
}