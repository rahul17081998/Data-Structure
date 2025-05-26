#include<iostream>
using namespace std;
//Naive approch: T(n)=O(n)
int firstocc(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}

// Recursive binary search approch: T(n)=O(logn)
int firstoc_rec(int arr[], int low, int high, int x)
{
    if(low>high)    return -1;
    int mid = (low+high)/2;

    if(x>arr[mid])
        return firstoc_rec(arr, mid+1, high, x);
    else if(x<arr[mid])
        return firstoc_rec(arr, low, mid-1, x);
    else
    {
        if(arr[mid-1] != arr[mid] or mid ==0)
            return mid;
        
        else
            return firstoc_rec(arr, low, mid-1, x);
    }
}
// Iterative binary method: T(n)=O(logn)
int firstoc_itr(int arr[], int low, int high, int x)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(x>arr[mid])
            low = mid+1;
        else if(x<arr[mid])
            high = mid-1;

        else
        {
            if(arr[mid-1]!=arr[mid] or mid==0)
                return mid;
            else
                high = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={5,10,10,20,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high= n-1;
    int x= 10;  // Element which we have to search
    // Index of element x if it is found
    cout<<firstocc(arr, n, x)<<endl;    //Naive approch
    cout<<firstoc_rec(arr, low, high, x)<<endl; //Recursive binary search approch
    cout<<firstoc_itr(arr, low, high, x)<<endl; // Iterative binary method
    return 0;
}