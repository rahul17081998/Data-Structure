#include<bits/stdc++.h>
using namespace std;
int longConSeqCount(int arr[],int n)
{
    int res=1;
    int curr=1;
    sort(arr,arr+n);
    for (int i = 1; i < n; i++)
    {
        if(arr[i]==arr[i-1]+1)
        { 
            curr++;
            
        }
        else if(arr[i]!=arr[i-1])
        {    
            res=max(res,curr);
            curr=1;
        }
    }
    return res;
}
int main(){
    int arr[]={1,9,3,4,2,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<longConSeqCount(arr,n)<<endl;
    return 0;
}