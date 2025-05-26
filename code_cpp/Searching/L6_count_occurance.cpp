#include<iostream>
using namespace std;
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
//count occurance in a sorted array: T(n)=(logn)
int countocc(int arr[], int low, int high, int x, int n)
{
    int first = firstoc_itr(arr, low, high, x);
    if(first == -1)
        return 0;
    else
        return (lastocc_itr(arr, low, high, x, n)-first+1);
}
int main(){
    int arr[]={5,10,10,10,20,20,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high= n-1;
    int x= 10;  // Element which we have to search
    cout<<countocc(arr, low, high, x, n)<<endl;
    return 0;
}