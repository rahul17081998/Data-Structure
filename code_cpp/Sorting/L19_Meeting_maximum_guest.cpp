#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Not properly correct
int maxGuest(int arr[],int dep[],int n)
{
    
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if((arr[j]<=arr[i]<=dep[j]) or (arr[j]<=dep[i]<=dep[j]))
            count++;
            res = max(res,count);
        }
        
    }
    return res-1;
    
}*/

// Effective approch
int maxguest(int arr[],int dep[],int n)
{
    int i=0,j=0,res=0,curr=0;
    sort(arr,arr+n);
    sort(dep,dep+n);
    while(i<n and j<n)
    {
        if(arr[i]<=dep[j])
        {
            i++;
            curr++;
        }
        else 
        {
            curr--;
            j++;
        }
        res=max(res,curr);
    }
    return res;
}
int main()
{
    // int arr[] = {900,600,700};
    // int dep[] = {1000,800,730};
    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxguest(arr,dep,n);
    return 0;
}
