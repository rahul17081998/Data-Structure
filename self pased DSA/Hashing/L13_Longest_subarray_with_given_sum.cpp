#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Naive method, O(n^2) time
int isSumZero(int arr[],int n,int x)
{
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int sum1=0;
        for (int j = i; j < n; j++)
        {
            sum1=sum1+arr[j];
            if(sum1==x)
                res=max(res,j-i+1);
        }
        
    }
    return res;
    
}
// Effective approch
// using prefix sum and hashing  
// Not correct code
/*
bool isMaxLong(int arr[],int n,int sum)
{
    unordered_map<int,int> m;
    int pre_sum=0,res=0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if(pre_sum==sum)
            res=i+1;
        if(m.find(pre_sum)==m.end())
            m[pre_sum]=i;
        if(m.find(pre_sum-sum)!=m.end())
            res=max(res,i-m[pre_sum-sum]);
    }
    return res;
}*/
int main(){
    int arr[]={3,1,1,8,2,3,6};
    int sum=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSumZero(arr,n,sum)<<endl;
    // cout<<isMaxLong(arr,n,sum)<<endl;

    return 0;
}