#include<iostream>
using namespace std;
// Naive approch: T(n)=O(logn)
void pairi_sum(int arr[], int n, int x)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==x)
            {
                cout<<"The pair is: "<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
                // cout<<arr[i]<<", "<<arr[j];
            }
           
        }
    }

}
//Two pair approch: T(n) = O(n);
// only work for sorted array
bool two_pair_fun(int arr[], int n, int x)
{
    int left = 0;
    int right = n-1;
    for (int i = 0; i < n; i++)
    {   
        if(left==right)
            break;
        if(arr[left]+arr[right]==x)
            return true;
        
        else if(arr[left]+arr[right]>x)
            right = right-1;
        else if(arr[left]+arr[right]<x)
            left = left+1;
        
    }
    return -1;
}

// Sum of three pair 
// Effective approch
// T(n) = O(n^2)
int three_pair(int arr[], int n, int x)
{
    
    for (int j = 0; j < n; j++)
    {
        int left = 0;
        int right = n-1;
        // sum of two pair 
        for (int i = 0; i < n; i++)
        {   
            if(left==right)
                break;
            if(arr[j]+arr[left]+arr[right]==x)
                return true;
        
            else if(arr[j]+arr[left]+arr[right]>x)
                right = right-1;
            else if(arr[j]+arr[left]+arr[right]<x)
                left = left+1;
        
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,3,7,20,30}; //sorted array
    int n = sizeof(arr)/sizeof(arr[0]);
    int x= 31;
    // cout<<pair_sum(arr, n, x)<<endl;
    // pairi_sum(arr, n, x);
    // cout<<two_pair_fun(arr, n ,x)<<endl;
    cout<<three_pair(arr, n, x)<<endl;
    return 0;
}