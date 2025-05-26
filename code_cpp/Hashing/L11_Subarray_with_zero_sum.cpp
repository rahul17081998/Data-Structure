#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
// Naive method, O(n^2) time
bool isSumZero(int arr[],int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        if(arr[i]==0) {return true;}
        for (int j = i; j < n; j++)
        {
            sum=sum+arr[j];
            if(sum==0)
                return true;
        }
        
    }
    return false;
    
}
// Effective approch
// using prefix sum and hashing  
bool isZeroSubarraySum(int arr[],int n)
{
    unordered_set<int> h;
    int pre_sum=0;
    for (int i = 0; i < n; i++)
    {
        pre_sum +=arr[i];
        if(h.find(pre_sum)!=h.end())
            return true;
        else if(pre_sum==0)
            return true;
        else
            h.insert(pre_sum);
    }
    return false;
}
int main(){
    bool arr[]={1,4,13,-3,-10,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSumZero(arr,n)<<endl;
    cout<<isZeroSubarraySum(arr,n)<<endl;
    return 0;
}