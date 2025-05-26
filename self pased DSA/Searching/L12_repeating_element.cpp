// Find the repeating element
// In array only one element will be repeating
#include<iostream>
using namespace std;
// Super Naive solution: O(n^2)
int maxele(int arr[], int n)
{
    
    for (int i = 0; i < n-1; i++)
    {
        // int count=1;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j])
            {
                // count++;
                return arr[i];
                break;
            }
                
        }
        
    }
    return -1;
    
}
// Naive solution: O(n*logn)
int method_2(int arr[], int n)
{
    sort(arr,arr+n);// sort an array
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==arr[i+1])
                return arr[i];
    }
    return -1;
}

int main(){
    int arr[]={1,3,2,4,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxele(arr, n)<<endl;
    cout<<method_2(arr, n)<<endl;

    return 0;
}
