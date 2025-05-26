
// Stock span problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Naive approch: tc=O(n^2)
void printspan(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        
        int count=1;
        for(int j=i-1; j>=0 && arr[i]>=arr[j]; j--)
        {
            count++;
        }
        cout<<count<<" ";
    }
}
//Effective solution tc=𝜃(n), aux space=O(n)
void printSpan_method2(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout<<1<<" ";
    for(int i=1; i<n; i++)
    {
        while(s.empty()==false && arr[s.top()]<=arr[i])
        {
            s.pop();
        }
        int span=s.empty()? i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}
int main(){
    int arr[]={13,15,12,14,16,8,6,4,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    printspan(arr, n);
    cout<<endl;
    printSpan_method2(arr, n);
    return 0;
}