#include<iostream>
using namespace std;
// binary search
int bsearch(int arr[], int n, int x)
{
    int low=0, high=n-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            high=mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60}; // array should be shorted for binary search
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 23;
    cout<<bsearch(arr, n, x);
    return 0;
}
