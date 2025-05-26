#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void mindiff(int arr[], int n)
{
    int res=INT_MAX;
    if(n==1)
    {
        cout<<res<<endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int diff = abs(arr[i]-arr[j]);
                res= min(res,diff);
            }
            
        }
        cout<<res<<endl;
    }
    
}
int main(){
    int arr[]={1,8,12,5,18};
    int n= sizeof(arr)/sizeof(arr[0]);
    mindiff(arr, n);
    return 0;
}