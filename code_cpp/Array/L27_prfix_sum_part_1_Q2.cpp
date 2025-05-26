// Given an array of integer find if it has an equilibrium point

// Prefix sum method
#include<iostream>
using namespace std;

void equilibrium_point(int arr[], int sum_arr[], int n)
{
    if (sum_arr[n-1]==sum_arr[0])
    {
        cout<<"Equilibrium point: "<<arr[0]<<endl;
    }
    else if (sum_arr[n-2]==0)
    {
        cout<<"Equilibrium point: "<<arr[n-1]<<endl;
    }
    else
    {
        for (int i = 1; i < n-1; i++)
        {
            if (sum_arr[n-1]-sum_arr[i-1]==sum_arr[i] )
            {
                 cout<<"Equilibrium point: "<<arr[i]<<endl;
            }
            
        }
        
    }
}
int main(){
    int arr[] = {2,-2,65,1,3,-4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int prefix_sum[n];
    prefix_sum[0]=arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1]+arr[i];
    }

    equilibrium_point(arr, prefix_sum, n);
    return 0;
}