#include<bits/stdc++.h>
using namespace std;
int EqualOneZero(int arr[],int n)
{
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int ones=0;
        int zeros=0;
        for (int j = i; j < n; j++)
        {
            if(arr[j]==0)
                zeros++;
            if(arr[j]==1)
                ones++;
            if(ones==zeros)
                res=max(res,ones*2);
        }
        
    }
    return res;
}
// method 2
// First replace 0 with -1 in given array
// use subarray sum =0 aproch,

int main(){
    int arr[]={0,0,1,0,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<EqualOneZero(arr,n);
    return 0;
}