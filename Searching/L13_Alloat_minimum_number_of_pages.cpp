// Minimize the maximum pages allocate
// Only contiguous pages can be allocated from input array

#include<iostream>
using namespace std;

int sum(int arr[], int b, int e)
{
    int s=0;
    for (int i = b; i <= e; i++)
    {
        s +=arr[i];
    }
    return s;
}

int minPage(int arr[], int n, int k)
{
    if(k==1)
        return sum(arr, 0, n-1);
    if(n==1)
        return arr[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(minPage(arr, i, k-1),sum(arr,i,n-1)));
    }
    return res;

}

int main(){
    int arr[]={10,20,30,40};    // No of pages of each books given
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;    // Number of student will going to read book
    cout<<minPage(arr, n, k);
    return 0;
}