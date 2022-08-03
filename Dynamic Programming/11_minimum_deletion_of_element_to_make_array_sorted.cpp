// Variation if LIS: longest common subsequence
// Approch: binary search
// Time = theta(N*logN), Space = theta(N)
#include<bits/stdc++.h>
using namespace std;

// ceiling of a value in an array
int ceilIdx(int tail[], int l, int r, int x)
{
    while(r>l)
    {
        int m = l+(r-l)/2;
        if(tail[m] >= x)
            r = m;
        else
            l = m+1;
    }
    return r;
}
// lis function
int LIS(int arr[], int n)
{
    int tail[n];
    tail[0] = arr[0];
    int len = 1;

    for (int i = 1; i < n; i++)
    {
        // cheak if current element is greater than
        // last element of tail array

        // if yes, then put this at the end of tail array 
        if(arr[i] > tail[len-1]){
            tail[len] = arr[i];
            len++;
        }
        // if no, find celling of element in tail array
        // and replce at their index with current element
        else
        {
            int celing = ceilIdx(tail, 0, len-1, arr[i]); // return ceiling element index
            tail[celing] = arr[i];
        }
        
    }
    return len;
    
}
// minimum no of elements to delete the array sorted
int minDelete(int arr[], int n)
{
    int lis_length = LIS(arr, n);
    return n-lis_length;
}


int main(){
    int arr[] = {3, 4, 2, 8, 10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"minimum no of elements to delete the array sorted: "<<minDelete(arr, n)<<endl;
    return 0;
}