#include<iostream>
using namespace std;
// Naive approch: T(n)=O(n)
int lastocc(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==x)
        {
            if(arr[i] != arr[i+1] or i==n-1)
                return i;
        }
    }
    return -1;
}
// Recursive binary search approch: T(n)=O(logn)
int lastocc_rec(int arr[], int low, int high, int x, int n)
{
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(x>arr[mid])
        return lastocc_rec(arr, mid+1, high, x, n);
    else if(x<arr[mid])
        return lastocc_rec(arr, low, mid-1, x, n);
    else
    {
        if(arr[mid]!=arr[mid+1] or mid==n-1)
            return mid;
        else
            return lastocc_rec(arr, mid+1, high, x, n);
    }
}
// Iterative binary method: T(n)=O(logn)
int lastocc_itr(int arr[], int low, int high, int x, int n)
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
            if(arr[mid]!=arr[mid+1] or mid==n-1)
                return mid;
            else
                low = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={5,10,10,10,20,20,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high= n-1;
    int x= 10;  // Element which we have to search
    cout<<lastocc(arr, n, x)<<endl;
    cout<<lastocc_rec(arr, low, high, x, n)<<endl; //Recursive binary search approch
    cout<<lastocc_itr(arr, low, high, x, n)<<endl; // Iterative binary method
    return 0;
    return 0;
}