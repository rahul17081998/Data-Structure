// Given a fixed array and multiple query of following type on an array, how to efficiently perform the k queries.

// Method 1  T(n) = O(n)
/*
#include<iostream>
using namespace std;

// Method 1: Naive approch,  T(n) = O(n) 
void getsum(int l, int r)
{
    int arr[] = {2,8,3,9,6,5,4};
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum = sum+arr[i];
    }
    cout<<sum<<" ";
}

int main(){
    getsum(0,2);
    getsum(1,3);
    getsum(2,6);
    return 0;
}*/


// Prefix sum method
#include<iostream>
using namespace std;

void get_sum(int prefix_sum[], int l, int r)
{   int res;
    if(l !=0)
    {
        res = prefix_sum[r]-prefix_sum[l-1];
    }
    else
    {
        res = prefix_sum[r];
    }
    cout<<res<<" ";
}

int main(){
    int arr[] = {2,8,3,9,6,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int prefix_sum[n];
    prefix_sum[0]=arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1]+arr[i];
    }
    /*
    // prefix sum array
    cout<<"Prefix_sum array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<prefix_sum[i]<<" ";
    }*/
    
    get_sum( prefix_sum, 0, 2);
    get_sum( prefix_sum, 1, 3);
    get_sum( prefix_sum, 0, 2);
    
    return 0;
}