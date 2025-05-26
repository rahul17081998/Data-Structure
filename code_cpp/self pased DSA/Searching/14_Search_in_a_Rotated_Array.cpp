// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// use binary serach
int search(int A[], int l, int h, int key){
//complete the function here

    while(l<=h)
    {
        int mid = l+(h-l)/2;
        
        // if target found
        if(A[mid] == key)
        {
            return mid;
        }
        // if left side is sorted
        else if(A[l] <= A[mid])
        {
            if(A[l]<=key && key<=A[mid])
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        // if right side is sorted
        else
        {
            // check if target inside the right half 
            if(A[mid]<=key && key<=A[h])
            {
                l = mid+1;
            }
            // if it is not in right half, it will be in left half
            else
            {
                h = mid-1;
            }
        }
        
    }
    return -1;
}


// { Driver Code Starts. 
int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; // array should be shorted for binary search
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    cout<<"Index of serched element "<<x<<" is :"<<search(arr, 0, n-1, x)<<endl;
    x =0;
    cout<<"Index of serched element "<<x<<" is :"<<search(arr, 0, n-1, x)<<endl;
    
return 0;
}  // } Driver Code Ends