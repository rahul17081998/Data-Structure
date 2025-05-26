#include<bits/stdc++.h>
using namespace std;
// Naive approch
void MaxOfSubarray(int arr[], int n, int k)
{
    
    for (int i = 0; i <= n-k; i++)
    {
        int maxi=INT_MIN;
        for (int j = i; j < i+k; j++)
        {
            maxi=max(maxi,arr[j]);
        }
        cout<<maxi<<" ";
    }
    
}
// Efficient approch: Tc=(n)
void printMax(int arr[],int n,int k)
{
    deque<int> dq;
    for(int i=0; i<k; i++)
    {
        while(dq.empty()==false && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
    
}
int main(){
    // int arr[]={20,5,3,8,6,15};
    // int k=4;
    int arr[] = {-10,-8,-2,12,15,7,6};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    MaxOfSubarray(arr,n,k);
    cout<<endl;
    printMax(arr,n,k);
    return 0;
}