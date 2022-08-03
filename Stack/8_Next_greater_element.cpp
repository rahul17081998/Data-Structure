#include<bits/stdc++.h>
using namespace std;

// Naive solution: Tc= (n^2)
void nextGreEle(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i+1; j<n; j++)
        {
            if(arr[j]>=arr[i])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==n)
            cout<<-1<<" ";
    }
}

// Efficient solution: Tc=𝜃(n), Aux space=O(n)
void Eff_nextGreele(int arr[], int n)
{
    stack<int> s;
    int temp[n];
    temp[n-1]=-1;
    s.push(arr[n-1]);
    for (int i = n-2; i >= 0; i--)
    {
        while(s.empty()==false && arr[i]>=s.top())
        {
            s.pop();
        }
        int pq=s.empty()?-1:s.top();
        temp[i]=pq;
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    
    
}
int main()
{
    int arr[]={15,10,18,12,4,6,2,8};
    // int arr[]={8,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    nextGreEle(arr,n);
    cout<<endl;
    Eff_nextGreele(arr,n);
    return 0;
}