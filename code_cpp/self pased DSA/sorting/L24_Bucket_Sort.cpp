#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BucketSort(int arr[],int n,int k)
{
    int max_value=arr[0];
    for (int i = 0; i < n; i++)
    {
        max_value=max(max_value,arr[i]);
    }
    max_value++;
    // creat k number of buckets[from 0 to k] 
    vector<int> bkt[k];
    for (int i = 0; i < n; i++)
    {
        int bi=(k*arr[i])/max_value;
        bkt[bi].push_back(arr[i]);
    }
    // Sort the elements in each bucket
    for (int i = 0; i < k; i++)
    {
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index=0;
    // Merge All sorted bucket
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bkt[i].size(); j++)
        {
            arr[index]=bkt[i][j];
            index++;
        }
        
    }
    
    
}
void printArray(int arr[],int n)
{
    // print sorted array
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={20,80,10,85,75,99,18};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    BucketSort(arr,n,k);
    printArray(arr,n); 
    return 0;
}