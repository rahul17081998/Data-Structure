#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Naive approch
void prGreEle(int arr[], int n)
{
    cout<<-1<<" ";
    for(int i=1; i<n; i++)
    {
        int j;
        for (j = i-1; j>=0; j--)
        {
            if(arr[j]>=arr[i])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==-1)
            cout<<-1<<" ";
        
    }
}
// Efficient solution
void Eff_prevGreEle(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout<<-1<<" ";
    for (int i = 1; i < n; i++)
    {
        while(s.empty()==false && arr[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty()==false)
        {
            cout<<s.top()<<" ";
        }
        else
        {
            cout<<-1<<" ";
        }
        
        s.push(arr[i]);
    }
    
}
int main(){
    int arr[]={15,10,18,12,4,6,2,8,55};
    // int arr[]={8,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    prGreEle(arr, n);
    cout<<endl;
    Eff_prevGreEle(arr, n);
    return 0;
}