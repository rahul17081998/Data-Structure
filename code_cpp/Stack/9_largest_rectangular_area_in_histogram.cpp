#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Naive solution
int largeAre(int arr[], int n)
{
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int c1=1;
        // forward loop
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]>=arr[i])
            {
                c1++;
            }
            else
            {
                break;
            }
            
        }
        // Beckward loop
        for (int k = i-1; k >= 0; k--)
        {
            if(arr[k]>=arr[i])
            {
                c1++;
            }
            else
            {
                break;
            }
            
        }
        
        res=max(res,(c1*arr[i]));
        
    }
    return res;
    
}
int main(){
    int arr[]={6,2,5,4,1,5,6};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<largeAre(arr,n)<<endl;
    return 0;
}