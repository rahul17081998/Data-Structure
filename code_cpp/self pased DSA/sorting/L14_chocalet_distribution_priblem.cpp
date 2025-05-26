#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int chocalet(int arr[], int n, int m)
{
    sort(arr,arr+n);
    int res = INT_MAX;
    int l=0;
    int r=m-1;
    int diff=0;
    while (r<n)
    {
        diff = arr[r]-arr[l];
        res = min(res,diff);
        l++;
        r++;

    }
    return res;
    
}

int main(){
    int arr[]={3,4,1,9,56,7,9,12};
    int n= sizeof(arr)/sizeof(arr[0]);
    int m=5;
    // sort(arr,arr+n);
    cout<<chocalet(arr,n,m);
    return 0;
}