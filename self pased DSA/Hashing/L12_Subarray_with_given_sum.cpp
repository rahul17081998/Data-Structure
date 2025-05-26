#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
// Naive method, O(n^2) time
bool isSumZero(int arr[],int n,int x)
{
    
    for (int i = 0; i < n; i++)
    {
        int sum1=0;
        if(arr[i]==0) {return true;}
        for (int j = i; j < n; j++)
        {
            sum1=sum1+arr[j];
            if(sum1==x)
                return true;
        }
        
    }
    return false;
    
}
// Effective approch
// using prefix sum and hashing  
bool isZeroSubarraySum(int arr[],int n,int sum)
{
    unordered_set<int> h;
    int pre_sum=0;
    for (int i = 0; i < n; i++)
    {
        pre_sum +=arr[i];

        if(pre_sum==sum)    // corner case
            return true;
        if(h.find(pre_sum-sum)!=h.end())
            return true;
        else
            h.insert(pre_sum);
    }
    return false;
}
int main(){
    int arr[]={1,4,13,-3,-10,5};
    int sum=14;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSumZero(arr,n,sum)<<endl;
    cout<<isZeroSubarraySum(arr,n,sum)<<endl;
    return 0;
}