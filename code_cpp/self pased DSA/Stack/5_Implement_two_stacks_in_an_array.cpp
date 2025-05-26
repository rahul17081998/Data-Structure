#include<iostream>
using namespace std;
struct twoStack
{
    int *arr,cap,top1,top2;
    twoStack(int n)
    {
        cap=n;
        top1=-1;
        top2=cap;
        arr=new int[n];
    }
    void push1(int x)
    {
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=x;
        }
        else 
        {
            cout<<"Stack overflow\n";
            exit(1);
        }
    }
    void push2(int x)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=x;
        }
        else 
        {
            cout<<"Stack overflow\n";
            exit(1);
        }
    }
    int pop1()
    {
        if(top1>=0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout<<"Stack underflow\n";
            exit(1);
        }
        
    }
    int pop2()
    {
        if(top2<cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout<<"Stack underflow\n";
            exit(1);
        }
        
    }
};

int main(){
    twoStack s1(5);
    s1.push1(10);
    s1.push1(20);
    s1.push2(50);
    s1.push2(5);
    s1.push2(21);
    cout<<"pop1: "<<s1.pop1()<<endl;
    cout<<"pop2: "<<s1.pop2()<<endl;
    return 0;
}